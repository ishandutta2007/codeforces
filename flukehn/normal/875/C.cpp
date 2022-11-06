#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;//*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=200011;
namespace Ga{
	struct Edge{
		int v;Edge *nxt;
	} pl[N<<2],*cur=pl,*G[N];
	void add(int u,int v){cur->v=v,cur->nxt=G[u],G[u]=cur++;}
};
vector<int> v[N>>1];
int n,m;
int vis[N];
int sta[N],tc;
int dfn[N],low[N],scc,col[N];
void dfs(int x){
	static int dfs_cnt;
	vis[x]=1,sta[++tc]=x;
	dfn[x]=low[x]=++dfs_cnt;
	using namespace Ga;
	Es(x,i)if(!dfn[i->v]){
		dfs(i->v);
		low[x]=min(low[i->v],low[x]);
	}else if(vis[i->v]){
		low[x]=min(low[x],dfn[i->v]);
	}
	if(dfn[x]==low[x]){
		scc++;int v;
		do{
			v=sta[tc--];
			vis[v]=0;
			col[v]=scc;
		}while(v!=x);
	}
}
int main(){
#ifdef flukehn
	freopen("test.txt","r",stdin);
#endif
	n=rd(),m=rd();
	rep(i,1,n){
		int p=rd();
		bool flag=(i!=1);
		rep(j,0,p-1){
			int x=rd();
			v[i].pb(x);
			if(flag){
				if(v[i-1].size()<j+1)flag=0;
				else {
					if(v[i-1][j]==x)continue;
					if(v[i-1][j]>x){
						Ga::add(2*v[i-1][j]-1,2*v[i-1][j]);
						Ga::add(2*x,2*x-1);
					}else{
						Ga::add(2*x,2*v[i-1][j]);
						Ga::add(2*v[i-1][j]-1,2*x-1);
					}
					flag=0;
				}
			}
		}
		if(flag&&v[i-1].size()>p){
			return puts("No"),0;
		}
	}
	rep(i,1,2*m)if(!dfn[i])dfs(i);
	rep(i,1,m){
		if(col[2*i-1]==col[2*i])return puts("No"),0;
		else if(col[2*i-1]>col[2*i]){
			sta[++tc]=i;
		}
	}
	puts("Yes");
	printf("%d\n",tc);
	rep(i,1,tc)printf("%d%c",sta[i]," \n"[i==tc]);
}