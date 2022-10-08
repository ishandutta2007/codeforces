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

const int size = 2100;
const int logsize = 71;
const int inf = 1000 * 1000 * 1000;
long long ans[logsize][size];
long long minedge[size];
int n;

int main () {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    vector <pair <int, pair <int, int> > > edges;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
    	minedge[i] = inf;
    }	

    for (int i = 0; i < n; i++)
    	for (int j = i + 1; j < n; j++) {
            int d;
    		scanf("%d", &d);
    		minedge[i] = min(minedge[i], d + 0ll);
    		minedge[j] = min(minedge[j], d + 0ll);
    		edges.pb(mp(d, mp(i, j)));
    	}

    sort(edges.begin(), edges.end());

    for (int j = min(n, logsize) - 1; j >= 0; j--) {
    	for (int i = 0; i < n; i++) {
    		ans[j][i] = minedge[i] * 1ll * (n - 1 - j);
    	}
    	if (j < min(n, logsize) - 1) {
		    for (int i = 0; i < (int) edges.size(); i++) {
    			int u = edges[i].sc.fs;
    			int v = edges[i].sc.sc;
    			long long val = edges[i].fs;
    	
    			ans[j][u] = min(ans[j][u], ans[j + 1][v] + val);
    			ans[j][v] = min(ans[j][v], ans[j + 1][u] + val);
    		}
    	}
    	if (j < min(n, logsize) - 2) {
    		long long best = inf * 1ll * n;
    		for (int i = 0; i < n; i++)
    			best = min(best, ans[j + 2][i]);
    		for (int i = 0; i < n; i++)
    			ans[j][i] = min(ans[j][i], best + minedge[i] * 2ll);
    	}
    }

    for (int i = 0; i < n; i++)
    	cout << ans[0][i] << endl;

    return 0;
}