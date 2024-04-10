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
const ld eps = 1e-2;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

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

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, m; cin >> n >> m;
	if (m > n) {
		cout << 1 << endl; return 0;
	}
	mat A; A.resize(m);
	rep(i, m) {
		A[i].resize(m,0);
		if (i == 0) {
			A[i][0] = A[i][m - 1] = 1;
		}
		else {
			rep(j, m) {
				if (i - j == 1)A[i][j] = 1;
			}
		}
	}
	A = mtpow(A, n - m+1);
	ll ans = 0;
	rep(i, m) {
		ans = (ans + A[0][i]) % mod;
	}
	cout << ans << endl;
	//stop
	return 0;
}