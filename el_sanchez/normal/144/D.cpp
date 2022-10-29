#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>
#include <queue>
#include <ctime>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 500000;

int n, m, s, l, ans, ansm, k[3];
set<pii> q;
vector<pii> g[MAXN];
int d[MAXN], b, w, pt1;

void dijkstra(int s) {
    pii temp;
    int a, b;

    for (int i = 1; i <= n; i++) {
        d[i] = (i != s) * INF;
        q.insert(make_pair(d[i], i));
    }

    while (!q.empty()) {
        temp = *q.begin();
        if (temp.fi == INF)
            return;
        q.erase(q.begin());
        a = temp.se;
        for (int i = 0; i < g[a].size(); i++) {
            b = g[a][i].se;
            if (d[b] > d[a] + g[a][i].fi) {
                q.erase(make_pair(d[b], b));
                d[b] = d[a] + g[a][i].fi;
                q.insert(make_pair(d[b], b));
            }
        }
    }
}

int main() {

	cin >> n >> m >> s;
	forn(i, m) {
		scanf("%d%d%d", &k[0], &k[1], &k[2]);
		g[k[0]].push_back(make_pair(k[2], k[1]));
		g[k[1]].push_back(make_pair(k[2], k[0]));
	}
	cin >> l;

	dijkstra(s);

	ans = 0;
	for (int i = 1; i <= n; i++)
		if (d[i] == l)
			ans++;

	ansm = 0;
	for (int a = 1; a <= n; a++) {
		k[0] = g[a].size();
		forn(j, k[0]) {
			b = g[a][j].se;
			w = g[a][j].fi;
			pt1 = -1;
			if (d[a] < l && w > l - d[a] && d[b] + (w - l + d[a]) >= l) {
				pt1 = l - d[a];
				ansm++;
			}
			if (d[b] < l && w > l - d[b] && d[a] + (w - l + d[b]) >= l && pt1 != (w - l + d[b]))
				ansm++;
		}
	}
	ansm /= 2;

	cout << (ans + ansm) << endl;

    return 0;
}