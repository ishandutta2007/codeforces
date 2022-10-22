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



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;
	int a[n];
	For(i,n) {
		cin >> a[i];
	}
	sort(a,a+n);

	if (n==1) {
		cout << a[0]+k << nl;
		return 0;
	}

	int cnt = 0;
	int j = 0;
	for (int i=n/2; i<n; i++) {
		if (a[i] == a[n/2]) {
			cnt++;
			j = i;
		}
	}

	int add = 0;
	while (j+1 < n) {
		int diff = a[j+1] - a[j];
		if ((ll)diff*cnt > k) {
			break;
		}
		k -= diff*cnt;
		add += diff;
		j++;
		cnt++;
		while (j+1<n && a[j+1] == a[j]) {
			j++;
			cnt++;
		}
	}

	cout << a[n/2] + add + k/cnt << nl;

	return 0;
}