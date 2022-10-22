#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

inline void srand() { srand(clock() + time(nullptr)); }

template <class T, class U>
ostream& operator << (ostream& os, const pair<T,U>& v) {
	os << "(" << v.first << "," << v.second << ")"; return os;
}

template <class T>
ostream& operator << (ostream& os, const vector<T>& v) {
	for (const T& it : v) os << it << " "; return os;
}

template <class T>
ostream& operator << (ostream& os, const set<T>& v) {
	os << "{ "; for (const T& it : v) os << it << " "; os << "}"; return os;
}

template <class T, class U>
ostream& operator << (ostream& os, const map<T,U>& v) {
	os << "{ ";
	for (const pair<T,U>& it : v) os << "{" << it.first << "," << it.second << "} "; 
	os << "}"; return os;
}

template <class T>
inline T sqr(T x) { return x*x; }

const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
//const ld PI = M_PIl;
////////////////////////////////////////////////////////////////////////

const ll MOD = 1e9+7;
const ld EPS = 1e-9;




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k, v;
	cin >> n >> k >> v;

	int sum = 0;
	int a[n+1];
	int res[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		res[i] = a[i] % k;
		sum += a[i];
	}

	int goal = v % k;
	int dp[n+1][k+1];
	int prev[n+1][k+1];
	memset(dp, INF, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			if (dp[i-1][j] < dp[i][j]) {
				dp[i][j] = dp[i-1][j];
				prev[i][j] = j;
			}
			if (dp[i-1][j] + res[i] < dp[i][(j+res[i])%k]) {
				dp[i][(j+res[i])%k] = dp[i-1][j] + res[i];
				prev[i][(j+res[i])%k] = j;
			}
		}
	}

	if (dp[n][goal] == INF || v > sum) {
		cout << "NO" << nl;
	}

	else {
		cout << "YES" << nl;

		vector<int> add, meh;
		int cur = goal;
		for (int i = n; i > 0; i--) {
			if (prev[i][cur] == cur) {
				meh.push_back(i);
			} else {
				cur = prev[i][cur];
				add.push_back(i);
			}
		}

		int good = (add.empty()) ? 0 : a[add[0]];
		for (int i = 1; i < add.size(); i++) {
			if (a[add[i]] > 0)
				cout << a[add[i]] + (res[add[i]] > 0) << " " << add[i] << " " << add[0] << nl;
			good += a[add[i]];
		}

		int bad = (meh.empty()) ? 0 : a[meh[0]];
		for (int i = 1; i < meh.size(); i++) {
			if (a[meh[i]] > 0)
				cout << a[meh[i]] + (res[meh[i]] > 0) << " " << meh[i] << " " << meh[0] << nl;
			bad += a[meh[i]];
		}

		if (good > v) {
			if (add.empty())
				cout << (good - v) / k << " " << 1+meh[0]%n << " " << meh[0] << nl;
			else if (meh.empty())
				cout << (good - v) / k << " " << add[0] << " " << 1+add[0]%n << nl;
			else
				cout << (good - v) / k << " " << add[0] << " " << meh[0] << nl;
		}
		else if (good < v) {
			if (add.empty())
				cout << (v - good) / k << " " << meh[0] << " " << 1+meh[0]%n << nl;
			else if (meh.empty())
				cout << (v - good) / k << " " << 1+add[0]%n << " " << add[0] << nl;
			else
				cout << (v - good) / k << " " << meh[0] << " " << add[0] << nl;
		}
	}

	return 0;
}