#include <iostream>
#include <fstream> 
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

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 111;
const int MAXM = 2000500;

int n, m, m1, m2;
int bonus[MAXN][MAXN];
char a1[MAXM], a2[MAXM];

struct edge {
	int w, f, c, cost;
	int inv;
	edge(){};
	edge(int _w, int _f, int _c, int _cost, int _inv) {
		w = _w;
		f = _f;
		c = _c;
		cost = _cost;
		inv = _inv;
	}
};

int cnt;
vector<vi> g(MAXN);
vector<edge> edges;

void add_edge(int v, int w, int flow, int cost) {
	edges.push_back(edge(w, 0, flow, cost, cnt + 1));
	edges.push_back(edge(v, 0, 0, -cost, cnt));
	g[v].push_back(cnt);
	g[w].push_back(cnt + 1);
	cnt += 2;
}

deque<int> q;
int fstart, fend, d[MAXN], par[MAXN], parid[MAXN];
bool used[MAXN];

bool find_way() {
    int eid, from, to;
    q.clear();
    q.push_back(fstart);
    forn(i, fend + 1)
        d[i] = INF;
    memset(used, 0, sizeof(used));
    d[fstart] = 0;
    par[fstart] = -1;
    used[fstart] = 1;

    while (!q.empty()) {
        from = q.front();
        used[from] = 0;
        q.pop_front();

        forn(i, g[from].size()) {
			eid = g[from][i];
			to = edges[eid].w;
			if (edges[eid].c - edges[eid].f > 0 && d[from] + edges[eid].cost < d[to]) {
                d[to] = d[from] + edges[eid].cost;
                par[to] = from;
                parid[to] = eid;
                if (!used[to])
                    q.push_back(to);
                used[to] = 1;
            }
        }
    }

    return (d[fend] < INF);
}

int fflow, fcost, answer;

void get(int v) {
    if (par[v] == -1)
        return;

    fflow = min(fflow, edges[parid[v]].c - edges[parid[v]].f);
    get(par[v]);
	fcost += edges[parid[v]].cost;
	edges[parid[v]].f += fflow;
	edges[edges[parid[v]].inv].f -= fflow;
}

int main() {
 
	scanf("%d %d\n", &n, &m);
	scanf("%s\n", a1);
	scanf("%s\n", a2);
	
	forn(i, n) {
		m1 = ('a' <= a1[i] && a1[i] <= 'z') ? (1 + a1[i] - 'a') : (27 + a1[i] - 'A');
		m2 = ('a' <= a2[i] && a2[i] <= 'z') ? (1 + a2[i] - 'a') : (27 + a2[i] - 'A');
		bonus[m1][m2]++;
	}

	cnt = 0;
	fstart = 0;
	fend = m * 2 + 1;
	forab(i, 1, m + 1)
		add_edge(fstart, i, 1, 0);
	forab(i, 1, m + 1)
		forab(j, 1, m + 1)
			add_edge(i, m + j, 1, -bonus[i][j]);
	forab(i, 1, m + 1)
		add_edge(m + i, fend, 1, 0);

	answer = 0;
    while (find_way()) {
        fflow = INF;
        fcost = 0;
        get(fend);
        answer -= fcost;
    }

	printf("%d\n", answer);
	forab(i, 1, m + 1)
		forn(j, g[i].size())
			if (edges[g[i][j]].f > 0) {
				m1 = edges[g[i][j]].w - m - 1;
				cout << char((0 <= m1 && m1 <= 25) ? ('a' + m1) : ('A' + m1 - 26));
				break;
			}
	cout << '\n';

    return 0;
}