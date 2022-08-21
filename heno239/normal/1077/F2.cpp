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

typedef long long tr;
//
bool func(tr a, tr b) {
	return a <= b;
}
//namin[0,k),...,min[i,i+k),...,min[n-k,n)
vector<tr> slide_minimum(vector<tr> a,int k) {
	int n = a.size();
	vector<tr> res(n-k+1);
	vector<int> deq(n);
	int s = 0, t = 0;
	rep(i, n) {
		while (s < t&&func(a[deq[t - 1]] , a[i]))t--;
		deq[t++] = i;
		if (i - k + 1 >= 0) {
			res[i - k + 1] = a[deq[s]];
			if (deq[s] == i - k + 1)s++;
		}
	}
	return res;
}
int n, k, x;
ll a[5000];
vector<ll> cur;
ll dp[5000];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k >> x;
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		if (i < k)cur.push_back(a[i]);
		else cur.push_back(-1);
	}
	rep(j, x - 1) {
		fill(dp, dp + n, -1);
		vector<ll> manc;
		ll ma = -1;
		rep(i, k) {
			manc.push_back(ma);
			ma = max(ma, cur[i]);
		}
		vector<ll> maxcur = slide_minimum(cur,k);
		rep(i, n - k) {
			manc.push_back(maxcur[i]);
		}
		rep1(i, n - 1) {
			ll z = manc[i];
			if (z >= 0) {
				dp[i] = z + a[i];
			}
		}
		rep(i, n) {
			cur[i] = dp[i];
		}
	}
	ll out = -1;
	Rep(i, n - k, n) {
		out = max(out, cur[i]);
	}
	cout << out << endl;
	return 0;
}