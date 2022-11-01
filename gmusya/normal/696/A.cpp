#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll q;
	cin >> q;
	unordered_map <ll, ll> c;
	while (q--) {
		ll t;
		cin >> t;
		if (t == 1) {
			ll v, u, w;
			cin >> v >> u >> w;
			ll copy_v = v, copy_u = u;
			string sv, su;
			while (copy_v > 0) {
				if (copy_v % 2)
					sv = "1" + sv;
				else
					sv = "0" + sv;
				copy_v /= 2;
			}
			while (copy_u > 0) {
				if (copy_u % 2)
					su = "1" + su;
				else
					su = "0" + su;
				copy_u /= 2;
			}
			ll lca = 0;
			ll pos = 0;
			while (pos < min(sv.size(), su.size()) && sv[pos] == su[pos])
				pos++;
			pos--;
			for (ll i = 0; i <= pos; i++) {
				if (sv[i] == '1')
					lca = lca * 2 + 1;
				else
					lca *= 2;
			}
			ll copy_lca = lca;
			ll copy_pos = pos + 1;
			while (copy_lca < u) {
				if (su[copy_pos] == '1')
					copy_lca = copy_lca * 2 + 1;
				else
					copy_lca *= 2;
				c[copy_lca] += w;
				copy_pos++;
			}
			copy_lca = lca;
			copy_pos = pos + 1;
			while (copy_lca < v) {
				if (sv[copy_pos] == '1')
					copy_lca = copy_lca * 2 + 1;
				else
					copy_lca *= 2;
				c[copy_lca] += w;
				copy_pos++;
			}
		}
		if (t == 2) {
			ll v, u, ans = 0;
			cin >> v >> u;
			ll copy_v = v, copy_u = u;
			string sv, su;
			while (copy_v > 0) {
				if (copy_v % 2)
					sv = "1" + sv;
				else
					sv = "0" + sv;
				copy_v /= 2;
			}
			while (copy_u > 0) {
				if (copy_u % 2)
					su = "1" + su;
				else
					su = "0" + su;
				copy_u /= 2;
			}
			ll lca = 0;
			ll pos = 0;
			while (pos < min(sv.size(), su.size()) && sv[pos] == su[pos])
				pos++;
			pos--;
			for (ll i = 0; i <= pos; i++) {
				if (sv[i] == '1')
					lca = lca * 2 + 1;
				else
					lca *= 2;
			}
			ll copy_lca = lca;
			ll copy_pos = pos + 1;
			while (copy_lca < u) {
				if (su[copy_pos] == '1')
					copy_lca = copy_lca * 2 + 1;
				else
					copy_lca *= 2;
				ans += c[copy_lca];
				copy_pos++;
			}
			copy_lca = lca;
			copy_pos = pos + 1;
			while (copy_lca < v) {
				if (sv[copy_pos] == '1')
					copy_lca = copy_lca * 2 + 1;
				else
					copy_lca *= 2;
				ans += c[copy_lca];
				copy_pos++;
			}
			cout << ans << endl;
		}
	}
	return 0;
}