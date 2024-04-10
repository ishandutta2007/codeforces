/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 101010
//#define MOD 1000000007
ll MOD;
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "Yes"
#define no "No"



void solve() {
	ll N;
	cin >> N;
	ll i;
	vector<ll> X, Y;
	X.resize(N + 1);
	Y.resize(N + 1);
	ll prev = 0;
	for (i = 1; i <= N; i++) {
		cin >> X[i];
		Y[i] = (prev & X[i]) ^ prev;
		prev = X[i] ^ Y[i];
	}
	for (i = 1; i <= N; i++) cout << Y[i] << ln;
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