#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int SIZE = 2E5+5;
const ll MOD = 1e9+7;

bool vis[SIZE];
ll v[SIZE];
ll vemPar[SIZE];
ll vemImpar[SIZE];
ll sobePar[SIZE];
ll sobeImpar[SIZE];
vi g[SIZE];

// ans = par - impar;

ll MODE(ll ans) {
	ans = ans % MOD;
	return (ans < 0) ? ans + MOD : ans;
}

ll MODEI(ll ans) {
	if(ans > 1E8) return ans - MOD;
}

void calculaSobe(int pos, int par = -1) {
	for(int v : g[pos]) {
		if(v != par) {
			calculaSobe(v, pos);
			sobePar[pos] += sobeImpar[v];
			sobeImpar[pos] += sobePar[v];
		}
	}
	sobePar[pos]++;
}

ll calc(int pos, int par = -1) {
	if(par != -1) {
		vemPar[pos] = vemImpar[par] + 1 - sobePar[pos];
		vemImpar[pos] = vemPar[par] - sobeImpar[pos];
	} else {
		vemPar[pos] = 1;
		vemImpar[pos] = 0;
	}
	ll ans = MODE(MODE((vemPar[pos] - vemImpar[pos]) * (sobePar[pos] + sobeImpar[pos])) * v[pos]);
	//if(pos == 2) cout << "::::" << MODEI(ans) << '\n';
	ans = MODE(ans + MODE(v[pos] * (vemPar[pos] + vemImpar[pos] - 1)));
	for(int v : g[pos]) {
		if(v != par) {
			vemPar[pos] += sobeImpar[v];
			vemImpar[pos] += sobePar[v];
		}
	}
	//if(pos == 2) cout << "::::" << MODEI(ans) << '\n';
	for(int a : g[pos]) {
		if(a != par) {
			ans = MODE(ans + MODE(MODE((vemPar[pos] - sobeImpar[a] + vemImpar[pos] - sobePar[a]) * (sobeImpar[a] - sobePar[a])) * v[pos]));
			ans = MODE(ans + calc(a, pos));
		}
	}
	//cout << "POS: " << pos << " : " << MODEI(ans) << '\n';
	//cout << vemPar[pos] << ' ' << vemImpar[pos] << '\n';
	//cout << sobePar[pos] << ' ' << sobeImpar[pos] << '\n';
	return ans;
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> v[i+1];
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	calculaSobe(1);
	ll ans = calc(1);
	cout << ans << '\n';
	return 0;
}