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

	int n, s;
	cin >> n >> s;
	int k = 1<<min(20,s*8/n);

	map<int,int> cnt;
	For(i,n) {
		int a;
		cin >> a;
		cnt[a]++;
	}
	int m = cnt.size();

	if (k >= m) {
		cout << 0 << nl;
		return 0;
	}

	vector<int> freq;
	for (const auto& it : cnt) {
		freq.push_back(it.second);
	}
	int cur = 0;
	for (int i=0; i<k; i++) {
		cur += freq[i];
	}
	int ans = cur;
	for (int i=k; i<m; i++) {
		cur += freq[i];
		cur -= freq[i-k];
		ans = max(ans, cur);
	}
	cout << n-ans << nl;

	return 0;
}