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
const ll MOD = 998244353;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin>>n;
	int a[n][2];
	vector<pii> v;
	unordered_map<int,int> cnt[2];
	map<pii,int> vals;
	for(int i=0;i<n;i++) {
		for(int j=0;j<2;j++) {
			cin>>a[i][j];
			cnt[j][a[i][j]]++;
		}
		vals[pii(a[i][0],a[i][1])]++;
		v.push_back(pii(a[i][0],a[i][1]));
	}

	auto sorted = [&]() {
		sort(v.begin(),v.end());
		for(int i=1;i<n;i++) {
			if(v[i].first>=v[i-1].first&&v[i].second>=v[i-1].second) continue;
			return false;
		}
		return true;
	};

	ll fact[n+1];
	fact[0] = 1;
	for(int i=1;i<=n;i++) {
		fact[i] = i*fact[i-1]%MOD;
	}

	ll ans = fact[n];
	for(int j=0;j<2;j++) {
		ll cur = 1;
		for(pii it:cnt[j]) {
			cur = cur*fact[it.second]%MOD;
		}
		ans += MOD-cur;
	}
	if(sorted()) {
		ll cur = 1;
		for(auto it:vals) {
			cur = cur*fact[it.second]%MOD;
		}
		ans += cur;
	}
	cout<<ans%MOD<<nl;

	return 0;
}