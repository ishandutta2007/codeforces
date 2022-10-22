#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
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

int solve(int a, int b, int k) {
	//cerr << "solving " << k << " full repeats" << nl;
	int n = a+b;
	int lb = (n+k+1)/(k+1);
	int ub = n/k;
	int alb = (a+k)/(k+1);
	int aub = a/k;
	int blb = (b+k)/(k+1);
	int bub = b/k;
	if (lb>ub || alb>aub || blb>bub) return 0;
	lb = max(lb, alb+blb);
	ub = min(ub, aub+bub);
	lb = max(lb, 1);
	ub = min(ub, n);
	return max(0, ub-lb+1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int a, b;
	cin >> a >> b;
	int n = a+b;

	int ans = 0;
	for (int i=1; i*i<=n; i++) {
		ans += solve(a, b, i);
		if (i!=n/i) ans += solve(a, b, n/i);
	}
	cout << ans << nl;

	return 0;
}