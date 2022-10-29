#pragma comment(linker, "/STACK:67108864")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const ll INF = 1E13 + 1;
const int MAXLEN = 15;
const int MAXN = 100500;

int n, z1, z2;
vi a, used;
vector<ll> val, nok;
vector<vi> g;
ll sum;

int len(ll x) {
	int ans = 0;
	while (x > 0) {
		ans++;
		x /= 10;
	}
	return ans;
}

ll gcd(ll a, ll b) {
	return (a == 0 ? b : gcd(b % a, a));
}

bool dfs(int v) {
	used[v] = 1;
	bool leaf = 1;
	ll childs = 0, gg;

	nok[v] = 1;
	forn(i, g[v].size()) {
		int w = g[v][i];
		if (!used[w]) {
			leaf = 0;
			if (!dfs(w))
				return 0;

			gg = gcd(nok[v], nok[w]);
			if (len(nok[v]) + len(nok[w] / gg) - 1 >= MAXLEN)
				return 0;

			nok[v] *= nok[w] / gg;
			if (nok[v] >= INF)
				return 0;

			childs++;
		}
	}

	if (leaf) {
		nok[v] = 1;
	}
	else {
		nok[v] *= childs;
		if (nok[v] >= INF)
			return 0;
	}
	return 1;
}

bool dfs2(int v, ll push) {
	used[v] = 1;
	bool leaf = 1;
	ll childs = 0;

	forn(i, g[v].size()) {
		int w = g[v][i];
		if (!used[w]) {
			leaf = 0;
			childs++;
		}
	}

	if (leaf) {
		return a[v] >= push;
	}

	ll p = push / childs;
	forn(i, g[v].size()) {
		int w = g[v][i];
		if (!used[w]) {
			if (!dfs2(w, p))
				return 0;
		}
	}

	return 1;
}

ll adoviy_binarnick() {
	ll l = 0, r = sum / nok[0] + 2, mid;
	while (r - l > 1) {
		forn(i, n)
			used[i] = 0;

		mid = (l + r) >> 1;
		if (dfs2(0, mid * nok[0])) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	return l * nok[0];
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	cin >> n;
	a.resize(n);
	used.resize(n, 0);
	g.resize(n);
	val.resize(n);
	nok.resize(n);

	sum = 0;
	forn(i, n) {
		cin >> a[i];
		sum += a[i];
	}

	forn(i, n - 1) {
		scanf("%d%d", &z1, &z2);
		z1--, z2--;
		g[z1].pb(z2);
		g[z2].pb(z1);
	}

	if (!dfs(0))
		cout << sum << '\n';
	else {
		cout << sum - adoviy_binarnick() << '\n';
	}

	return 0;
}