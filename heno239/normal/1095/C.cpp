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
const ll mod = (ll)(1e+9) + 7;
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
int n, k;
int c[30];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	per(i, 30) {
		int d = (1 << i);
		if (d&n) {
			c[i]++; k--;
		}
	}
	for (int i = 29; i > 0; i--) {
		if (k <= 0)continue;
		if (c[i] < k) {
			k -= c[i]; c[i - 1] += 2*c[i]; c[i] = 0;
		}
		else {
			c[i - 1] += 2*k; c[i] -= k; k = 0;
		}
	}
	if (k != 0) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		bool f = false;
		rep(i, 30) {
			rep(j, c[i]) {
				if (f)cout << " ";
				else f = true;
				cout << (1 << i);
			}
		}
		cout << endl;
	}
	return 0;
}