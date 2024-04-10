/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 301010
#define MOD 100000009
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var
vector<ll> v[MAX];
//

void solve() {
	srand(time(NULL));
	ll N;
	cin >> N;
	vector<ll> A, B, chk;
	A.resize(N + 1);
	B.resize(N + 1);
	chk.resize(N + 1);
	ll x;
	ll i;
	for (i = 1; i <= N; i++) v[i].clear();
	for (i = 1; i <= N; i++) cin >> x, v[x].push_back(i), A[i] = x;
	ll cnt = 0;
	for (i = 1; i <= N; i++) cnt += max((ll)v[i].size() - 1, 0LL);
	cout << N - cnt << ln;
	for (i = 1; i <= N; i++) B[i] = 0;
	for (i = 1; i <= N; i++) {
		if (!v[i].empty()) {
			for (auto x : v[i]) {
				B[x] = i;
				chk[i] = x;
				break;
			}
		}
	}
	vector<ll> both, X, Y;
	for (i = 1; i <= N; i++) {
		if ((!B[i]) && (!chk[i])) both.push_back(i);
		else if (!B[i]) X.push_back(i);
		else if (!chk[i]) Y.push_back(i);
	}
	if ((X.size() + Y.size() + both.size()) == 1) {
		ll asdf = both[0];
		B[chk[A[asdf]]] = asdf;
		chk[A[asdf]] = asdf;
		B[asdf] = A[asdf];
	}
	else {
		if (both.size() == 1){
			for (i = 0; i < X.size(); i++) B[X[i]] = Y[i];
			ll asdf = both[0];
			B[chk[A[asdf]]] = asdf;
			chk[A[asdf]] = asdf;
			B[asdf] = A[asdf];
		}
		else {
			for (i = 0; i < both.size(); i++) B[both[i]] = both[(i + 1) % both.size()];
			for (i = 0; i < X.size(); i++) B[X[i]] = Y[i];
		}
	}
	for (i = 1; i <= N; i++) cout << B[i] << bb;
	cout << ln;
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