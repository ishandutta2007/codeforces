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



//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	string s;
	cin >> s;
	int n = s.size();

	int a[n];
	For(i,n) {
		a[i] = i;
	}
	shuffle(a,a+n,rng);

	int memo[n];
	memset(memo, INF, sizeof memo);
	For(i,n && clock()<3.3*CLOCKS_PER_SEC) {
		int m = a[i];
		for (int j=1; m-j>=0 && m+j<n; j++) {
			if (s[m-j] == s[m] && s[m] == s[m+j]) {
				memo[m-j] = min(memo[m-j], m+j);
				break;
			}
		}
	}

	multiset<int> st;
	st.insert(INF);
	For(i,n) {
		st.insert(memo[i]);
	}

	ll ans = 0;
	For(i,n) {
		int it = *st.begin();
		if (it < INF) {
			ans += n-it;
		}
		st.erase(st.find(memo[i]));
	}
	cout << ans << nl;

	return 0;
}