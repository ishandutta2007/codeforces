#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
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
const int INF = 1E9;
const int MAXN = 333;
const int MAXM = 100500;
const ll MOD = 1E9 + 7;

int n, q, t1, t2, l, r, csz;
vi a;
int nxt[MAXN], prv[MAXN], used[MAXN];
vi cur, sum;
vector<ll> elems;
ll t, dp[MAXM];

bool leftdfs(int v) {
	used[v] = 1;
	if (prv[v] == -1) {
		l = v;
		return 1;
	}
	if (used[prv[v]] == 1)
		return 0;
	return leftdfs(prv[v]);
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n >> q >> t;
	a.resize(n);
	forn(i, n)
		scanf("%d", &a[i]);

	memset(nxt, -1, sizeof(nxt));
	memset(prv, -1, sizeof(prv));
	forn(i, q) {
		scanf("%d%d", &t1, &t2);
		t1--, t2--;
		nxt[t2] = t1;
		prv[t1] = t2;
	}

	elems.clear();
	forn(i, n)
		if (!used[i]) {
			l = i;
			if (!leftdfs(i)) {
				cout << 0;
				return 0;
			}

			cur.clear();
			sum.clear();
			r = l;
			while (r != -1) {
				cur.pb(r);
				sum.pb(0);
				used[r] = 1;
				r = nxt[r];
			}

			sum.back() = a[cur.back()];
			ford(j, cur.size() - 1)
				sum[j] = sum[j + 1] + a[cur[j]];

			forn(j, sum.size())
				elems.pb(sum[j]);

			for (int j = 1; j < cur.size(); j++)
				t -= 1ll * j * a[cur[j]];
		}

	if (t < 0) {
		cout << 0;
		return 0;
	}
	dp[0] = 1;
	forn(i, elems.size())
		if (elems[i] <= t) {
			csz = elems[i];
			for (int k = 0; k <= t - csz; k++) {
				dp[k + csz] += dp[k];
				if (dp[k + csz] > MOD)
					dp[k + csz] -= MOD;
			}
		}
	cout << dp[t];

    return 0;
}