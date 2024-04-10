#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
#define next Next
using namespace std;
typedef long long LL;
const int MXN = 300004;
struct BccVertex {
    int n,nScc,step,dfn[MXN],low[MXN];
    vector<int> E[MXN],sccv[MXN];
    int top,stk[MXN];
    void init(int _n) {
        n = _n;
        nScc = step = 0;
        for (int i=0; i<n; i++) E[i].clear();
    }
    void add_edge(int u, int v) {
        E[u].pb(v);
        E[v].pb(u);
    }
    void DFS(int u, int f) {
        dfn[u] = low[u] = step++;
        stk[top++] = u;
        for (auto v:E[u]) {
            if (v == f) continue;
            if (dfn[v] == -1) {
                DFS(v,u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u]) {
                    int z;
                    sccv[nScc].clear();
                    do {
                        z = stk[--top];
                        sccv[nScc].pb(z);
                    } while (z != v);
                    sccv[nScc].pb(u);
                    nScc++;
                }
                } else {
                low[u] = min(low[u],dfn[v]);
            }
        }
    }
    vector<vector<int>> solve() {
        vector<vector<int>> res;
        for (int i=0; i<n; i++) {
            dfn[i] = low[i] = -1;
        }
        for (int i=0; i<n; i++) {
            if (dfn[i] == -1) {
                top = 0;
                DFS(i,i);
            }
        }
        for(int i=0;i<nScc;i++){
        	sort(sccv[i].begin(),sccv[i].end());
			 res.pb(sccv[i]);
		}
        return res;
    }
}graph;
struct node{
	node *l,*r;
	int a,b;
	int add;
	LL sum;
	node(int _a,int _b):a(_a),b(_b){
		l=r=NULL;
		add=0;
		sum=0;
	}
}*root;
vector<int> v[300005];
int a[300005];
struct ask{
	int l,r,i;
	LL ans;
	ask(int a,int b,int c){
		l=a,r=b,i=c;
	}
};
bool cmp(const ask &a,const ask &b){
	return a.r<b.r;
}
bool cmp2(const ask &a,const ask &b){
	return a.i<b.i;
} 
LL Sum(node *n){
	return n->sum+n->add*((LL)n->b-n->a+1);
}
void push(node *n){
	n->l->add+=n->add;
	n->r->add+=n->add;
	n->add=0;
}
void pull(node *n){
	n->sum=Sum(n->l)+Sum(n->r);	
}
void add(node *n,int l,int r){
	if(l<=n->a&&n->b<=r){
		n->add++;
		return ;
	}
	if(n->b<l||n->a>r){
		return ;
	}
	push(n);
	add(n->l,l,r);
	add(n->r,l,r);
	pull(n);
}
LL  qu(node *n,int l,int r){
	if(l<=n->a&&n->b<=r){
		return Sum(n);
	}
	if(n->b<l||n->a>r){
		return 0;
	}
	push(n);
	LL res=qu(n->l,l,r)+qu(n->r,l,r);
	pull(n);
	return res;
}
int getMax(vector<int> &a){
	int res=0;
	for(auto &it:a){
		res=max(res,it); 
	}
	return res;
}
void build(node *n,int l,int r){
	if(l==r)return;
	int mid=(l+r)/2;
	n->l=new node(l,mid);
	build(n->l,l,mid);
	n->r=new node(mid+1,r);
	build(n->r,mid+1,r);
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	root = new node(1,n);
	build(root,1,n);
	graph.init(n+1);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		graph.add_edge(x,y);
	}
	auto res=graph.solve();
	for(auto it:res){
		if(it.size()>2){
		//	printf("%d %d\n",it.back(),it.front());
			v[it.back()].pb(it.front());
		}
	}
	vector<ask> query;
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		query.pb(ask(l,r,i));
	}
	sort(query.begin(),query.end(),cmp);
	int now=0,k=1;
	for(auto &x:query){
		while(now<x.r){
			now++;
			k=max(k,getMax(v[now])+1);
		//	printf("%d %d\n",k,now);
			add(root,k,now);
		}
		x.ans=qu(root,x.l,x.r);
	}
	sort(query.begin(),query.end(),cmp2);
	for(auto &x:query){
		printf("%I64d\n",x.ans);
	}
}