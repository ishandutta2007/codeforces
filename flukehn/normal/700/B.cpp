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
const int inf=~0u>>1,mod=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=2e5+11;
vector<int> g[N];
int n,k;
int sz[N];
ll ans;
void Dfs(int x,int fa=0){
	foe(i,g[x])if(*i!=fa){
		Dfs(*i,x);
		sz[x]+=sz[*i];
	}
	//cerr<<x<<" "<<sz[x]<<" "<<n-sz[x]<<endl;
	ans+=min(sz[x],2*k-sz[x]);
}
int main(){
#ifdef flukehn
	freopen(".in","r",stdin);
#endif
	n=rd(),k=rd();
	rep(i,1,2*k){
		int x=rd();
		sz[x]=1;
	}
	rep(i,2,n){
		int u=rd(),v=rd();
		g[u].pb(v);
		g[v].pb(u);
	}
	Dfs(1);
	cout<<ans<<endl;
}