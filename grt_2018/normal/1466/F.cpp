#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

const int nax = 500 * 1000 + 10, mod = 1e9 + 7;
int n, m;
int am[nax];
vector<vi>V[nax];
bool done[nax];
int p[nax], siz[nax];
bool odd[nax];
int f[nax], inv[nax];
vi ans;

int Fund(int a) {
	if(p[a] != a) {
		p[a] = Fund(p[a]);
	}
	return p[a];
}

bool Onion(int a, int b) {
	a = Fund(a);
	b = Fund(b);
	if(a == b || (odd[a] && odd[b])) return 0;
	if(siz[a] < siz[b]) swap(a, b);
	siz[a] += siz[b];
	p[b] = a;
	odd[a] |= odd[b];
	return 1;
}

int fastpow(int a, int b) {
	int w = 1;
	while(b > 0) {
		if(b & 1) w = ((ll)w * a)% mod;
		b/=2;
		a = ((ll)a * a) % mod;
	}
	return w;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	f[0] = 1;
	inv[0] = 1;
	for(int i = 1; i <= m; ++i) {
		p[i] = i;
		siz[i] = 1;
		f[i] = ((ll)f[i - 1] * i) % mod;
		inv[i] = fastpow(f[i], mod - 2);
	}
	for(int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		if(k == 1) {
			int x;
			cin >> x;
			int pr = Fund(x);
			if(!odd[pr]) {
				odd[pr] = 1;
				ans.PB(i);
			}
		} else {
			int x, y;
			cin >> x >> y;
			if(Onion(x, y)) {
				ans.PB(i);
			}
		}
	}
	ll res = 1;
	for(int i = 1; i <= m; ++i) {
		if(p[i] == i) {
			ll pt = 1;
			if(odd[i]) {
				for(int j = 0; j < siz[i]; ++j) pt = (pt * 2) % mod;
				res = (res * pt) % mod;
			} else {
				pt = 0;
				for(int j = 0; j <= siz[i]; j += 2) {
					ll cur = ((ll)f[siz[i]] * inv[siz[i] - j]) % mod;
					cur = (cur * inv[j]) % mod;
					//cout << cur << " ";
					pt = (pt + cur) % mod;
				}
				res = (res * pt) % mod;
			}
			//cout << pt << " ";
		}
	}
	cout << res << " ";
	cout << (int)ans.size() << "\n";
	for(int x : ans) cout << x << " ";	
}