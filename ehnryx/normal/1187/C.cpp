#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e3+1;
int sorted[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;

	vector<pii> nosort;
	For(i,m) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 0) {
			nosort.push_back(pii(l,r));
		} else {
			FOR(j,2*l,2*r) {
				sorted[j] = true;
			}
		}
	}

	for (const pii& it : nosort) {
		bool ok = false;
		FOR(i,2*it.first,2*it.second) {
			if (!sorted[i]) {
				ok = true;
				break;
			}
		}
		if (!ok) {
			cout << "NO" << nl;
			return 0;
		}
	}

	cout << "YES" << nl;
	int cur = 1e9;
	FOR(i,1,n) {
		if (!sorted[2*i-1]) {
			cur -= 7*n;
		}
		cout << cur++ << " ";
	}
	cout << nl;

	return 0;
}