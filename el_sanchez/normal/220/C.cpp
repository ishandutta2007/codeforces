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

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 100500;

int n, id, k;
vi a, b, ida, idb, jmp, change, cur, wh, ans;
vector<pii> emptyv;
vector<vector<pii> > q;
pii c;
set<pii> s1, s2;

void init() {
	a.resize(n);
	b.resize(n);
	ida.resize(n);
	idb.resize(n);
	jmp.resize(n);
	change.resize(n);
	cur.resize(n);
	ans.resize(n);
	wh.resize(n);
	emptyv.clear();
	forn(i, n + 2)
		q.push_back(emptyv);

	s1.clear();
	s2.clear();
}

int main() {

    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
	
	scanf("%d", &n);
	init();
	forn(i, n) {
		scanf("%d", &b[i]);
		b[i]--;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	forn(i, n) {
		ida[a[i]] = i;
		idb[b[i]] = i;
	}

	//calc jumps and flips
	forn(i, n) {
		jmp[a[i]] = (n + idb[a[i]] - ida[a[i]]) % n;
		change[a[i]] = n - ida[a[i]];
		q[change[a[i]]].push_back(make_pair(0, a[i]));
		q[jmp[a[i]]].push_back(make_pair(-1, a[i]));
	}
	forn(i, n)
		sort(all(q[i]));
	
	//insert elements
	forn(i, n) {
		if (ida[i] <= idb[i]) {
			s1.insert(make_pair(idb[i] - ida[i], i));
			wh[i] = 0;
		} else {
			s2.insert(make_pair(ida[i] - idb[i], i));
			wh[i] = 1;
		}
		cur[i] = abs(idb[i] - ida[i]);
	}

	//go!
	forn(i, n) {
		forn(j, q[i].size()) {
			k = q[i][j].se;
			if (q[i][j].fi == -1) {
				if (wh[k] == 0) {
					s1.erase(make_pair(cur[k], k));
					cur[k] = -i;
					s2.insert(make_pair(cur[k], k));
				} else {
					s2.erase(make_pair(cur[k], k));
					cur[k] = i;
					s1.insert(make_pair(cur[k], k));
				}
				wh[k] = 1 - wh[k];
			} else {
				if (wh[k] == 0) {
					s1.erase(make_pair(cur[k], k));
					cur[k] = idb[k] - i;
					s2.insert(make_pair(cur[k], k));
				} else {
					s2.erase(make_pair(cur[k], k));
					cur[k] = idb[k] + i;
					s1.insert(make_pair(cur[k], k));
				}
				wh[k] = 1 - wh[k];
			}
		}

		//extract
		ans[i] = INF;
		if (!(s1.empty())) {
			c = *s1.begin();
			ans[i] = min(ans[i], c.fi - i);
		}
		if (!(s2.empty())) {
			c = *s2.begin();
			ans[i] = min(ans[i], c.fi + i);
		}
	}

	printf("%d\n", ans[0]);
	FORD(i, n, 1)
		printf("%d\n", ans[i]);

    return 0;
}