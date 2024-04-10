#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;

int dfn[N],low[N],ins[N],st[N],bel[N],ty[N],cntu[N];
char s[N];
VI e[N],comp[N];
int ind,top,ww,n,m,u,v,cnt,_;

void tarjan(int u) {
	dfn[u]=low[u]=++ind;
	ins[u]=1;
	st[++top]=u;
	rep(i,0,SZ(e[u])) {
		int v=e[u][i];
		if (!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if (ins[v]) low[u]=min(low[u],low[v]);
	} 
	if (dfn[u]==low[u]) {
		++cnt;
		comp[cnt].clear();
		cntu[cnt]=0;
		while (1) {
			int v=st[top];
			comp[cnt].pb(v);
			bel[v]=cnt;
			ins[v]=0;
			cntu[cnt]+=ty[v/2]==0;
			if (st[top--]==u) break;
		}
		if (cntu[cnt]>=2) {
			ww=0;
		}
		bool vis=0;
		for (auto v:comp[cnt]) {
			for (auto u:e[v]) if (bel[u]!=cnt) {
				vis|=cntu[bel[u]];
			}
		}
		if (cntu[cnt]&&vis) {
			ww=0;
		}
		cntu[cnt]|=vis;
	}
}

bool solve() {
	scanf("%d%d",&n,&m);

	rep(i,0,2*n) e[i].clear(),dfn[i]=low[i]=0;
	scanf("%s",s);
	rep(i,0,n) ty[i]=s[i]=='E';
	for (int i=0;i<m;i++) {
		scanf("%d%d",&u,&v);
		if (u>0) u=2*(u-1); else u=2*(-u-1)+1;
		if (v>0) v=2*(v-1); else v=2*(-v-1)+1;
		e[u^1].pb(v);
		e[v^1].pb(u);
	}
	ind=0;
	cnt=0;
	ww=1;
	rep(i,0,2*n) if (dfn[i]==0) {
		tarjan(i);
	}
	if (!ww) return 0;
	rep(i,0,n) if (ty[i]) {
		if (bel[2*i]==bel[2*i+1]) return 0;
	}
	rep(i,1,cnt+1) {
		int maxu=-1,mine=2*n;
		for (auto p:comp[i]) {
			if (ty[p/2]) {
				mine=min(mine,p);
			} else {
				maxu=max(maxu,p);
			}
		}
		if (mine<maxu) return 0;
	}
	return 1;
}

int main() {
	for (scanf("%d",&_);_;_--) {
		puts(solve()?"TRUE":"FALSE");
	}
}