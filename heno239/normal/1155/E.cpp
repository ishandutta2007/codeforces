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
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

const ll mn = 1000003;

ll inv[11];
ll mod_inverse(ll x, ll n = mn - 2) {
	ll ret = 1;
	while (n) {
		if (n % 2)ret = ret * x%mn;
		x = x * x%mn; n >>= 1;
	}
	return ret;
}
void solve() {
	vector<ll> y(11);
	rep(i, 11) {
		cout << "? "<<i << endl;
		cin >> y[i];
		//y[i] = i * i - 1;
		//if (y[i] < mn)y[i] += mn;
	}
	rep1(i, 10) {
		inv[i] = mod_inverse(i);
	}
	vector<ll> coef(11);
	rep(i, 11) {
		coef[i] = 1;
		rep(j, 11) {
			if (i == j)continue;
			ll dif = i - j; if (dif < 0)dif += mn;
			coef[i] = mod_inverse(dif) * coef[i] % mn;
		}
	}
	rep(i, mn) {
		ll sum = 0;
		rep(j, 11) {
			ll csum = y[j] * coef[j] % mn;
			rep(k, 11) {
				if (j == k)continue;
				ll dif = i - k;
				if (dif < 0)dif += mn;
				csum = csum * dif%mn;
			}
			sum += csum;
			//cout << y[j] << endl;
		}
		if (sum%mn == 0) {
			cout << "! " << i << endl; return;
		}
	}
	cout << "! " << -1 << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
		return 0;
}