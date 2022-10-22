#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back

using namespace std;
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 100 * 1000 + 10;
int t, n;
vi V[nax];
int deg[nax];
int cnt[nax];
bool done[nax];

int solve(int x) {
	vi leaves;
	for(int i = 1; i <= n; ++i) {
		deg[i] = 0;
		done[i] = 0;
		cnt[i] = (int)V[i].size();
		if((int)V[i].size() == 1) {
			leaves.PB(i);
			done[i] = true;
		}
	}
	for(int i = 1; i < n - 1; ++i) {
		int u = leaves.back();
		leaves.pop_back();
		if(deg[u] % x == 0) {
			for(int nbh : V[u]) {
				if(!done[nbh]) {
					deg[nbh]++;
				}
			}
		} else {
			if((deg[u] + 1) % x != 0) {
				return 0;
			}
			deg[u]++;
		}
		for(int nbh : V[u]) {
			if(!done[nbh]) {
				cnt[nbh]--;
				if(cnt[nbh] == 1) {
					leaves.PB(nbh);
					done[nbh] = true;
				}
			}
		}
	}
	int u = leaves.back(), v = leaves[0];
	if(deg[u] % x == 0) deg[v]++;
	else if(deg[v] % x == 0) deg[u]++;
	else {
		return 0;
	}
	if(deg[u] % x != 0 || deg[v] % x != 0) return false;
	int g = 0;
	for(int i = 1; i <= n; ++i) {
		g = __gcd(g, deg[i]);
	}
	return g;
}

int ans[nax];

const int mod = 998244353;

int fastpow(int a, int b) {
	int w = 1;
	while(b > 0) {
		if(b & 1) w = ((ll)w * a) % mod;
		b /= 2;
		a = ((ll)a * a) % mod;
	}
	return w;
}

void test_case() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		V[i].clear();
		ans[i] = 0;
	}
	for(int a,b, i = 1; i < n; ++i) {
		cin >> a >> b;
		V[a].PB(b);
		V[b].PB(a);
	}
	int m = n - 1;
	vi pr;
	for(int i = 2; i <= n - 1; ++i) {
		if(m % i == 0) pr.PB(i);
		while(m % i == 0) {
			m /= i;
		}
	}
	for(int x : pr) {
		int w = solve(x);
		ans[w] = 1;
	}
	int sum = 0;
	for(int i = 2; i <= n; ++i) {
		sum += ans[i];
	}
	ans[1] = fastpow(2, n - 1) - sum;
	if(ans[1] < 0) ans[1] += mod;
	for(int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		test_case();
	}
}