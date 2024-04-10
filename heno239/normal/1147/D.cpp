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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;


bool used[1000];
void solve() {
	string s; cin >> s;
	int n = s.length();
	if (s[n - 1] == '1') {
		cout << 0 << endl; return;
	}
	s[n - 1] = '0';
	ll ans = 0;
	rep1(i, n - 1) {
		ll csum = 1;
		fill(used, used + n, false);
		//cout << "hello ";
		//cout << i << endl;
		//cout << ans << endl;
		rep(j, i) {
			if (used[j])continue;
			LP dp= { 0,0 };
			if (s[j] != '0') {
				dp.second = 1;
			}
			if(s[j]!='1') {
				dp.first = 1;
			}
			int id = 0;
			int cur = j;
			used[cur] = true;
			while (true) {
				if (id == 0) {
					int nex = n-1-cur;
					if (used[nex])break;
					if (nex < i) {
						if (s[nex] == '0') {
							dp.second = 0;
						}
						if (s[nex] == '1') {
							dp.first = 0;
						}
						used[nex] = true; break;
					}
					used[nex] = true;
					cur = nex;
					LP nexdp = { 0,0 };
					//xor0
					if (s[cur] != '1') {
						nexdp.first += dp.first;
						nexdp.second += dp.second;
					}
					//xor1
					if (s[cur] != '0') {
						nexdp.first += dp.second;
						nexdp.second += dp.first;
					}
					if (nexdp.first >= mod)nexdp.first -= mod;
					if (nexdp.second >= mod)nexdp.second -= mod;
					dp = nexdp;
					id ^= 1;
				}
				else {
					int nex = i + n - 1 - cur;
					if (used[nex])break;
					used[nex] = true;
					cur = nex;
					LP nexdp = { 0,0 };
					//xor0
					if (s[cur] != '1') {
						nexdp.first += dp.first;
						nexdp.second += dp.second;
					}
					//xor1
					if (s[cur] != '0') {
						nexdp.first += dp.second;
						nexdp.second += dp.first;
					}
					if (nexdp.first >= mod)nexdp.first -= mod;
					if (nexdp.second >= mod)nexdp.second -= mod;
					dp = nexdp;
					id ^= 1;
				}
			}
			csum = csum * (dp.first + dp.second) % mod;
			//cout << j << " " << dp.first << " " << dp.second << endl;
		}
		ans = (ans + csum) % mod;
		//cout << ans << endl;
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}