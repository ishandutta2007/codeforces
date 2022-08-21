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
string s[70000]; int n;
vector<string> u[70000];
map<string, int> mp;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) {
		cin >> s[i];
		rep(j, 9) {
			Rep(k, j, 9) {
				string z = s[i].substr(j, k - j + 1);
				mp[z]++;
				u[i].push_back(z);
			}
		}
		sort(u[i].begin(), u[i].end());
	}
	rep(i, n) {
		int ma = 10; string ans;
		rep(j, u[i].size()) {
			int c = 1;
			string cur = u[i][j];
			while (j + 1 < u[i].size() && u[i][j] == u[i][j + 1]) {
				c++; j++;
			}
			int cc = mp[cur];
			if (c == cc) {
				if (ma > cur.size()) {
					ma = cur.size(); ans = cur;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}