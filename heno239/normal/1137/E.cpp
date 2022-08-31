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
typedef long double ld;
const ld INF = (ld)10000000000000;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
ll n; int m;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	vector<ll> v; v.push_back(0);
	vector<ll> u; u.push_back(n);
	vector<ll> z; z.push_back(0);

	ll rsum = 0;

	ll sum = 0;
	int le = 0;
	rep(i, m) {
		int t; cin >> t;
		if (t == 1) {
			ll l; cin >> l;
			ll len = v[v.size() - 1] + u[v.size() - 1];
			v.clear(); u.clear(); z.clear();
			v.push_back(0); u.push_back(len + l); z.push_back(0);
			rsum = 0; sum = 0; le = 0;
			cout << "1 0" << endl;
		}
		else if (t == 2) {
			ll k; cin >> k;
			if (sum + z[v.size() - 1] + rsum * v[v.size() - 1] == 0) {
				u[v.size() - 1] += k;
			}
			else {
				ll loc = v[v.size() - 1] + u[v.size() - 1];
				v.push_back(loc);
				u.push_back(k);
				z.push_back(-sum - rsum * v[v.size() - 1]);
			}
			while (v.size() - le >= 2) {
				if (z[le] + rsum * v[le] <= z[le + 1] + rsum * v[le + 1]) {
					v[le + 1] = v[le]; u[le + 1] += u[le]; z[le + 1] = z[le];
					le++;
				}
				else break;
			}
			while (v.size() - le >= 3) {
				ll a1 = v[le + 2], b1 = z[le + 2];
				ll a2 = v[le + 1], b2 = z[le + 1];
				ll a3 = v[le], b3 = z[le];
				if ((a2 - a1)*(b3 - b2) >= (b2 - b1)*(a3 - a2)) {
					v[le + 1] = v[le]; u[le + 1] += u[le]; z[le + 1] = z[le];
					le++;
				}
				else break;
			}
			while (v.size() - le >= 3) {
				int len = v.size();
				ll a1 = v[len - 1], b1 = z[len - 1];
				ll a2 = v[len - 2], b2 = z[len - 2];
				ll a3 = v[len - 3], b3 = z[len - 3];
				if ((a2 - a1)*(b3 - b2) >= (b2 - b1)*(a3 - a2)) {
					u[len - 3] += u[len - 2];
					v[len - 2] = v[len - 1];
					u[len - 2] = u[len - 1];
					z[len - 2] = z[len - 1];
					v.pop_back(); u.pop_back(); z.pop_back();
				}
				else break;
			}
			while (v.size() - le >= 2) {
				int len = v.size();
				if (z[len - 2] + rsum * v[len - 2] <= z[len - 1] + rsum * v[len - 1]) {
					u[len - 2] += u[len - 1];
					v.pop_back(); u.pop_back(); z.pop_back();
				}
				else break;
			}
			cout << v[v.size() - 1] + 1 << " " << sum + z[v.size() - 1] + rsum * v[v.size() - 1] << endl;
		}
		else {
			ll b, s; cin >> b >> s; sum += b; rsum += s;
			while (v.size() - le >= 2) {
				if (z[le] + rsum * v[le] <= z[le + 1] + rsum * v[le + 1]) {
					v[le + 1] = v[le]; u[le + 1] += u[le]; z[le + 1] = z[le];
					le++;
				}
				else break;
			}
			while (v.size() - le >= 3) {
				ll a1 = v[le+2], b1 = z[le+2];
				ll a2 = v[le+1], b2 = z[le+1];
				ll a3 = v[le], b3 = z[le];
				if ((a2 - a1)*(b3 - b2) >= (b2 - b1)*(a3 - a2)) {
					v[le + 1] = v[le]; u[le + 1] += u[le]; z[le + 1] = z[le];
					le++;
				}
				else break;
			}
			while (v.size() - le >= 3) {
				int len = v.size();
				ll a1 = v[len - 1], b1 = z[len - 1];
				ll a2 = v[len - 2], b2 = z[len - 2];
				ll a3 = v[len - 3], b3 = z[len - 3];
				if ((a2 - a1)*(b3 - b2) >= (b2 - b1)*(a3 - a2)) {
					u[len - 3] += u[len - 2];
					v[len - 2] = v[len - 1];
					u[len - 2] = u[len - 1];
					z[len - 2] = z[len - 1];
					v.pop_back(); u.pop_back(); z.pop_back();
				}
				else break;
			}
			while (v.size() - le >= 2) {
				int len = v.size();
				if (z[len - 2] + rsum * v[len - 2] <= z[len - 1] + rsum * v[len - 1]) {
					u[len - 2] += u[len - 1];
					v.pop_back(); u.pop_back(); z.pop_back();
				}
				else break;
			}
			cout << v[v.size() - 1] + 1 << " " << sum + z[v.size() - 1] + rsum * v[v.size() - 1] << endl;
		}
	}
	//stop
	return 0;
}