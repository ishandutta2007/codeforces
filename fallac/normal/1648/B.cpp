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

#define MAX 1010100
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

int arr[MAX];
int psum[MAX];
int N, C;
bool chk(ll l, ll r) {
	if (r > C) r = C;
	if (l > r) return false;
	return psum[r] - psum[l - 1];
}

void solve() {
	cin >> N >> C;
	int i;
	set<int> st;
	vector<int> arr(N);
	for (i = 0; i < N; i++) {
		cin >> arr[i];
		st.insert(arr[i]);
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	N = arr.size();
	arr.insert(arr.begin(), 0);
	for (i = 1; i <= C; i++) psum[i] = 0;
	for (i = 1; i <= N; i++) psum[arr[i]]++;
	for (i = 1; i <= C + 1; i++) psum[i] += psum[i - 1];
	psum[C + 1] = 0;
	int j;
	for (i = 1; i <= C; i++) {
		if (!chk(i, i)) {
			for (j = 1; j <= N; j++) {
				if (chk((ll)i * (ll)arr[j], (ll)(i + 1) * (ll)arr[j] - 1)) {
					cout << "No" << ln;
					return;
				}
				if ((ll)i * (ll)arr[j] > C) break;
			}
		}
	}
	cout << "Yes" << ln;

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