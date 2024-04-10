#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;
ll a[1000007];

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i], a[i] -= i;

	vector<pair<ll, int> > t;
	t.pb({a[0], 1});

	for (int i = 1; i < n; ++i) {
		//assert(t.back().x <= a[i]);

		t.back().y++;
		ll extra = a[i] - t.back().x;


		while (t.size() > 1) {
			ll can = t.back().y * (ll)(t[(int)t.size() - 2].x - t.back().x);
			if (can <= extra) {
				extra -= can;
				t[(int)t.size() - 2].y += t.back().y;
				t.pop_back();
				if (extra == 0) break;
			} else {
				break;
			}
		}

		if (extra > 0) {
			t.back().x += extra / t.back().y;
			extra %= t.back().y;
			if (extra > 0) {
				t.push_back({t.back().x, t.back().y - extra});
				t[(int)t.size() - 2].x++;
				t[(int)t.size() - 2].y = extra;
			}
		}
	}

	int add = 0;
	for (auto [w1, w2] : t) {
		for (int i = 0; i < w2; ++i) {
			cout << w1 + add << ' ';
			++add;
		}
	}

}