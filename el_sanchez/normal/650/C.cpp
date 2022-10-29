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
#define db(x) cerr << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 1000500;

int rt[MAXN], rk[MAXN];

void makeSet(int v) {
	rt[v] = v;
	rk[v] = 0;
}

int findSet(int v) {
	if (rt[v] != v)
		rt[v] = findSet(rt[v]);
	return rt[v];
}

void unionSets(int a, int b) {
	int x = findSet(a);
	int y = findSet(b);
	if (x != y) {
		if (rk[x] > rk[y])
			rt[y] = x;
		else
			rt[x] = y;
		if (rk[x] == rk[y])
			rk[y]++;
	}
}

int n, m;

int getId(int x, int y) {
	return x * m + y;	
}

vi a[MAXN], ans[MAXN];
vi oldGraph[MAXN], g[MAXN], ig[MAXN];
int sz;
int bad[MAXN], used[MAXN], visited[MAXN];
pii arr[MAXN];

int curSz, curPtr;
int topSort[MAXN];

int dp[MAXN];

void dealWith() {
	sort(arr, arr + sz);
	
	int L = 0, R;
	int prevVertex = -1;
	for (int i = 1; i <= sz; i++)
		if (i == sz || arr[i].X != arr[L].X) {
			R = i - 1;
			
			//compress [L, R]
			for (int j = L; j < R; j++)
				unionSets(arr[j].Y, arr[j + 1].Y);
			if (prevVertex != -1)
				oldGraph[prevVertex].pb(arr[L].Y);
			prevVertex = arr[L].Y;
				
			L = i;
		}
}

void dfs(int v) {
	assert(!bad[v]);
	used[v] = 1;
	
	for (auto w: g[v])
		if (!used[w])
			dfs(w);
			
	topSort[curPtr--] = v;
}

int main() {
        
	scanf("%d%d", &n, &m);
	forn(i, n) {
		a[i].resize(m);
		ans[i].resize(m);
		forn(j, m)
			scanf("%d", &a[i][j]);	
	}
	
	forn(i, n)
		forn(j, m)
			makeSet(getId(i, j));
			
	forn(i, n) {
		sz = m;
		forn(j, m)
			arr[j] = {a[i][j], getId(i, j)};	
		dealWith();	
	}
	
	forn(i, m) {
		sz = n;
		forn(j, n)
			arr[j] = {a[j][i], getId(j, i)};	
		dealWith();	
	}
	/*
	forn(i, n)
		forn(j, m)
			cout << findSet(getId(i, j)) << " \n"[j == m - 1];
	*/		
	//cerr << 1 << endl;
	
	int V = n * m;
	int av, aw;
	forn(v, V)
		for (auto w: oldGraph[v]) {
			av = findSet(v);
			aw = findSet(w);
			
			g[av].pb(aw);
			ig[aw].pb(av);			
		}
			
	curSz = V;
	forn(v, V) {
		bad[v] = 0;
		if (findSet(v) != v) {
			bad[v] = 1;
			curSz--;
		}
	}
	
	curPtr = curSz - 1;
	forn(v, V)
		if (!bad[v] && !used[v])
			dfs(v);	
	
	assert(curPtr == -1);
	
	//cerr << 2 << endl;

	for (int i = 0; i < curSz; i++) {
		int v = topSort[i];

		int mx = 0;
		for (auto w: ig[v]) {
			assert(visited[w]);
			
			mx = max(mx, dp[w]);			
		}

		dp[v] = mx + 1;		
		visited[v] = 1;
	}
	
	//cerr << 3 << endl;

	forn(i, n)
		forn(j, m)
			ans[i][j] = dp[findSet(getId(i, j))];
			
	forn(i, n) {
		forn(j, m)
			printf("%d ", ans[i][j]);
		printf("\n");	
	}
		
	return 0;	
}