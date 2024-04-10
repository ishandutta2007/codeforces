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



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int N = 20;
	set<int> s;
	int ans[N+1];
	for (int v=1; v<=N; v++) {
		for (int i=0; i<=v; i++) {
			for (int j=0; i+j<=v; j++) {
				for (int k=0; i+j+k<=v; k++) {
					int l = N-(i+j+k);
					s.insert(i+5*j+10*k+50*l);
				}
			}
		}
		ans[v] = s.size();
	}

	int n;
	cin >> n;

	if (n <= N) {
		cout << ans[n] << nl;
	} else {
		cout << ans[N] + (ll)49*(n-N) << nl;
	}

	return 0;
}