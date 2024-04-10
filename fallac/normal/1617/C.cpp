/*

*/

#include <bits/stdc++.h>
#include <cassert>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 101010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll query(ll a, ll b, ll c) {
	a++;
	b++;
	c++;
	cout << '?' << bb << a << bb << b << bb << c << endl;
	ll x;
	cin >> x;
	return !x;
}

void solve() {
	ll N;
	cin >> N;
	vector<ll> arr, chk;
	chk.resize(N + 5);
	ll i;
	ll a;
	ll cnt = 0;
	for (i = 1; i <= N; i++) {
		cin >> a;
		if (a <= N && !chk[a]) chk[a] = 1;
		else arr.push_back(a);
	}
	vector<ll> rem;
	sort(arr.begin(), arr.end());
	for (i = 1; i <= N; i++) if (!chk[i]) rem.push_back(i);
	for (i = 0; i < rem.size(); i++) {
		if (rem[i] * 2 >= arr[i]) {
			cout << -1 << ln;
			return;
		}
	}
	cout << rem.size() << Ln;
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		init();
		solve();
	}
}