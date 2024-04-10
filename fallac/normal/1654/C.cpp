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
typedef pair<int, int> pi;

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
	int i;
	ll sum = 0;
	multiset<ll> ms;
	ll x;
	cin >> N;
	for (i = 1; i <= N; i++) {
		cin >> x;
		sum += x;
		ms.insert(x);
	}
	queue<ll> q;
	q.push(sum);
	while (q.size()) {
		if (q.size() > ms.size()) {
			cout << no << ln;
			return;
		}
		ll t = q.front();
		q.pop();
		if (ms.empty() || ms.find(t) == ms.end()) {
			if (t == 1) {
				cout << no << ln;
				return;
			}
			ll a, b;
			if (t % 2) a = b = t / 2, b++;
			else a = b = t / 2;
			q.push(a);
			q.push(b);
		}
		else ms.erase(ms.find(t));
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