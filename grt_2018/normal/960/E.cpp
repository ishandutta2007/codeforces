#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 200 * 1000 + 10, mod = 1e9 + 7;
int n;
int val[nax];
int odd[nax], even[nax];
vi V[nax];
ll ans;

void dfs(int x, int p) {
	even[x] = 1;
	for(int nbh : V[x]) if(nbh != p) {
		dfs(nbh, x);
		even[x] += odd[nbh];
		odd[x] += even[nbh];
	}
}

void dfs2(int x, int p) {
	//~ cout << x << " " << even[x] << " " << odd[x] << "\n";
	for(int nbh : V[x]) {
		ans += ((ll)(even[x] - odd[nbh]) * odd[nbh] % mod) * val[x];
		ans %= mod;
		if(ans < 0) ans += mod;
		ans -= (ll)((ll)(odd[x] - even[nbh]) * even[nbh] % mod) * val[x];
		ans %= mod;
		if(ans < 0) ans += mod;
	}
	ans += (ll)even[x] * val[x];
	ans %= mod;
	if(ans < 0) ans += mod;
	for(int nbh : V[x]) if(nbh != p) {
		even[x] -= odd[nbh];
		odd[x] -= even[nbh];
		even[nbh] += odd[x];
		odd[nbh] += even[x];
		dfs2(nbh, x);
		even[nbh] -= odd[x];
		odd[nbh] -= even[x];
		even[x] += odd[nbh];
		odd[x] += even[nbh];
	}
}


int main() {_
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> val[i];
	}
	for(int a,b,i=1; i< n;++i) {
		cin >> a >> b;
		V[a].PB(b);
		V[b].PB(a);
	}
	dfs(1, 0);
	dfs2(1, 0);
	cout << ans;
	
}