#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;--i)
#define foe(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,mo=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=1e5+11;
int n,m,h,a[N];
vector<int> g[N],f[N];
int dfn[N],low[N],siz[N];
char vt[N];
int sta[N],sop,scc,c[N];
char ddd[N];
void dfs(int x){
	static int cnt;
	dfn[x]=low[x]=++cnt;
	sta[++sop]=x,vt[x]=1;
	foe(i,f[x]){
		if(!dfn[*i]){
			dfs(*i);
			low[x]=min(low[x],low[*i]);
		}else if(vt[*i]){
			low[x]=min(low[x],dfn[*i]);
		}
	}
	if(dfn[x]==low[x]){
		int v;++scc;
		do{
			v=sta[sop--];
			vt[v]=0,siz[scc]++;
			c[v]=scc;
		}while(v!=x);
	}
}
int U[N*5],V[N*5],tot;
int main(){
#ifdef flukehn
	freopen(".in","r",stdin);
#endif
	n=rd(),m=rd(),h=rd();
	rep(i,1,n)a[i]=rd();
	rep(i,1,m){
		int u=rd(),v=rd();
		g[u].pb(v);
		g[v].pb(u);
	}
	/*rep(i,1,n)if(fa(i)==i){
		cout<<i<<" "<<sz[i]<<endl;
	}*/
	rep(i,1,n){
		int x=(a[i]+1)%h;
		//int fl=0;
		foe(j,g[i])if(a[*j]==x){
			f[i].pb(*j);
			U[++tot]=i,V[tot]=*j;
		}
	}
	rep(i,1,n){
		if(!dfn[i])dfs(i);
	}
	rep(i,1,tot){
		int x=c[U[i]],y=c[V[i]];
		if(x!=y)
			ddd[x]=1;
	}
	//rep(i,1,n)cout<<c[i]<<endl;
	siz[0]=inf;
	int mx=0;
	rep(i,1,scc)if(!ddd[i]&&siz[i]<siz[mx])mx=i;
	printf("%d\n",siz[mx]);
	rep(i,1,n){
		if(c[i]==mx)printf("%d ",i);
	}
}