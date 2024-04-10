#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	char c[200005];
	scanf("%s",c+1);
	char c1[200005];
	scanf("%s",c1+1);
	int l=0,r=m+1;
	int st=0;
	for(int i=1;i<=n;i++){
		if(c[i]=='*'){
			st=1;
		}
	}
	if(!st&&n!=m){
		printf("NO\n");
		return 0;
	}
	for(int i=1;c[i]!='*'&&c[i]!=0;i++){
		if(c[i]!=c1[i]){
			printf("NO\n");
			return 0;
		}
		l=i;

	}
	for(int i=0;c[n-i]!='*'&&c[n-i]!=0;i++){
		if(c[n-i]!=c1[m-i]){
			printf("NO\n");
			return 0;
		}
		r=m-i;
	}
	if(l>=r&&st){
		printf("NO\n");
	}
	else
	printf("YES\n");
}
/*
#define N 500005
int a[N];
struct node{
	node *l,*r;
	int Max;
	int a,b;	
	node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),Max(0){

	}
}*root;
int getMax(node *n){
	return n?n->Max:0;
}
void pull(node *n){
	n->Max=max(getMax(n->l),getMax(n->r));
}
void build(node *n){
	if(n->a==n->b){
		n->Max=a[n->a];
		return ;
	}
	int mid=(n->a+n->b)/2;
	n->l=new node(n->a,mid);
	n->r=new node(mid+1,n->b);
	build(n->l);
	build(n->r);
	pull(n);
}
int query(node *n,int l,int r){
	if(l<=n->a&&r>=n->b)
	return n->Max;
	if(l>n->b||r<n->a)
	return 0;
	return max(query(n->l,l,r),query(n->r,l,r));
}
void init(int n){
	root=new node(0,n-1);
	build(root);
	return ;
}//implement
int n,fa[N],belong[N],dep[N],sz[N],que[N];
int step,line[N],stPt[N],edPt[N];
vector<int> v[N], chain[N];
void DFS(int u){
    vector<int> &c = chain[belong[u]];
    for (int i=c.size()-1; i>=0; i--){
        int v = c[i];
        stPt[v] = step;
        line[step++] = v;
    }
    for (int i=0; i<(int)c.size(); i++){
        u = c[i];
        for (vector<int>::iterator it=v[u].begin();it!=v[u].end();it++){
            if (fa[u] == *it || (i && *it == c[i-1])) continue;
            DFS(*it);
        }
        edPt[u] = step-1;
    }
}
void build_chain(int st){
    int fr,bk;
    fr=bk=0; que[bk++] = 1; fa[st]=st; dep[st]=0;
    while (fr < bk){
        int u=que[fr++];
        for (vector<int>::iterator it=v[u].begin();it!=v[u].end();it++){
            if (*it == fa[u]) continue;
            que[bk++] = *it;
            dep[*it] = dep[u]+1;
            fa[*it] = u;
        }
    }
    for (int i=bk-1,u,pos; i>=0; i--){
        u = que[i]; sz[u] = 1; pos = -1;
        for (vector<int>::iterator it=v[u].begin();it!=v[u].end();it++){
            if (*it == fa[u]) continue;
            sz[u] += sz[*it];
            if (pos==-1 || sz[*it]>sz[pos]) pos=*it;
        }
        if (pos == -1) belong[u] = u;
        else belong[u] = belong[pos];
        chain[belong[u]].pb(u);
	//	printf("%d %d\n",u,belong[u]);
    }
    step = 0;
    DFS(st);
}
int getLCA(int u, int v){
    while (belong[u] != belong[v]){
		//printf("%d %d\n",u,v);
		//printf("%d %d\n",belong[u],belong[v]);
        int a = chain[belong[u]].back();
        int b = chain[belong[v]].back();
		//printf("%d %d\n",a,b);
        if (dep[a] > dep[b]) u = fa[a];
        else v = fa[b];
    }
    return sz[u] >= sz[v] ? u : v;
}
vector<pii> getPathSeg(int u, int v){
    vector<pii> ret1,ret2;
    while (belong[u] != belong[v]){
        int a = chain[belong[u]].back();
        int b = chain[belong[v]].back();
        if (dep[a] > dep[b]){
            ret1.pb(mp(stPt[a],stPt[u]));
            u = fa[a];
            } else {
            ret2.pb(mp(stPt[b],stPt[v]));
            v = fa[b];
        }
    }
    if (dep[u] > dep[v]) swap(u,v);
    ret1.pb(mp(stPt[u],stPt[v]));
    reverse(ret2.begin(), ret2.end());
    ret1.insert(ret1.end(),ret2.begin(),ret2.end());
    return ret1;
}
// Usage
void build(int n){
    build_chain(1); //change root
    init(n);
}
int get_answer(int u, int v){
    int ret = -2147483647;
    vector<pii> vec = getPathSeg(u,v);
	int x=getLCA(u,v);
    for (auto it:vec){
		if(it.x==stPt[x]){
			if(it.x!=it.y)
			ret=max(ret,query(root,it.x+1,it.y));
		}
		else
			ret=max(ret,query(root,it.x,it.y));
		printf("%d %d\n",it.x,it.y);
	}
	printf("%d\n",ret);
     // check answer with segment [it.F, it.S]
    return ret;
}
int f[500005];
int Find(int a){
	if(f[a]==a)return a;
	return f[a]=Find(f[a]);
}
vector<pii> myv[N];
int main(){
	int n,k,m;
	scanf("%d %d %d",&n,&k,&m);
	pii p[500005];
	for(int i=0;i<k;i++){
		int x,y,len;
		scanf("%d %d",&x,&y);
		p[i]=mp(x,y);
	}
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=0;i<m;i++){
		int x,y,len;
		scanf("%d %d %d",&x,&y,&len);
		int fx=Find(x);
		int fy=Find(y);
		if(fx!=fy){
			v[x].pb(y);
			v[y].pb(x);
			myv[x].pb(mp(y,len));
			myv[y].pb(mp(x,len));
			f[fx]=fy;
		}
	}
	build_chain(1);
	for(int i=1;i<=n;i++){
		for(auto it:myv[i]){
			if(dep[it.x]<dep[i]){
				printf("%d %d %d\n",i,stPt[i],it.y);
				a[stPt[i]]=it.y;
			}
		}
	}
	init(n);
	LL ans=0;
	for(int i=0;i<k;i++){
		int fx=Find(p[i].x);
		int fy=Find(p[i].y);
		if(fx!=fy){
			printf("-1\n");
			return 0;
		}
		int x=getLCA(p[i].x,p[i].y);
		ans+=get_answer(p[i].x,p[i].y);
	}
	printf("%lld\n",ans);
}
/*
int x,y;
bool cmp(const pii &a,const pii &b){
	int disa=min(a.x-x,a.y-y),disb=min(b.x-x,b.y-y);
	return disa>disb;
}
string ans;
void rec(int r1,int c1,int r2,int c2){
	if(r1==r2){
		for(int i=c1;i<c2;i++)
		ans+='R';
		return;
	}
	if(c1==c2){
		for(int i=r1;i<r2;i++)
		ans+='D';
		return ;
	}
	vector<pii> v;
	int y=c2;
	for(int i=r1;i<=r2;i++){
		v.pb(mp(i,y));
		y--;
		if(y<c1)
		break;
	}
	x=r1;
	y=r2;
	sort(v.begin(),v.end(),cmp);
	for(auto it:v){
		if(rand()%2==0){
			cout<<"? "<<r1<<" "<<c1<<" "<<it.x<<" "<<it.y<<endl;//%d %d %d %d\n",r1,c1,it.x,it.y);
			cout.flush();
			string s;
			cin>>s;
			if(s=="NO")
			continue;
			assert(s!="BAD");
			cout<<"? "<<it.x<<" "<<it.y<<" "<<r2<<" "<<c2<<endl;
			cout.flush();
			cin>>s;
			if(s=="NO")
			continue;
			assert(s!="BAD");
		}
		else{
			cout<<"? "<<it.x<<" "<<it.y<<" "<<r2<<" "<<c2<<endl;
			cout.flush();
			string s;
			cin>>s;
			if(s=="NO")
			continue;
			assert(s!="BAD");
			cout<<"? "<<r1<<" "<<c1<<" "<<it.x<<" "<<it.y<<endl;
			cout.flush();
			cin>>s;
			if(s=="NO")
			continue;
			assert(s!="BAD");
		}
		rec(r1,c1,it.x,it.y);
		rec(it.x,it.y,r2,c2);
		break;
	}
}
int main(){
	srand(time(NULL));
	int n;
	scanf("%d",&n);
	rec(1,1,n,n);
	cout<<"! "<<ans<<endl;
	cout.flush();
}
*/