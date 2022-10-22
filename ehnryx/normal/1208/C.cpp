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

vector<vector<int>> g = {
	{ 8, 9, 1, 13 }, 
	{ 3, 12, 7, 5 },
	{ 0, 2, 4, 11 },
	{ 6, 10, 15, 14 }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin>>n;
	int ans[n][n];
	int pre = 0;
	for(int i=0;i<n;i+=4) {
		for(int j=0;j<n;j+=4) {
			for(int ii=0;ii<4;ii++) {
				for(int jj=0;jj<4;jj++) {
					ans[i+ii][j+jj] = pre<<4|g[ii][jj];
				}
			}
			pre++;
		}
	}

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<ans[i][j]<<" ";
		}
		cout<<nl;
	}

	return 0;
}