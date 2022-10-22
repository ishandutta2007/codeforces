#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int nax = 100*1000+10,mod = 1e9+7;
int n;
ll val[nax];
vi V[nax];
map<ll,int> g[nax];
ll ans;

void dfs(int x,int p) {
	g[x][val[x]]=1;
	for(auto it:g[p]) {
		g[x][__gcd(val[x],it.ST)]+=it.ND;
	}
	for(auto it:g[x]) {
		ans=(ans+((ll)it.ST*it.ND)%mod)%mod;
	}
	for(int nbh:V[x]) if(nbh!=p) dfs(nbh,x);
}

int main() {_
	cin>>n;
	for(int i=1; i<=n; i++) cin>>val[i];
	for(int a,b,i=1; i<n; i++) {
		cin>>a>>b;
		V[a].PB(b);
		V[b].PB(a);
	}
	dfs(1,0);
	cout<<ans;
}