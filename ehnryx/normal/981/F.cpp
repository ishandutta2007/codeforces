#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5;
ll p[2][2*N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	ll L;
	cin >> n >> L;

	for (int t=0; t<2; t++) {
		for (int i=0; i<n; i++) {
			cin >> p[t][i];
			p[t][i+n] = p[t][i] + L;
		}
		sort(p[t], p[t]+2*n);
	}

	auto possible = [&] (int len) {
		int cur = 0;
		for (int i=0; i<2*n; i++) {
			if (p[0][i] >= len && p[0][i]+len < 2*L) {
				while (cur < 2*n && p[1][cur]+len < p[0][i]) { cur++; }
				if (cur == 2*n || p[1][cur] > p[0][i]+len) return false;
				else cur++;
			}
		}
		return true;
	};

	int left, right, mid;
	left = 0;
	right = L/2;
	while (left <= right) {
		mid = (left+right)/2;
		if (possible(mid)) right = mid-1;
		else left = mid+1;
	}
	if (!possible(mid)) mid++;

	cout << mid << nl;

	return 0;
}