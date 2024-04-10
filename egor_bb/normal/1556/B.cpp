#include <bits/stdc++.h> 
 
using namespace std;
 
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

ll solve(vi &a, int s) {
	int n = sz(a);
	vector<int> positions[2] = {vi(), vi()};
	forn(i, n) {
		positions[a[i]].pb(i);
	}
	int cur[2] = {0, 0};
	ll res = 0;
	forn(i, n) {
		int curS = (s + i) & 1;
		int pos = positions[curS][cur[curS]];
		if (pos > i) {
			res += pos - i;
		}
		cur[curS]++;
	}
	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		forn(i, n) {
			int x;
			cin >> x;
			a[i] = x & 1;
		}
		int cnt[2] = {0, 0};
		forn(i, n) {
			cnt[a[i]]++;
		}
		if (abs(cnt[0] - cnt[1]) > 1) {
			cout << -1 << '\n';
			continue;
		}
		ll ans = 0;
		if (cnt[0] > cnt[1]) {
			ans = solve(a, 0);
		} else if (cnt[1] > cnt[0]) {
			ans = solve(a, 1);
		} else {
			ans = min(solve(a, 0), solve(a, 1));
		}
		cout << ans << '\n';
	}
	return 0;
}