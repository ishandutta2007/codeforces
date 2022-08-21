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
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
int n; string s;
int c[3];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> s;
	rep(i, n) {
		c[s[i] - '0']++;
	}
	string ans;
	ans.resize(n, '3');
	rep(j, 3) {
		char t = '0' + j;
		if (c[j] >= n/3) {
			int cnt = 0;
			rep(i, n) {
				if (ans[i] != '3')continue;
				if (s[i] == t) {
					ans[i] = t; cnt++;
				}
				if (cnt == n / 3)break;
			}
		}
		else {
			int cnt = 0;
			rep(i, n) {
				if (s[i] == t) {
					ans[i] = t; cnt++;
				}
			}
			rep(i, n) {
				if (cnt == n / 3)break;
				if (ans[i] != '3')continue;
				int id = s[i] - '0';
				if (c[id] > n / 3) {
					c[id]--;
					ans[i] = t;
					cnt++;
				}
			}
		}
	}
	cout << ans << endl;
	//stop
	return 0;
}