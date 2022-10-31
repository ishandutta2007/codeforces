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
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int ans = 0;
		map<int, int> cnt;
		forn(i, n) {
			int x;
			cin >> x;
			cnt[x]++;
		}
		for(auto [x, c] : cnt) {
			int tmp = c;
			int curX = x;
			while(1) {
				int nxt = curX + (curX - x);
				if (nxt == x) nxt++;
				auto it = cnt.lower_bound(nxt);
				if (it == cnt.end()) break;
				curX = it->fst;
				tmp++;
			}
			ans = max(tmp, ans);
		}
		cout << n - ans << '\n';
	}
	return 0;
}