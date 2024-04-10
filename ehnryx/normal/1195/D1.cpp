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
const ll MOD = 998244353;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e5+1;
const int L = 20;
ll p10[L];
ll sum[L];
string a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	p10[0] = 1;
	FOR(i,1,L-1) {
		p10[i] = p10[i-1] * 10 % MOD;
	}

	int n;
	cin >> n;

	For(i,n) {
		cin >> a[i];
	}

	For(j,20) {
		For(i,n) {
			int len = a[i].size();
			sum[j] = (sum[j] + p10[j + min(len,j)]) % MOD;
			sum[j] = (sum[j] + p10[j + min(len,j+1)]) % MOD;
		}
	}

	ll ans = 0;
	For(i,n) {
		reverse(a[i].begin(), a[i].end());
		For(j,a[i].size()) {
			ans += sum[j] * (a[i][j]-'0') % MOD;
		}
		ans %= MOD;
	}
	cout << ans << nl;

	return 0;
}