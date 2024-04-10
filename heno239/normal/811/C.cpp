#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-4;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int a[5000]; int n;
int xors[5000][5000];
bool valid[5000][5000];
bool nonuse[5001];
int dp[5001];
vector<int> v[5001];
bool aped[5001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		v[a[i]].push_back(i);
	}
	rep(i, n) {
		int s = 0;
		fill(aped, aped + 5001, false);
		Rep(j,i, n) {
			if (!aped[a[j]]) {
				aped[a[j]] = true; s ^= a[j];
			}
			xors[i][j] = s;
		}
	}
	rep(i, n) {
		int le = i; int j = i;
		while (le < n) {
			while (j <= le&&j<n&&le<n) {
				if (nonuse[a[j]]) {
					le = n; break;
				}
				int las = v[a[j]][v[a[j]].size() - 1];
				le = max(le, las);
				j++;
			}
			if (le >= n)break;
			valid[i][le] = true;
			le++;
		}
		nonuse[a[i]] = true;
	}
	rep(i, n) {
		Rep(j, i, n) {
			if (!valid[i][j])continue;
			dp[j + 1] = max(dp[j + 1], dp[i] + xors[i][j]);
		}
		dp[i + 1] = max(dp[i], dp[i + 1]);
	}
	cout << dp[n] << endl;
	return 0;
}