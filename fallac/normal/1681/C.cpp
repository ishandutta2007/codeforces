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

#define MAX 301010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

pii arr[MAX];
int A[MAX];
int B[MAX];
pii ans[MAX];

void solve() {
	int N;
	cin >> N;
	int i;
	for (i = 1; i <= N; i++) cin >> A[i], arr[i].first = A[i];
	for (i = 1; i <= N; i++) cin >> B[i], arr[i].second = B[i];
	sort(A + 1, A + N + 1);
	sort(B + 1, B + N + 1);
	for (i = 1; i <= N; i++) ans[i] = { A[i], B[i] };
	vector<pii> vpi;
	int j;
	while (1) {
		int diff = -1;
		for (i = 1; i <= N; i++) {
			if (arr[i] != ans[i]) {
				diff = i;
				break;;
			}
		}
		if (diff == -1) break;
		int loc = -1;
		for (j = diff + 1; j <= N; j++) {
			if (ans[diff] == arr[j]) {
				loc = j;
				continue;
			}
		}
		if (loc == -1) {
			cout << -1 << ln;
			return;
		}
		swap(arr[diff], arr[loc]);
		vpi.emplace_back(diff, loc);
	}
	cout << vpi.size() << ln;
	for (auto x : vpi) cout << x.first << bb << x.second << ln;

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