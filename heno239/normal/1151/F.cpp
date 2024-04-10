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


typedef vector<vector<ll>> mat;
typedef vector<ll> vec;
mat mtmul(mat &A, mat &B) {
	mat C(A.size(), vec(B[0].size()));
	rep(i, (int)A.size()) {
		rep(k, (int)B.size()) {
			rep(j, (int)B[0].size()) {
				C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % mod) % mod;
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
ll mod_pow(ll x, ll n = mod - 2) {
	ll ret = 1;
	while (n) {
		if (n % 2)ret = ret * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return ret;
}
void solve() {
	mat A;
	int n, k; cin >> n >> k;
	int c[2] = {};
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		if (a[i])c[1]++;
		else c[0]++;
	}
	ll z = n * (n - 1) / 2;
	z = mod_pow(z);
	ll b = c[0] * (c[0]-1)/2 + c[1] * (c[1]-1)/2;
	int sz = min(c[0],c[1]) + 1;
	A.resize(sz); rep(i, sz)A[i].resize(sz,0);
	rep(i, sz) {
		A[i][i] = b + i * (c[1] - i) + (c[0] - i)*i;
		A[i][i] = A[i][i] * z%mod;
		if (i > 0) {
			A[i][i - 1] = (c[0]-i+1)*(c[1]-i+1) % mod*z%mod;
		}
		if (i+1 < sz) {
			A[i][i + 1] = (i+1)*(i+1) % mod*z%mod;
		}
	}
	/*rep(i, A.size()) {
		rep(j, A[i].size()) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}*/
	A = mtpow(A, k);
	int num = 0;
	rep(i, n) {
		if (i < c[0] && a[i])num++;
	}
	cout << A[0][num] << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}