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
ll p[5];
ll num[5];
void init() {
	p[0] = 1;
	rep1(i, 4) {
		p[i] = p[i - 1] * i;
	}
	num[0] = 1; num[1] = 0;
	Rep1(i, 2, 4) {
		vector<int> a(i);
		rep(j, i) {
			a[j] = j;
		}
		int c = 0;
		while (true) {
			bool f = true;
			rep(j, i) {
				if (a[j] == j)f = false;
			}
			if (f)c++;
			if (!next_permutation(a.begin(), a.end()))break;
		}
		num[i] = c;
	}
}
ll comb(ll n, ll k) {
	ll res = 1;
	for (ll i = n; i > n - k; i--) {
		res *= i;
	}
	for (ll i = 1; i <= k; i++) {
		res /= i;
	}
	return res;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	init();
	int n, k; cin >> n >> k;
	ll ans = 0;
	Rep1(i, n - k, n) {
		ll csum = comb(n, n - i)*num[n - i];
		ans += csum;
		//cout << csum << endl;
	}
	cout << ans << endl;
	return 0;
}