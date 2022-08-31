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
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; ll k; cin >> n >> k;
	string s, t; cin >> s >> t;
	if (k == 1) {
		cout << n << endl; return 0;
	}
	int i = 0;
	while (i < n&&s[i] == t[i]) {
		i++;
	}
	ll out = 2*(n-i)+i;
	ll c1 = 1, c2 = 1;
	ll cs = 0, ct = 0;
	k -= 2;
	i++;
	while (i < n) {
		if (!k)break;
		ll csum = (n - i);
		ll sum = cs + ct;
		out += min(sum, k)*csum;
		k -= min(sum, k);
		cs *= 2; ct *= 2;
		if (s[i] == 'a') {
			if (k) {
				cs++; out += n - i; k--;
			}
		}
		if (t[i] == 'b') {
			if (k) {
				ct++; out += n - i; k--;
			}
		}
		i++;
	}
	cout << out << endl;
	return 0;
}