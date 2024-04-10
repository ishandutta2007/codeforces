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
#include<cassert>
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-4;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
typedef vector<string> svec;

typedef vector<vector<ll>> mat;
typedef vector<ll> vec;
mat mtmul(mat &A, mat &B) {
	mat C(A.size(), vec(B[0].size()));
	rep(i, (int)A.size()) {
		rep(k, (int)B.size()) {
			rep(j, (int)B[0].size()) {
				C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % (mod-1)) % (mod-1);
			}
		}
	}
	return C;
}
mat mtpow(mat A, ll n) {
	mat B(A.size(), vec(A.size()));
	rep(i, (int)A.size()) {
		B[i][i] = 1;
	}
	while (n > 0) {
		if (n&(ll)1)B = mtmul(B, A);
		A = mtmul(A, A);
		n >>= 1;
	}
	return B;
}
ll mod_pow(ll x, ll n) {
	ll ret = 1;
	while (n > 0) {
		if (n % 2)ret = ret * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return ret;
}
void solve() {
	ll n, x, y, z, c; cin >> n >> x >> y >> z >> c;
	mat A = { {1,1,1},{1,0,0},{0,1,0} };
	A = mtpow(A,n - 3);
	ll t1 = A[0][2], t2 = A[0][1], t3 = A[0][0];
	x = x * c%mod;
	y = y * c%mod*c%mod;
	rep(i, 3)z = z * c%mod;
	ll pro = mod_pow(x, t1) % mod;
	pro = pro * mod_pow(y, t2) % mod;
	pro = pro * mod_pow(z, t3) % mod;
	ll inv = mod_pow(c, mod-2) % mod;
	inv = mod_pow(inv, n) % mod;
	pro = pro * inv%mod;
	cout << pro << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(11);
	/*while (cin >> n, n) {
		solve();
	}*/
	solve();
	//stop
	return 0;
}