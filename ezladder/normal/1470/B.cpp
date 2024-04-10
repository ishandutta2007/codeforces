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
int a[300007];

int kek(int val) {
	int d = 2;
	int kekos = 1;
	while (d * d <= val) {
		int cnt = 0;
		while (val % d == 0) {
			val /= d;
			++cnt;
		}
		if (cnt & 1) kekos *= d;
		++d;
	}
	if (val != 1) kekos *= val;
	return kekos;
}

void solve() {
	cin >> n;
	unordered_map<int, int> we;
	for (int i = 0; i < n; ++i) cin >> a[i], a[i] = kek(a[i]), we[a[i]]++;

	int ma = 0;
	int tot = 0;
	for (auto [w1, w2] : we) {
		ma = max(ma, w2);
		if (w1 == 1 || w2 % 2 == 0) {
			tot += w2;
		}
	}

	int q;
	cin >> q;
	while (q--) {
		ll w; cin >> w;
		if (w == 0) {
			cout << ma << "\n";
		} else {
			cout << max(ma, tot) << "\n";
		}
	}
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