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
int a[10007];

struct kek {
	int a, b, c;
};

void solve() {
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
	if (sum % n != 0) {
		cout << "-1\n";
		return;
	}
	sum /= n;
	vector<kek> ans;

	int v = -1;
	for (int i = 0; i < n; ++i) {
		if (a[i] >= i + 1) v = i;
	}

	if (v == -1) {
		cout << "-1\n";
		return;
	}

	if (v != 0) {
		ans.pb({v + 1, 1, a[v] / (v + 1)});
		a[0] += (a[v] / (v + 1)) * (v + 1);
		a[v] -= (a[v] / (v + 1)) * (v + 1);
	}

	vector<int> can;
	for (int i = 1; i < n; ++i) can.pb(i);

	while (can.size()) {
		int i = 0;
		int ge = -1;
		for (int v : can) {
			int need = (v + 1) - a[v] % (v + 1);
			if (need == v + 1) need = 0;
			if (need <= a[0]) {
				ans.pb({1, v + 1, need});
				a[0] -= need;
				a[v] += need;
				ans.pb({v + 1, 1, a[v] / (v + 1)});
				a[0] += a[v];
				a[v] = 0;
				ge = i;
				break;
			}
			++i;
		}
		if (ge == -1) {
			cout << "-1\n";
			return;
		}
		swap(can.back(), can[ge]);
		can.pop_back();
	}

	for (int i = 1; i < n; ++i) {
		ans.pb({1, i + 1, sum});
	}

	assert(ans.size() <= 3 * n);
	cout << ans.size() << "\n";
	for (auto c : ans) cout << c.a << ' ' << c.b << ' ' << c.c << "\n";
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}