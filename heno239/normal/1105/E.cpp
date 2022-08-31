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
const ld eps = 1e-9;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
map<string, int> mp;
int n, m;
vector<int> v;
int ev[1 << 17]; int id[1 << 17];
int ban[40][40];

int num[1 << 20];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int cur = 1;
	rep(i, n) {
		cin >> ev[i];
		if (ev[i] == 1) {
			v.push_back(i);
		}
		else {
			string in; cin >> in;
			if (mp[in]) {
				id[i] = mp[in];
			}
			else {
				id[i] = mp[in] = cur;
				cur++;
			}
		}
	}
	v.push_back(n);
	rep(i, v.size() - 1) {
		vector<int> u;
		Rep1(j, v[i] + 1, v[i + 1] - 1) {
			u.push_back(id[j]);
		}
		sort(u.begin(), u.end());
		int len = unique(u.begin(), u.end()) - u.begin();
		rep(j, len) {
			Rep(k, j + 1, len) {
				ban[u[j]-1][u[k]-1] = true;
			}
		}
	}
	int d1 = m / 2;
	int d2 = m - d1;
	rep(i, (1 << d2)) {
		if (i == 0) {
			num[i] = 0; continue;
		}
		vector<int> v;
		rep(j, d2) {
			if (i&(1 << j)) {
				v.push_back(j);
			}
		}
		bool f = true;
		rep(j, v.size()) {
			Rep(k, j + 1,v.size()) {
				if (ban[d1+v[j]][d1+v[k]])f = false;
			}
		}
		if (f)num[i] = v.size();
		else {
			rep(j, v.size()) {
				int x = i ^ (1 << v[j]);
				num[i] = max(num[i], num[x]);
			}
		}
	}
	int ans = 0;
	rep(i, (1 << d1)) {
		vector<int> v;
		rep(j, d1) {
			if (i&(1 << j)) {
				v.push_back(j);
			}
		}
		bool f = true;
		rep(j, v.size()) {
			Rep(k, j + 1, v.size()) {
				if (ban[v[j]][v[k]])f = false;
			}
		}
		if (!f)continue;
		int r = 0;
		rep(j, v.size()) {
			Rep(k, d1, m) {
				if (ban[v[j]][k]) {
					r |= (1 << (k - d1));
				}
			}
		}
		r = (1 << d2) - 1 - r;
		ans = max(ans, (int)v.size() + num[r]);
	}
	cout << ans << endl;
	//stop
	return 0;
}