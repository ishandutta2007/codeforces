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

const int K = 33;

int topBit(int x) {
	fornr(i, 31) {
		if (x & (1ll << i)) {
			return i + 1;
		}
	}
	return 0;
}

int solve(vector<int> &v) {
	if (sz(v) <= 2) {
		return 0;
	}
	vector<int> cnt[K];
	forn(i, K) {
		cnt[i].clear();
	}
	int n = sz(v);
	for(int x : v) {
		int top = topBit(x);
		if (top == 0) {
			cnt[top].pb(x);
		} else {
			cnt[top].pb(x ^ (1ll << (top - 1)));
		}
	}
	int curCnt = 0, below = n;
	int ans = n;
	fornr(i, K) {
		if (sz(cnt[i])) {
			int val = n - curCnt - sz(cnt[i]);
			below -= sz(cnt[i]);
			if (below) {
				val--;
			}
			val += solve(cnt[i]);
			ans = min(ans, val);
			curCnt++;
		}
	}
	return ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> v;
	forn(i, n) {
		int x;
		cin >> x;
		v.pb(x);
	}
	cout << solve(v) << '\n';
	
	return 0;
}