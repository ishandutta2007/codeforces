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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = 998244353;
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
int n;
ll dp(int x) {
	ll res[501][501] = {};
	res[1][1] = 1;
	Rep(i,1, n) {
		rep1(j, x) {
			(res[i + 1][1] += res[i][j]) %= MOD;
			if (j < x) {
				(res[i + 1][j + 1] += res[i][j]) %= MOD;
			}
		}
	}
	ll res2 = 0;
	rep1(j, x) {
		(res2 += res[n][j]) %= MOD;
	}
	return res2;
}
ll sum[501];
ll cnt[501][501];
void init() {
	rep1(i, 500) {
		sum[i] = dp(i);
	}
	for(int i=500;i>1;i--){
	    sum[i]=(sum[i]-sum[i-1]+MOD)%MOD;
	}
	rep1(i, 500) {
		rep1(j, 500) {
			cnt[i][j] = (sum[i] * sum[j] % MOD)*(ll)2%MOD;
		}
	}
}
int main() {
	int k; cin >> n >> k;
	init();
	ll out = 0;
	rep1(i, n) {
		rep1(j, n) {
			if (i*j >= k)continue;
			(out += cnt[i][j]) %= MOD;
		}
	}
	cout << out << endl;
	return 0;
}