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

#define MAX 101010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll A[MAX];
ll B[MAX];

void solve() {
	int N;
	cin >> N;
	int i;
	for (i = 1; i <= N; i++) cin >> A[i];
	vector<ll> v1, v2;
	ll sum = 0;
	for (i = 1; i <= N; i++) {
		cin >> B[i];
		sum += B[i];
		if (A[i]) v1.push_back(B[i]);
		else v2.push_back(B[i]);
	}
	if (v1.size()) sort(v1.begin(), v1.end());
	if (v2.size()) sort(v2.begin(), v2.end());
	if (v1.size()) reverse(v1.begin(), v1.end());
	if (v2.size()) reverse(v2.begin(), v2.end());
	int a, b;
	a = v1.size();
	b = v2.size();
	if (a == b) {
		ll s1, s2;
		s1 = s2 = 0;
		for (i = 0; i < a - 1; i++) s1 += v1[i], s1 += v2[i];
		s2 = s1;
		s1 += v1[a - 1];
		s2 += v2[a - 1];
		cout << sum + max(s1, s2) << ln;
	}
	else {
		for (i = 0; i < min(a, b); i++) sum += v1[i];
		for (i = 0; i < min(a, b); i++) sum += v2[i];
		cout << sum << ln;
	}
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