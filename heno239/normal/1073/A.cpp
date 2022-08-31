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
const ld eps = 1e-12;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int c[1001][26];
int main() {
	int n; cin >> n;
	string s; cin >> s;
	rep(i, n) {
		rep(j, 26) {
			if (s[i] - 'a' == j)c[i + 1][j] = c[i][j] + 1;
			else c[i + 1][j] = c[i][j];
		}
	}
	//from i to j
	bool ansed = false;
	rep(i, n) {
		Rep(j, i + 1, n) {
			int len = j - i + 1;
			bool f = true;
			rep(k, 26) {
				int num = c[j + 1][k] - c[i][k];
				if (num*2 > len) {
					f = false;
				}
			}
			if (f) {
				cout << "YES" << endl;
				cout << s.substr(i, len) << endl;
				ansed = true;
			}
			if (ansed)break;
		}
		if (ansed)break;
	}
	if (!ansed)cout << "NO" << endl;
	return 0;
}