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

void solve() {
	ll N, Q;
	cin >> N >> Q;
	ll i;
	string s;
	cin >> s;
	vector<ll> arr(N);
	ll cnt = 0;
	for (i = 2; i < N; i++) {
		if (s[i - 2] == 'a' && s[i - 1] == 'b' && s[i] == 'c') arr[i - 2] = arr[i - 1] = arr[i] = 1, cnt++;
	}
	ll a;
	char b;
	for (i = 1; i <= Q; i++) {
		cin >> a >> b;
		a--;
		if (arr[a] == 1) {
			if (s[a] != b) {
				if (s[a] == 'a') arr[a] = arr[a + 1] = arr[a + 2] = 0, cnt--;
				if (s[a] == 'b') arr[a] = arr[a + 1] = arr[a - 1] = 0, cnt--;
				if (s[a] == 'c') arr[a] = arr[a - 1] = arr[a - 2] = 0, cnt--;
			}
		}
			if (s[a] != b) {
				if ((a > 1) && b == 'c' && s[a - 1] == 'b' && s[a - 2] == 'a') arr[a - 2] = arr[a - 1] = arr[a] = 1, cnt++;
				if (a + 1 < N && (a > 0) && b == 'b' && s[a - 1] == 'a' && s[a + 1] == 'c') arr[a - 1] = arr[a + 1] = arr[a] = 1, cnt++;
				if (a + 2 < N && b == 'a' && s[a + 1] == 'b' && s[a + 2] == 'c') arr[a + 2] = arr[a + 1] = arr[a] = 1, cnt++;
			}
		s[a] = b;
		cout << cnt << ln;
	}
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	omode;
	while (T--) {
		init();
		solve();
	}
}