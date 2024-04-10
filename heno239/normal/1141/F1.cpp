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
const ll INF = 1e+14;
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

int n;
int a[1500];
int ra[1501];
map<int, int> mp;
void solve() {
	cin >> n;
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		ra[i + 1] = ra[i] + a[i];
	}
	vector<int> v;
	rep(i, n) {
		Rep1(j, i + 1, n) {
			int s = ra[j] - ra[i];
			v.push_back(s);
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	rep(i, v.size()) {
		mp[v[i]] = i;
	}
	vector<vector<P>> u(v.size());
	rep(i, n) {
		Rep1(j, i + 1, n) {
			int s = ra[j] - ra[i];
			int id = mp[s];
			//cout << i << " " << j << " " << s << endl;
			u[id].push_back({ j - 1,i });
		}
	}
	int ans = 0;
	vector<P> out;
	rep(i, u.size()) {
		//cout << v[i]<<"hel" << endl;
		vector<P> z;
		sort(u[i].begin(), u[i].end());
		int le = -1;
		rep(j, u[i].size()) {
			//cout << le << " " << u[i][j].second + 1 << " " << u[i][j].first+1 << endl;
			if (u[i][j].second < le)continue;
			z.push_back(u[i][j]);
			le = u[i][j].first + 1;
			//cout << le << endl;
		}
		if (z.size() > ans) {
			ans = z.size();
			out = z;
		}
	}
	cout << ans << endl;
	rep(i, ans) {
		cout << out[i].second + 1 << " " << out[i].first+1 << endl;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	//stop
	return 0;
}