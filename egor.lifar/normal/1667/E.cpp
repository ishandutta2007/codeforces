#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2> inline bool chkmin(T1 &a, T2 b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<typename T1, typename T2> inline bool chkmax(T1 &a, T2 b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const int MOD = 998244353;


int sum(int a, int b) {
	return (a + b >= MOD ? a + b - MOD: a + b); 
}

int mul(int a, int b) {
	return ((ll)a * b) % MOD;
}


int powm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		b >>= 1;
		a = mul(a, a);
	}
	return res;
}


int rev[300000 * 4];
const int G = 3;



void FFT(vector<ll> &a,int n,ll op){
    for (int i=0;i<n;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
    for (int i=1;i<n;i<<=1){
        ll wn=powm(G,(MOD-1)/i>>1);
        if (op) wn=powm(wn,MOD-2);
        for (int j=0;j<n;j+=i<<1){
            ll w=1;
            for (int k=j;k<j+i;k++,w=1ll*w*wn%MOD){
                ll x=a[k],y=1ll*w*a[k+i]%MOD;
                a[k]=(x+y)%MOD;a[k+i]=(x-y + MOD)%MOD;
            }
        }
    }
    if (op){
        ll invn=powm(n,MOD-2);
        for (int i=0;i<n;i++) a[i]=1ll*a[i]*invn%MOD;
    }
}

vector<ll> multiply(vector<ll> a, vector<ll> b) {
    int n = max(sz(a), sz(b));
    int ns=1,len=0,m=n * 2;
    for (;ns<=m;len++) ns<<=1;
    for (int i=1;i<ns;i++) {
        rev[i]=rev[i>>1]>>1^((i&1)<<(len-1));
    }
    a.resize(ns);
    b.resize(ns);
    FFT(a,ns,0);
    FFT(b,ns,0);
    for (int i=0;i<ns;i++) a[i] = mul(a[i], b[i]);
    FFT(a,ns,1);
    return a;
}


const int MAXN = 300228;

int n;
int fact[MAXN];
int facti[MAXN];
int ans[MAXN];
int a[MAXN];
int b[MAXN];



void solve() {
	cin >> n;
	fact[0] = 1;
	for (int i = 1; i <= n + 1; i++) {
		fact[i] = mul(fact[i - 1], i);
	}
	facti[n + 1] = powm(fact[n + 1], MOD - 2);
	for (int i = n; i >= 0; i--) {
		facti[i] = mul(facti[i + 1], i + 1);
	}
	vector<ll> a;
	a.resize(n + 2);
	for (int k = n / 2 + 1; k <= n; k++) {
		a[n - k] = (n - k - 1 < 0 ? 1: fact[n - k - 1]);
	}
	vector<ll> b;
	b.resize(n + 2);
	for (int i = 1; i <= n + 1; i++) {
		b[i] = facti[n - i + 1];
	}
	auto val = multiply(a, b);
	int rs = 0;
	//cout << a[0] << ' ' << b[4] << endl;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			if (1 + n == i + j) {
				//cout << i << ' '  << j << endl;
				rs = sum(rs, mul(a[i], b[j]));
				//cout << rs << endl;
			}
		}
	}
//	cout << rs << endl;
	int sub = 0;
	for (int i = n; i >= 1; i--) {
		// k >= n / 2 + 1
		//C(n - i, k - 1) * (k - 1)! * i * (n - k - 1)!
		//(n - i)! / (n - i - k + 1)! * i * (n - k - 1)!
		//(n - k - 1)! / (n - i - k + 1)!
		//a[n - k - 1] = (n - k - 1)!
		//b[k + i] = 1 / (n - (k + i) + 1)!
		//i + j
		//i! / (n - j + 1)!
		//i = n - k - 1
		//k = n - i - 1
		//j - (n - i - 1) = target
		//j + i - n + 1 = target
		//j + i = target + n - 1
		if (n - i >= n / 2) {
			// int kek = 0;
			// for (int k = n / 2 + 1; k <= n - i + 1; k++) {
			// 	if (i == 1 && k != n) {
			// 		continue;
			// 	}
			// 	// if (i == 1) {
			// 	// 	cout << n - k << ' ' << i + k << endl;
			// 	// 	cout << fact[n - k - 1] << ' ' << facti[n - i - k + 1] << endl;
			// 	// }
			// 	kek = sum(kek, mul((n - k - 1 < 0 ? 1: fact[n - k - 1]), facti[n - i - k + 1]));
			// }
		//	cout << mul(val[i + n], mul(fact[n - i], max(1, i - 1))) << endl;
			// if (i == 1) {
			// 	val[i + n] = fact[n - 1];
			// }
			int rofl = (i == 1 ? fact[n - 1]: mul(val[i + n], mul(fact[n - i], max(1, i - 1))));
			ans[i] = sum(rofl, MOD - sub);
			sub = sum(sub, mul(rofl, powm(i - 1, MOD - 2))); 
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}


int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	t = 1;
	//cin >> t;
	while (t--) {
	//	cerr << t << endl;
		solve();
	}
}