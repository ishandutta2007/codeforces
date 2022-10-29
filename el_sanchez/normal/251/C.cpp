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

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 2000000;
const int MAXM = 360360;

ll a, b, t, t2, ans, tmp[3];
int used[MAXM], tmr;
int k, d[MAXM];
vector<vi> g(MAXM);
deque<int> q;

inline void add(int a, int b) {
	g[a].push_back(b);
}

void bfs(int a, int b, int x) {
	used[a] = 1;
	q.clear();
	q.push_back(a);
	d[a] = 0;

	int v, w;
	while (!q.empty()) {
		v = q.front();
		q.pop_front();
		
		forn(i, g[v].size()) {
			w = g[v][i];
			if (used[w] < tmr) {
				used[w] = tmr;
				d[w] = d[v] + 1;
				q.push_back(w);
			}
		}
	}

	tmr++;
	tmp[x] = d[b];
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	tmr = 1;
	cin >> a >> b >> k;
	forab(i, 1, MAXM) {
		add(i, (MAXM + i - 1) % MAXM);
		forab(j, 2, k + 1)
			if (i % j)
				add(i, (MAXM + i - (i % j)) % MAXM);
	}

	t = b / MAXM;
	if (t * MAXM <= b && b < (t + 1) * MAXM && t * MAXM <= a && a < (t + 1) * MAXM) {
		bfs(a % MAXM, b % MAXM, 0);
		cout << tmp[0];
	} else {
		t2 = a / MAXM;
		t++;
		bfs(a % MAXM, 0, 0);
		bfs(MAXM - 1, 0, 1);
		tmp[1]++;
		bfs(MAXM - 1, b % MAXM, 2);
		tmp[2]++;
		ans = tmp[0] + (t2 - t) * tmp[1] + tmp[2];
		cout << ans;
	}

    return 0;
}