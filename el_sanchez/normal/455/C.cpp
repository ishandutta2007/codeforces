#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>          
#include <queue>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <cassert>
                   
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++) 
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = int(a); i < int(b); i++)

#define sqr(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;

const int INF = 1E9;    
const ld eps = 1e-9;
const ld pi = acos(-1.0);
const int MAXN = 111111;
    
bool flag;
int n, m, k, q, a, b, tmr;
int idv, len, mlen;
vector<vi> g;
vi used, visited, stk;
vi rt, answer;     
int iter;

int findrt(int v) {
	if (v == rt[v])
		return v;
	return rt[v] = findrt(rt[v]);
}

void unite(int a, int b) {
	int ra = findrt(a), rb = findrt(b), ma, mb;
	if (ra != rb) {
		ma = (answer[ra] + 1) / 2;
		mb = (answer[rb] + 1) / 2;
		answer[ra] = max(answer[ra], answer[rb]);
		answer[ra] = max(answer[ra], ma + 1 + mb);
		answer[rb] = answer[ra];
		if (rand() & 1)
			rt[ra] = rb;
		else
			rt[rb] = ra;		
	}
}

void dfs1(int v, int h) {
	visited[v] = iter;
	if (h > len) {
		idv = v;
		len = h;
	}
	
	for (auto w: g[v]) {
		if (visited[w] != iter)
			dfs1(w, h + 1);	
	}
}

void dfs2(int v, int h) {
	used[v] = tmr;
	rt[v] = idv;
	                           
	if (h == len && !flag) {
		flag = 1;          
		answer[idv] = len;
	}
	
	for (auto w: g[v]) {
		if (used[w] != tmr)
			dfs2(w, h + 1);	
	}
}

int main() {

	cin >> n >> m >> k;
	g.resize(n);
	forn(i, m) {
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	used.resize(n, 0);
	visited.resize(n, 0);
	rt.resize(n, 0);
	answer.resize(n, 0);
			
	forn(i, n)
		if (visited[i] == 0) {
			len = 0;
			idv = i;
			iter = 1;
			dfs1(i, 0);	
			
			rt[i] = idv;
			len = 0;
			iter = 2;
			dfs1(rt[i], 0);
			
			idv = rt[i];
			tmr++;
			flag = 0;
			dfs2(rt[i], 0);			
		}
			
	forn(i, k) {
		scanf("%d%d", &q, &a);
		a--;
		if (q == 1) {
			printf("%d\n", answer[findrt(a)]);
		} else {
			scanf("%d", &b);
			b--;
			unite(a, b);	
		}		
	}
	
	return 0;
}