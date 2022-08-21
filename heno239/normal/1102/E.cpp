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
const ll mod = 998244353;
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
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
map<int, int> mp;
int n;
int a[1 << 18];
int main() {
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		mp[a[i]] = i;
	}
	int cur = 0;
	ll ans = (1 + mod) / 2;
	while (cur < n) {
		ans = ans * 2 % mod;
		int ri = mp[a[cur]];
		while (cur < ri) {
			ri = max(ri, mp[a[cur]]);
			cur++;
		}
		cur++;
	}
	cout << ans << endl;
	//stop
	return 0;
}