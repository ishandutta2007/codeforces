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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = (1e+9)+7;
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
typedef pair<ll,P> PP;
int main() {
	int n; cin >> n;
	string s, t; cin >> s >> t;
	ll out = 0;
	ll c0 = 0; ll c1 = 0;
	ll cc0 = 0; ll cc1 = 0;
	rep(i, n) {
		if (s[i] == '0')c0++;
		else c1++;
		if (t[i] == '0'&&s[i] == '0')cc0++;
		else if (t[i] == '0'&&s[i] == '1')cc1++;
	}
	rep(i, n) {
		if (t[i] == '0') {
			if (s[i] == '0') {
				out += c1;
			}
			else {
				out += c0;
			}
		}
	}
	out -= cc0 * cc1;
	cout << out << endl;
	return 0;
}