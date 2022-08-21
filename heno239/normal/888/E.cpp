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
//#define revstr(s) reverse(s.begin(),s.end())
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
ll a[36];
int n; ll m;
vector<ll> memo;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n) {
		cin >> a[i];
	}
	int d = n / 2, d1 = n - d;
	rep(i, (1 << d1)) {
		ll sum = 0;
		rep(j, d1) {
			if (i&(1 << j)) {
				sum += a[d + j];
			}
		}
		sum %= m;
		memo.push_back(sum);
	}
	sort(memo.begin(), memo.end());
	ll out = 0;
	rep(i, 1 << d) {
		ll sum = 0;
		rep(j, d) {
			if (i&(1 << j)) {
				sum += a[j];
			}
		}
		sum %= m;
		int id = lower_bound(memo.begin(), memo.end(), m - sum) - memo.begin();
		if (id > 0) {
			out = max(out, sum + memo[id-1]);
		}
		else {
			out = max(out, sum + m - memo[memo.size() - 1]);
		}
	}
	cout << out << endl;
	return 0;
}