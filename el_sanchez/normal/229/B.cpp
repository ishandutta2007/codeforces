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
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second

using namespace std;

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int64 INF = 1E10;
const int MAXN = 111111;

int n, m, a, b, c, k, lft, val;
set<pair<int64, int> > q;
int64 d[MAXN], ans;
vector<pii> g[MAXN];
vector<vector<int64> > l(MAXN), r(MAXN);

int64 dijkstra(int s, int f) {
    pair<int64, int> temp;
	int64 cd;
    int a, b, v;

    forn(i, n) {
        if (i != s)
			d[i] = INF;
		else {
			d[i] = 0;
			if (!l[0].empty() && l[0][0] == 0)
				d[i] = r[0][0];
		}
        q.insert(make_pair(d[i], i));
    }

    while (!q.empty()) {
        temp = *q.begin();
        if (temp.ff == INF)
            return INF;
		if (temp.ss == f)
            return temp.ff;
        q.erase(q.begin());
        a = temp.ss;
        forn(i, g[a].size()) {
            b = g[a][i].ff;
			cd = d[a] + g[a][i].ss;
			
			v = lower_bound(l[b].begin(), l[b].end(), cd) - l[b].begin();
			if (l[b][v] > cd)
				v--;
			if (v >= 0) {
				if (l[b][v] <= cd && cd < r[b][v])
					cd = r[b][v];
			}
            if (d[b] > cd) {
                q.erase(make_pair(d[b], b));
                d[b] = cd;
                q.insert(make_pair(d[b], b));
            }
        }
    }

	return d[f];
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	scanf("%d%d", &n, &m);
	forn(i, m) {
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}
	forn(i, n - 1) {
		scanf("%d", &k);
		lft = 0;
		val = -1;
		forn(j, k) {
			scanf("%d", &c);
			if (val == -1) {
				lft = c;
				val = c + 1;
			} else if (c <= val) {
				val++;
			} else {
				l[i].push_back(lft);
				r[i].push_back(val);
				lft = c;
				val = c + 1;
			}
		}

		if (val != -1) {
			l[i].push_back(lft);
			r[i].push_back(val);
		}
		l[i].push_back(INF);
	}
	l[n - 1].push_back(INF);

	ans = dijkstra(0, n - 1);
	cout << (ans == INF ? -1 : ans);

	return 0;
}