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
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

int ma[2001];
ll dp[2001];
ll ra[2001];
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n);
	vector<P> q(m);
	rep(i, n)cin >> a[i];
	rep(i, m) {
		cin >> q[i].first >> q[i].second;
		if (q[i].first > k)continue;
		ma[q[i].first] = max(ma[q[i].first], q[i].second);
	}
	sort(a.begin(), a.end());
	rep(i, k) {
		ra[i + 1] = ra[i] + a[i];
	}
	rep(i, k) {
		rep1(j, k) {
			if (i + j > k)break;
			dp[i + j] = max(dp[i + j], dp[i] + ra[i + ma[j]] - ra[i]);
		}
	}
	cout << ra[k] - dp[k] << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}