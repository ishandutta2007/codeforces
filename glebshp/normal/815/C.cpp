#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int size = 5100;
const int inf = 1000 * 1000 * 1000 + 100;

int ctake[size][size];
int cnot[size][size];
int tsize[size];
int n, b;
vector <int> vertex[size];
int c[size];
int d[size];
int p[size];
int h[size];

void dfs(int v) {
	for (int i = 0; i <= n; i++)
		ctake[v][i] = inf;
	ctake[v][1] = c[v] - d[v];
	for (int i = 0; i <= n; i++)
		cnot[v][i] = inf;
	cnot[v][0] = 0;
	cnot[v][1] = c[v];
	
	tsize[v] = 1;

	for (auto& u : vertex[v]) {
		dfs(u);

		for (int i = 0; i <= tsize[v] + tsize[u]; i++)
			h[i] = inf;
		for (int i = 0; i <= tsize[v]; i++)
			for (int j = 0; j <= tsize[u]; j++)
	        	h[i + j] = min(h[i + j], ctake[v][i] + ctake[u][j]);
	   	for (int i = 0; i <= tsize[v]; i++)
			for (int j = 0; j <= tsize[u]; j++)
	        	h[i + j] = min(h[i + j], ctake[v][i] + cnot[u][j]);
	    for (int i = 0; i <= tsize[v] + tsize[u]; i++)
	    	ctake[v][i] = min(ctake[v][i], h[i]);

	    for (int i = 0; i <= tsize[v] + tsize[u]; i++)
			h[i] = inf;
		for (int i = 0; i <= tsize[v]; i++)
			for (int j = 0; j <= tsize[u]; j++)
	        	h[i + j] = min(h[i + j], cnot[v][i] + cnot[u][j]);
	    for (int i = 0; i <= tsize[v] + tsize[u]; i++)
	    	cnot[v][i] = min(cnot[v][i], h[i]);

	    tsize[v] += tsize[u];
	    //for (int i = 0; i <= tsize[v]; i++)
	    //	cnot[v][i] = min(cnot[v][i], ctake[v][i]);
	}
}

int main () {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &b);
    for (int i = 0; i < n; i++) {
    	scanf("%d%d", &c[i], &d[i]);
    	if (i > 0)
    		scanf("%d", &p[i]);
    }

    for (int i = 1; i < n; i++) {
    	p[i]--;
    	vertex[p[i]].pb(i);
    }

    dfs(0);

    int ans = 0;
    for (int i = 0; i <= n; i++)
    	if (min(ctake[0][i], cnot[0][i]) <= b)
    		ans = i;

    printf("%d\n", ans);

    return 0;
}