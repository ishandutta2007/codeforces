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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int memo[33];
ll aa[1 << 18];
LP x[1 << 18];
int main() {
	fill(memo, memo + 33, -1);
	int n; scanf(" %d", &n);
	ll out = 0;
	rep(i, n) {
		scanf(" %lld", &aa[i]);
		x[i] = { aa[i],-i };
	}
	sort(x, x + n);
	rep(i, n) {
		ll a = aa[i];
		ll orsum = a;
		vector<int> v;
		v.push_back(i);
		rep(j, 33) {
			if (a&((ll)1 << j))continue;
			v.push_back(memo[j]);
		}
		sort(v.begin(), v.end(), greater<int>());
		int len = v.size();
		int cnt = 0;
		while (a) {
			if (a % 2) {
				memo[cnt] = i;
			}
			a /= 2; cnt++;
		}
		len = v.size();
		rep(j, len - 1) {
			int le = v[j + 1]; int ri = v[j]; int chk = ri;
			if (le == ri)continue;
			orsum |= aa[ri];
			int id = lower_bound(x, x + n, LP{ orsum,-ri}) - x;
			if (id == n||x[id].first!=orsum)out += ri - le;
			else out += ri - max(le,(int)-x[id].second);
		}
	}
	
	printf("%lld", out);
	return 0;
}