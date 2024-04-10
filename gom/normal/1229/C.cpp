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
int n,m,q,a[N];
ll dn[N],up[N];
vector<int> g[N],cur[N];
ll ans;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	for(int u,v,i=1;i<=m;i++){
		cin>>u>>v;
		g[u].push_back(v); g[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		for(auto &it : g[i]){
			if(i>it) dn[i]++;
			else{
				up[i]++;
				cur[i].push_back(it);
			}
		}
		ans+=up[i]*dn[i];
	}
	cout<<ans<<"\n";
	cin>>q;
	for(int u,i=1;i<=q;i++){
		cin>>u;
		for(auto &it : cur[u]){
			ans-=up[it]*dn[it];
			dn[it]--; up[it]++;
			ans+=up[it]*dn[it];
			cur[it].push_back(u);
		}
		cur[u].clear();
		ans-=dn[u]*up[u];
		dn[u]=g[u].size(); up[u]=0;
		cout<<ans<<"\n";
		//for(int i=1;i<=n;i++) cout<<i<<" : "<<up[i]<<" - "<<dn[i]<<"\n";
	}
    return 0;
}