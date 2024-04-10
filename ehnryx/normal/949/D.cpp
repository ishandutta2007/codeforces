#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class T>
ostream& operator << (ostream& os, const vector<T>& v) {
	for (const T& it : v) os << it << ' '; return os;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, d, b;
	cin >> n >> d >> b;

	vector<int> to_l(n+1, 0), to_r(n+1, 0);
	int left[n+1], right[n+1];
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> to_l[i];
		sum += to_l[i];
		if (sum > n*b/2) {
			int diff = min(to_l[i], sum - n*b/2);
			to_l[i] -= diff;
			to_r[i] += diff;
		}
		left[i] = max((ll)1, i - (ll)(n-i+1)*d);
		right[i] = min((ll)n, i + (ll)i*d);
	}

	int other = 1;
	for (int i = 1; i <= n; i++) {
		while (other < right[i]) {
			++other;
			to_l[i] += to_l[other];
			to_l[other] = 0;
		}
	}
	other = n;
	for (int i = n; i > 0; i--) {
		while (other > left[i]) {
			--other;
			to_r[i] += to_r[other];
			to_r[other] = 0;
		}
	}

	int l_ans, r_ans;
	l_ans = r_ans = 0;
	for (int t = 0; t < n/2; t++) {
		if (to_l[1+t] < b) {
			l_ans++;
			to_l[1+t+1] += to_l[1+t];
		} else {
			to_l[1+t+1] += to_l[1+t] - b;
		}
		if (to_r[n-t] < b) {
			r_ans++;
			to_r[n-t-1] += to_r[n-t];
		} else {
			to_r[n-t-1] += to_r[n-t] - b;
		}
	}

	int ans = max(l_ans, r_ans);
	if (n % 2 == 1) {
		if (to_l[(n+1)/2] + to_r[(n+1)/2] < b) {
			ans++;
		}
	}
	cout << ans << nl;

	return 0;
}