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

const int N = 1e4;
int cnt[N+1];
bitset<N+1> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, q;
	cin >> n >> q;

	vector<pii> p;
	int a, b, c;
	for (int i=0; i<q; i++) {
		cin >> a >> b >> c;
		p.push_back(pii(a,c));
		p.push_back(pii(b+1,-c));
	}
	sort(p.begin(), p.end());

	cnt[0] = 1;
	for (const pii& it : p) {
		if (it.second > 0) {
			for (int i=N-it.second; i>=0; i--) {
				cnt[i+it.second] += cnt[i];
				if (cnt[i+it.second] > 0) ans[i+it.second] = true;
			}
		}
		else {
			int v = -it.second;
			for (int i=v; i<=N; i++) {
				cnt[i] -= cnt[i-v];
			}
		}
	}

	int sum = 0;
	for (int i=1; i<=n; i++) {
		sum += ans[i];
	}
	cout << sum << nl;
	for (int i=1; i<=n; i++) {
		if (ans[i]) cout << i << " ";
	}
	cout << nl;

	return 0;
}