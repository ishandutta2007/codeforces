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

vector<int> A, B, C, D;

int N;

int query(vector<int>& v) {
	int cnt = 0;
	for (auto x : v) if (x <= N) cnt++;
	if (cnt == 0) return 0;
	cout << "? ";
	cout << cnt << bb;
	for (auto x : v) if (x <= N) cout << x << bb;
	cout << endl;
	string res;
	cin >> res;
	return res == yes;
}

int query(vector<int> v1, vector<int> v2) {
	for (auto v : v2) v1.push_back(v);
	return query(v1);
}

void f(vector<int>& X, vector<int>& Y, vector<int>& A, vector<int>& B) {
	X.clear();
	Y.clear();
	while (A.size() > X.size()) X.push_back(A.back()), A.pop_back();
	while (B.size() > Y.size()) Y.push_back(B.back()), B.pop_back();
}

void solve() {
	cin >> N;
	int i;
	int NN = (N + 3) / 4 * 4;
	for (i = 1; i <= NN / 4; i++) A.push_back(i);
	for (i = NN / 4 + 1; i <= NN / 2; i++) B.push_back(i);
	for (i = NN / 2 + 1; i <= NN / 4 * 3; i++) C.push_back(i);
	for (i = NN / 4 * 3 + 1; i <= NN; i++) D.push_back(i);
	while (A.size() + B.size() + C.size() + D.size() > 2) {
		int p, q, r, s;
		p = query(A, C);
		q = query(A, B);
		r = query(A, B);
		s = query(D, B);
		if (q + r == 1) {
			if (r) {
				swap(A, B);
				swap(C, D);
				swap(q, r);
				swap(p, s);
			}
			if (p && s) f(A, D, B, C);
			if (p && !s) f(B, D, A, C);
			if (!p && s) f(A, C, B, D);
			if (!p && !s) f(B, C, A, D);
		}
		else if (q + r == 0) f(A, B, C, D); // not a && not b
		else f(C, D, A, B); //a or b
	}
	for (auto v : B) A.push_back(v);
	for (auto v : C) A.push_back(v);
	for (auto v : D) A.push_back(v);
	while (1) {
		while (A.back() > N) A.pop_back();
		if (A.empty()) {
			cout << "wa:(";
			return;
		}
		cout << "! " << A.back() << endl;
		string res;
		cin >> res;
		if (res == ":)") return;
		else {
			if (A.empty()) {
				cout << "wa:(";
				return;
			}
			A.pop_back();
		}
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