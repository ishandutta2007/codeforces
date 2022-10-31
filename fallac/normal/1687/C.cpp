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
typedef pair<ll, ll> pii;

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

ll C[MAX];
pii range[MAX];
ll chk[MAX];
ll removed[MAX];
vector<ll> st[MAX];
vector<ll> en[MAX];

queue<ll> q;
set<ll> remain;

void del(ll x) {
	removed[x] = 1;
	remain.erase(x);
	for (auto v : st[x]) {
		if (!(chk[v] & 1)) chk[v]++;
		if (chk[v] == 3) q.push(v);
	}
	for (auto v : en[x]) {
		if (!(chk[v] & 2)) chk[v] += 2;
		if (chk[v] == 3) q.push(v);
	}
}

void solve() {
	ll N, M;
	cin >> N >> M;
	ll i;
	vector<ll> A(N + 1), B(N + 1);
	for (i = 0; i <= max(N, M) + 10; i++) C[i] = 0;
	for (i = 0; i <= max(N, M) + 10; i++) st[i].clear(), en[i].clear();
	while (q.size()) q.pop();
	remain.clear();
	for (i = 0; i <= max(N, M) + 10; i++) removed[i] = 0, chk[i] = 0, range[i] = { 0, 0 };
	for (i = 1; i <= N; i++) cin >> A[i];
	for (i = 1; i <= N; i++) cin >> B[i], C[i] = A[i] - B[i], C[i] += C[i - 1];
	for (i = 1; i <= M; i++) cin >> range[i].first >> range[i].second, range[i].first--;
	for (i = 1; i <= M; i++) st[range[i].first].push_back(i), en[range[i].second].push_back(i);
	for (i = 0; i <= N; i++) remain.insert(i);
	for (i = 0; i <= N; i++) if (C[i] == 0) del(i);
	
	while (q.size()) {
		ll t = q.front();
		q.pop();
		ll l, r;
		l = range[t].first;
		r = range[t].second;
		while (1) {
			auto it = remain.lower_bound(l);
			if (it == remain.end() || *it > r) break;
			ll x = *it;
			del(x);
		}
	}
	if (remain.size()) cout << no << ln;
	else cout << yes << ln;
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