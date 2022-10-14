/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=5e5+233;
int n,m;
set<int> g[MAXN];
vector<int> tree[MAXN];
vector<int> dsu[MAXN];
int fa[MAXN];
int root(int now){
	return fa[now]=(fa[now]==now? now:root(fa[now]));
}
set<int> roots;
void merge(int u,int v){
	roots.erase(u);
	fa[u]=v;
	for(auto it:dsu[u]){
		dsu[v].PB(it);
	}
	dsu[u].clear();
}
int z[MAXN],t[MAXN];
int cnt=0;
bool go(int now,int pre){
	if(pre==-1&&tree[now].empty()){
		z[now]=t[now]=++cnt;
		return 0;
	}
	vector<int> sing;
	int last=-1;
	for(auto it:tree[now]) if(it!=pre){
		last=it;
//		cout<<now<<"->"<<it<<endl;
		if(!go(it,now)){
			sing.PB(it);
		}
	}
	if(sing.empty()){
		if(pre==-1){
			t[now]=z[now]=++cnt;
			swap(t[now],t[last]);
		}
		return 0;
	}
	else{
		t[now]=z[now]=++cnt;
		for(auto it:sing){
			t[it]=z[it]=++cnt;
			swap(t[it],t[now]);
		}
		return 1;
	}
}
void solve(){
	cnt=0;
	roots.clear();
	scanf("%d%d",&n,&m);
	rb(i,1,n) fa[i]=i,dsu[i].clear(),dsu[i].PB(i),tree[i].clear(),g[i].clear(),roots.insert(i); 
	rb(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].insert(v);
		g[v].insert(u); 
	}
	rb(i,1,n){
		int rt=root(i);
		vector<int> tmp;
		for(auto ite=roots.begin();ite!=roots.end();++ite){
			if(rt!=*ite){
				for(auto it:dsu[*ite]){
					if(g[i].find(it)!=g[i].end());
					else{
						tree[i].PB(it);
						tree[it].PB(i);
						tmp.PB(*ite);
						break;				
					}
				}
			}
		}
		for(auto it:tmp){
			if(dsu[it].size()>dsu[rt].size()){
				swap(it,rt);
			}
			merge(it,rt); 
		}
	}
	rb(i,1,n) if(root(i)==i){
		go(i,-1);	
	}
	rb(i,1,n){
		printf("%d ",z[i]);
	}
	puts("");
	rb(i,1,n){
		printf("%d ",t[i]);
	}
	puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();	
	return 0;
}