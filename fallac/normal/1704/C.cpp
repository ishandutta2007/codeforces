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
typedef pair<int, int> pii;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 201010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

void solve() {
	int N;
	int M;
	cin >> N >> M;
	int i;
	vector<int> arr;
	int x;
	for (i = 1; i <= M; i++) {
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	vector<int> sub;
	for (i = 0; i < M - 1; i++) sub.push_back(arr[i + 1] - arr[i] - 1);
	sub.push_back(arr[0] + N - arr[M - 1] - 1);
	sort(sub.begin(), sub.end());
	reverse(sub.begin(), sub.end());
	int ans = 0;
	int t = 0;
	for (i = 0; i < M; i++) {
		if (sub[i] == t * 2 + 1) ans++, t++;
		else if (sub[i] == t * 2 + 2) ans++, t++;
		else if (sub[i] > 2 * t) {
			ans += sub[i] - t - t - 1;
			t += 2;
		}
	}
	cout << N - ans << Ln;
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