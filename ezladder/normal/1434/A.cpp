#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

ll q[6];
int n;
ll a[100007];
ll ans = 1e18;
int pos[100007];

void check(multiset<int>& f) {
	int mi = *f.begin();
	int ma = *(prev(f.end()));
	ans = min(ans, (ll)(ma - mi));
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 6; ++i) cin >> q[i];
	sort(q, q + 6);
	reverse(q, q + 6);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<vector<int> > kek;
	vector<pair<int, int> > t;
	multiset<int> f;
	for (int i = 0; i < n; ++i) {
		kek.emplace_back();
		for (int j = 0; j < 6; ++j) kek.back().pb(a[i] - q[j]), t.pb({kek.back().back(), i});
		f.insert(kek.back()[0]);
	} 


	sort(all(t));
	check(f);
	for (auto [w1, w2] : t) {
		f.erase(f.find(w1));
		++pos[w2];
		if (pos[w2] >= 6) break;
		f.insert(kek[w2][pos[w2]]);
		check(f);
	}
	cout << ans;
}