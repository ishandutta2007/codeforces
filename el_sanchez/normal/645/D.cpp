#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;

int n, m;
pii e[MAXN];
vi g[MAXN];
int used[MAXN];
int sz;
int order[MAXN], nxt[MAXN];
int rest;

void dfs(int v) {
	used[v] = 1;
	for (auto w: g[v])
		if (!used[w])
			dfs(w);

	order[sz++] = v;
}

int main() {

	scanf("%d%d", &n, &m);
	forn(i, m) {
		scanf("%d%d", &e[i].X, &e[i].Y);
		e[i].X--;
		e[i].Y--;
		g[e[i].X].pb(e[i].Y);	
	}
	
	sz = 0;
	forn(i, n)
		if (!used[i])
			dfs(i);

	reverse(order, order + n);
	/*
	forn(i, n)
		cout << order[i] << '\n';
	*/	
	memset(nxt, -1, sizeof(nxt));
	
	forn(i, n - 1) {
		int v = order[i];
		int w = order[i + 1];
		nxt[v] = w;
		
		bool ok = 0;
		for (auto z: g[v])
			if (z == w) {
				ok = 1;
				break;
			}
			
		if (!ok) {
			cout << -1 << '\n';
			return 0;	
		}
	}
	
	rest = n;
	forn(i, n)
		if (nxt[i] == -1)
			rest--;
			
	forn(i, m) {
		int v = e[i].X;
		int w = e[i].Y;	
		
		if (nxt[v] == w) {
			rest--;
			nxt[v] = -1;	
		}
		
		if (rest == 0) {
			cout << i + 1 << '\n';
			return 0;
		}
	}
	
	cout << -1 << '\n';
	
	return 0;
}