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

const ll P = 101;
const ll M = 1e9+7;

ll power(ll b, int e) {
	ll res = 1;
	for ( ; e>0; e/=2) {
		if (e&1) res = res*b % M;
		b = b*b % M;
	}
	return res;
}

const int N = 1e6+1;
ll ha[N];
int len = 0;
void add_hash(const string& s, int t) {
	for (int j=0, i=t; i<s.size(); i++, j++) {
		ha[len+j+1] = (ha[len+j]*P + s[i]) % M;
	}
	len += s.size()-t;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	string s[n];
	For(i,n) {
		cin >> s[i];
	}

	string ans = s[0];
	add_hash(s[0], 0);
	for (int i=1; i<n; i++) {
		ll cur = 0;
		int last = 0;
		for (int j=0; j<s[i].size() && len-j-1>=0; j++) {
			cur = (cur*P + s[i][j]) % M;
			if (cur == (ha[len]-ha[len-j-1]*power(P,j+1)%M + M) % M) {
				last = j+1;
			}
		}
		for (int j=last; j<s[i].size(); j++) {
			ans.push_back(s[i][j]);
		}
		add_hash(s[i], last);
	}
	cout << ans << nl;

	return 0;
}