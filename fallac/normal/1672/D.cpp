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

//var

//

void solve() {
	int N;
	cin >> N;
	int i;
	vector<int> A(N), B(N);
	int v;
	vector<int> st;
	vector<int> dlist(N + 1);
	for (i = 0; i < N; i++) cin >> A[i], st.push_back(A[i]);
	for (i = 0; i < N; i++) cin >> B[i];
	int pv = -1;
	for (i = N - 1; i >= 0; i--) {
		if (st.back() == B[i]) st.pop_back();
		else {
			int x;
			if (pv == B[i]) dlist[pv]++;
			else {
				while (1) {
					if (st.back() == B[i]) break;
					if (st.size() && dlist[st.back()]) dlist[st.back()]--, st.pop_back();
					else {
						cout << no << ln;
						return;
					}
				}
				st.pop_back();
			}
		}
		pv = B[i];
	}
	cout << yes << ln;
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