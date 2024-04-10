#include <bits/stdc++.h> 
 
using namespace std;
 
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



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	ll ans = 0;
	map<int, int> cnt;
	map<pii, int> cnt2;
	forn(i, n) {
		int w, h;
		cin >> w >> h;
		if (w > h) swap(w, h);
		ans += cnt[w];
		if (w != h) {
			ans += cnt[h];
			ans -= cnt2[mp(w, h)];
		}
		cnt[w]++;
		if (w != h) {
			cnt[h]++;
			cnt2[mp(w, h)]++;
		}
	//	cout << ans << '\n';
	}
	cout << ans << '\n';
	return 0;
}