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
#include<complex>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;
typedef pair<int, bool> sP;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

const int sz = 2000000;
bool isp[sz+1];

void init() {
	fill(isp + 2, isp + sz + 1, true);
	for (int i = 2; i <= sz; i++) {
		if (!isp[i])continue;
		for (int j = 2 * i; j <= sz; j += i)isp[j] = false;
	}
}
bool ispain(int x) {
	string s = to_string(x);
	int len = s.size();
	rep(i, len/2) {
		if (s[i] != s[len - 1 - i])return false;
	}
	return true;
}
void solve() {
	int ans = 0;
	int n = 1;
	ll p, q; cin >> p >> q;
	int pn=0;
	int cnt = 0;
	for(int n=1;n<=sz;n++){
		if (isp[n])pn++;
		if (ispain(n))cnt++;
		if (q*pn <= p * cnt) {
			ans = n;
		}
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(9);
	init();
	solve();
	//stop
	return 0;
}