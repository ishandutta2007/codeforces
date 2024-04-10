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
const int MAXN=3e5+233;
int fa[MAXN];
vector<int> ans;
vector<int> ans2;
LL a[MAXN];
LL olda[MAXN];
int root(int x){
	return fa[x]=(fa[x]==x? x:root(fa[x]));
}
int n,x;
void init(){
	rb(i,1,n) fa[i]=i;
}
vector<mp> og[MAXN];
vector<mp> g[MAXN];
vector<mp> gg[MAXN];
bool vis[MAXN];
void merge(int u,int v){
	if(g[u].size()>g[v].size()) swap(u,v);
	fa[u]=v;
	a[v]+=a[u]-x;
	for(auto it:g[u]){
		if(root(it.FIR)!=root(v)){
			g[v].PB(it);
		}
	}
	g[u].clear();
}
void gao(int x){
	while(!g[x].empty()&&root(g[x].back().FIR)==root(x)) g[x].POB();
	if(g[x].empty()) return ;
	ans.PB(g[x].back().SEC);
	merge(root(g[x].back().FIR),x);
}
void dfs(int now){
	vis[now]=1;
	for(auto it:gg[now]){
		if(!vis[it.FIR]){
			dfs(it.FIR);
			ans2.PB(it.SEC);
		}
	}
}
void do_(int u,int v){
	assert(root(u)!=root(v));
	a[root(v)]+=a[root(u)]-x;
	assert(a[root(v)]>=0);
	fa[root(u)]=root(v);
}
int u_[MAXN],v_[MAXN];
int main(){
	int m;
	scanf("%d%d%d",&n,&m,&x);
	rb(i,1,n) scanf("%lld",&a[i]),olda[i]=a[i];
	LL sum=0;
	rb(i,1,n) sum+=a[i];
	init();
	rb(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v);
		u_[i]=u;
		v_[i]=v;
		g[u].PB(II(v,i));
		g[v].PB(II(u,i));
		fa[root(u)]=root(v);
	}
	rb(i,1,n) og[i]=g[i];
	rb(i,1,n) if(root(i)!=root(1)){
		puts("NO");
		return 0;
	}
	if(sum-1ll*x*(n-1)<0){
		puts("NO");
		return 0;
	}
	puts("YES");
	init();
	rb(i,1,n){
		while(a[root(i)]>=x){
			gao(root(i));
			if(ans.size()==n-1){
				init();
				rb(i,1,n) a[i]=olda[i];
				for(auto it:ans){
					printf("%d\n",it),do_(u_[it],v_[it]); 
				}
				return 0;
			}
		}
	}
	rb(i,1,n){
		for(auto it:og[i]){
			if(root(it.FIR)!=root(i)){
				gg[root(i)].PB(II(root(it.FIR),it.SEC));
				gg[root(it.FIR)].PB(II(root(i),it.SEC));
			}
		}
	}
	rb(i,1,n) if(root(i)==i){
		dfs(i);
		break;
	}
	reverse(ALL(ans2));
	init();
	rb(i,1,n) a[i]=olda[i];
	for(auto it:ans) printf("%d\n",it),do_(u_[it],v_[it]);
	for(auto it:ans2) printf("%d\n",it),do_(u_[it],v_[it]);
	return 0;
}