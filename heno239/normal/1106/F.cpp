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
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;

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
ll mod_pow(ll a, ll n, ll m) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%m;
		n >>= 1; a = a * a%m;
	}
	return res;
}
//a^xb(mod p)x,-1
ll baby_step_giant_step_algorithm(ll a,ll b,ll p) {
	ll res = -1;
	ll rp = sqrt(p) + 1;
	map<ll, bool> exi;
	map<ll, ll> num;
	ll t = mod_pow(a, rp, p);
	ll z = 1;
	rep(i, rp) {
		exi[z] = true; num[z] = i;
		z = z * t%p;
	}
	z = b * mod_pow(a, p - rp, p) % p;
	per(i, rp) {
		if (exi[z]) {
			res = rp * num[z] + i;
			break;
		}
		z = z * a%p;
	}
	return res;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int k; cin >> k;
	mat A;
	vector<ll> b; b.resize(k);
	rep(i, k) {
		cin >> b[i];
	}
	A.push_back(b);
	rep1(i, k - 1) {
		vector<ll> v;
		rep(j, k) {
			if (i - j == 1) {
				v.push_back(1);
			}
			else v.push_back(0);
		}
		A.push_back(v);
	}
	ll n, m; cin >> n >> m;
	A = mtpow(A, n-k);
	ll sum = A[0][0];
	ll x = mod_pow(3, sum, mod);
	ll y = m;
	ll z = baby_step_giant_step_algorithm(x, y, mod);
	if (z < 0) {
		cout << -1 << endl;
	}
	else {
		cout << mod_pow(3, z, mod) << endl;
	}
	//stop
	return 0;
}