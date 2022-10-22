#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int,int> TP;
typedef vector<vector<ll>> mat;
const ll mod=1e9+7;
mat operator *(const mat &a,const mat &b)
{
	int n=a.size(),w=b.size(),m=b[0].size();
	mat c(n,vector<ll>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<w;j++){
			for(int k=0;k<m;k++){
				(c[i][k]+=a[i][j]*b[j][k]%mod)%=mod;
			}
		}
	}
	return c;
}
namespace fastIO{
	int cntF = 0;
	int lenF = 0;
	char bufF[1000000];
	void re() {
		cntF = 0;
		lenF = fread(bufF, 1, 1000000, stdin);
	}
	int nextint() {
		if (lenF == cntF) re();
		while (!(bufF[cntF] >= '0' && bufF[cntF] <= '9')) {
			cntF++;
			if (lenF == cntF) re();
			if (lenF == cntF) return -1;
		}
		int retF = 0;
		while ((bufF[cntF] >= '0' && bufF[cntF] <= '9')) {
			retF *= 10;
			retF += bufF[cntF]-'0';
			cntF++;
			if (lenF == cntF) re();
			if (lenF == cntF) return retF;
		}
		return retF;
	}
};
using namespace fastIO;
const int N=1e5+5;
int n;
ll a[N],p[18][N],h[N],v[18][N],ans;
vector<int> g[N];
void dfs(int u,int par)
{
	for(auto &it : g[u]) if(it!=par){
		h[it]=h[u]+1;
		p[0][it]=u; v[0][it]=__gcd(a[u],a[it]);
		dfs(it,u);
	}
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int u,v,i=1;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v); g[v].push_back(u);
	}
	dfs(1,0);
	for(int bit=1;bit<18;bit++) for(int i=1;i<=n;i++){
		p[bit][i]=p[bit-1][p[bit-1][i]];
		v[bit][i]=__gcd(v[bit-1][i],v[bit-1][p[bit-1][i]]);
	}
	ans=a[1]%mod;
	for(int i=2;i<=n;i++){
		ll cur=a[i]; int u=i;
		while(u){
			int ve=u;
			for(ll bit=17;bit>=0;bit--) if(p[bit][u]&&__gcd(cur,v[bit][u])==cur) u=p[bit][u];
			(ans+=(h[ve]-h[u]+1LL)*(cur%mod)%mod)%=mod;
			u=p[0][u]; cur=__gcd(cur,a[u]);
		}
	}
	cout<<ans;
    return 0;
}