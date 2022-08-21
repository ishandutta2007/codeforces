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
const ll mod = 998244353;
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
const ld eps = 1e-2;
const ld pi = acos(-1.0);
ll t10[19];
int k;
void init() {
	t10[0] = 1;
	rep(i, 18) {
		t10[i+1] = t10[i] * 10;
	}
}
bool used[19]; int val[19];
bool chk[19][1024][2];
ll ans[19][1024][2];
ll onecalc(ll x,int id,int s,bool f) {
	if (chk[id][s][f])return ans[id][s][f];
	chk[id][s][f] = true;
	int cnt = 0;
	rep(i, 10) {
		if (s&(1 << i))cnt++;
	}
	if (cnt > k)return ans[id][s][f]=0;
	if (id == 0)return ans[id][s][f] = 1;

	ll u = (x%t10[id]) / t10[id - 1];
	if (used[id]) {
		int z = val[id];
		if (f) {
			if (z > u)return ans[id][s][f] = 0;
			else if (z == u)return ans[id][s][f] = onecalc(x, id - 1, s | (1 << z), f);
			else return ans[id][s][f] = onecalc(x, id - 1, s | (1 << z), false);
		}
		else return ans[id][s][f] = onecalc(x, id - 1, s | (1 << z), false);
	}
	else {
		ll res = 0;
		if (f) {
			if (u != 0) {
				if (s == 0)res = (res + onecalc(x, id - 1, s, false)) % mod;
				else res = (res + onecalc(x, id - 1, s|1, false)) % mod;
			}
			else if(s==0)res = (res + onecalc(x, id - 1, s, true)) % mod;
			else {
				res = (res + onecalc(x, id - 1, s|1, true)) % mod;
			}
			rep1(i, u-1) {
				int ns = s | (1 << i);
				res = (res + onecalc(x, id - 1, ns, false)) % mod;
			}
			if(u!=0)res = (res + onecalc(x, id - 1, s | (1 << u), true)) % mod;
		}
		else {
			if (s == 0) {
				res = (res + onecalc(x, id - 1, 0, false)) % mod;
			}
			else {
				res = (res + onecalc(x, id - 1, s|1, false)) % mod;
			}
			rep1(i, 9) {
				int ns = s | (1 << i);
				res = (res + onecalc(x, id - 1, ns, false)) % mod;
			}
		}
		return ans[id][s][f] = res;
	}
}
void set_up(int id,int v) {
	rep(i, 19) {
		used[i] = false;
		rep(j, 1024) {
			rep(l, 2) {
				chk[i][j][l] = false;
				ans[i][j][l] = 0;
			}
		}
	}
	used[id] = true; val[id] = v;
}
ll calc(ll x) {
	ll ret = 0;
	rep1(i, 18) {
		rep(j, 10) {
			set_up(i, j);
			//cout << i << " " << j << " " << onecalc(x, 18, 0, true) << endl;
			ret = (ret + t10[i-1]%mod*onecalc(x, 18, 0, true)%mod*j) % mod;
		}
	}
	return ret;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	init();
	ll l, r; cin >> l >> r >> k;
	cout << (calc(r) - calc(l - 1) + mod) % mod << endl;
	//stop
	return 0;
}