#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e6+1;
ll dp[N][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin>>n;

	dp[0][0] = 1;
	int d = 0;
	for(int i=1;i<=n;i++) {
		if(__builtin_popcount(i)==1) d++;
		int half = 1<<(d-1);
		//cerr<<"half: "<<half<<nl;
		for(int s=i/2-7; s<=i/2+7;s++) {
			int b = (s+1)%2;
			int left = s;
			int right = i - 1 - s;
			if(half/2-1<=left && left<half && half/2-1<=right && right<half) {
				dp[i][b] += dp[left][b^1] * dp[right][0];
				//int add = dp[left][b^1] * dp[right][0];
				//if(add) cerr<<" + "<<left<<","<<(b^1)<<" * "<<right<<","<<0<<nl;
				//cerr<<"dp "<<i<<" "<<b<<" += ("<<left<<","<<(b^1)<<") * ("<<right<<",0)"<<" @ "<<left<<" vs "<<right<<(add?" !! add ":"")<<(add?to_string(add):"")<<nl;
			}
		}
		//cout<<i<<": "<<dp[i][0]<<" + "<<dp[i][1]<<" = "<<dp[i][0]+dp[i][1]<<nl;
		//cerr<<nl;
	}
	cout<<dp[n][0]+dp[n][1]<<nl;

	return 0;
}