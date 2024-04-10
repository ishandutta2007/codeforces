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

const int N = 24;
int sum[1<<N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		int bm = 0;
		for(int j=0;j<3;j++) {
			bm |= 1<<(s[j]-'a');
		}
		sum[bm]++;
	}

	for(int i=0;i<N;i++) {
		for(int bm=0;bm<1<<N;bm++) {
			if(bm&1<<i) {
				sum[bm] += sum[bm^1<<i];
			}
		}
	}

	ll ans = 0;
	for(int i=0;i<1<<N;i++) {
		sum[i] = n-sum[i];
		assert(sum[i]>=0);
		ans ^= (ll)sum[i]*sum[i];
	}
	cout<<ans<<nl;

	return 0;
}