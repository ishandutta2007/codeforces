#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct TNode {
	int L, R;
	int l, r;
	int sum;
};

const int MAXT = 210000;
TNode t[MAXT];

int tc = 0;

int buildTree(int L, int R) {
	int node = tc++;
	TNode &n = t[node];
	n = {L, R, -1, -1, 0};
	if (R - L > 1) {
		int M = (L + R) / 2;
		n.l = buildTree(L, M);
		n.r = buildTree(M, R);
	}
	return node;
}

void relax(TNode &n) {
	n.sum = t[n.l].sum + t[n.r].sum;
}

void change(TNode &n, int i, int x) {
	if (i < n.L || i >= n.R) return;
	if (n.R - n.L == 1) {
		n.sum = x;
		return;
	}
	change(t[n.l], i, x);
	change(t[n.r], i, x);
	relax(n);
}

void minsumk(TNode &n, int &l, int &k) {
//	if (!k) return;
	if (l < n.L) return;
	if (n.R <= l) return;
	if (n.L == l) {
		if (n.sum <= k) {
			k -= n.sum;
			l = n.R;
			return;
		}
	}
	minsumk(t[n.l], l, k);
	minsumk(t[n.r], l, k);
}

const int maxn = 110000;
vi q[maxn], qadd[maxn];
int pos[maxn], ans[maxn];
int prevp[maxn], peq[maxn];

int main() {
#ifdef LOCAL_DEFINE
	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
#endif

	int n;
	cin >> n;
	forn(i, n + 1) prevp[i] = -1;
	forn(i, n) {
		int x;
		cin >> x;
		peq[i] = prevp[x];
		prevp[x] = i;
		qadd[peq[i] + 1].pb(i);
	}
	
	for1(k, n) q[0].pb(k);

	int root = buildTree(0, n);
	forn(i, n) {
		for (auto x: qadd[i]) change(t[root], x, 1);
		for (auto x: q[i]) {
			int l = i;
			int k = x;
			minsumk(t[root], l, k);
//			cerr << i << ' ' << x << ' ' << l << '\n';
			++ans[x];
			pos[x] = l;
			q[l].pb(x);
		}
	}

	for1(k, n) cout << ans[k] << ' ';
	cout << '\n';

#ifdef LOCAL_DEFINE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}