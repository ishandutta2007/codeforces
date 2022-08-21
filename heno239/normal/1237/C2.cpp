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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000087;
const ll INF = mod * mod;
typedef pair<int, int>P;
typedef pair<int, bool> sP;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;


void solve() {
	int n; cin >> n;
	vector <vector<int>> v(n);
	rep(i, n) {
		v[i].resize(4);
		rep(j, 3)cin >> v[i][j];
		v[i][3] = i + 1;
	}
	sort(v.begin(), v.end());

	vector<int> ids;
	vector<P> ans;
	rep(i, n) {
		vector<vector<int>> u;
		u.push_back({ v[i][1],v[i][2],v[i][3] });
		while (i + 1 < n&&v[i][0] == v[i + 1][0]) {
			i++;
			u.push_back({ v[i][1],v[i][2],v[i][3] });
		}
		/*if (u.size() % 2) {
			ids.push_back(u.back()[2]);
			u.pop_back();
		}*/
		int len = u.size();
		vector<int> ids2;
		rep(j, len) {
			vector<P> z;
			z.push_back({ u[j][1],u[j][2] });
			while (j + 1 < len&&u[j][0] == u[j + 1][0]) {
				j++;
				z.push_back({ u[j][1],u[j][2] });
			}
			if (z.size() % 2) {
				ids2.push_back(z.back().second);
				z.pop_back();
			}
			int len2 = z.size();
			int mid = len2 / 2;
			rep(k, mid) {
				ans.push_back({ z[mid - 1 - k].second,z[mid + k].second });
			}
		}
		if (ids2.size() % 2) {
			ids.push_back(ids2.back());
			ids2.pop_back();
		}
		len = ids2.size();
		int mid = len / 2;
		rep(j, mid) {
			ans.push_back({ ids2[mid - 1 - j],ids2[mid + j] });
		}
	}
	int len = ids.size();
	int mid = len / 2;
	rep(j, mid) {
		ans.push_back({ ids[mid - 1 - j],ids[mid + j] });
	}
	rep(i, n / 2) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}

}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	solve();
	//stop
	return 0;
}