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
const ll mod = (1e+9) + 7;
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
const ld eps = 1e-4;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int s[1002];
map<string,int> mp;
map<int, string> inv;
typedef pair<string, int> speP;
speP ss[1001];
int atl[1001];
int main() {
	int n; cin >> n;
	int now = 1;
	rep(i, n) {
		string t; int k; cin >> t >> k;
		ss[i] = { t,k };
		if (!mp[t]) {
			inv[now] = t;
			mp[t] = now; now++;
		}
		int id = mp[t];
		s[id] += k;
	}
	vector<int> v;
	int ma = -(int)mod;
	Rep(i,1, now) {
		ma = max(ma, s[i]);
	}
	Rep(i, 1,now) {
		if (s[i] == ma) {
			v.push_back(i);
		}
		s[i] = 0;
		atl[i] = 10000;
	}
	rep(i, n) {
		string t = ss[i].first; int k = ss[i].second;
		int id = mp[t];
		s[id] += k;
		if (s[id] >= ma) {
			atl[id] = min(atl[id], i);
		}
	}
	int chk; int mi = 10000;
	rep(i, (int)v.size()) {
		int id = v[i];
		if (atl[id] < mi) {
			chk = id; mi = atl[id];
		}
	}
	cout << inv[chk] << endl;
	return 0;
}