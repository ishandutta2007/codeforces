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

const int inf = 1000 * 1000 * 1000;
const int size = 100;

int ans[size][size][size];
int way[size][size];
int n, k, m;

int main () {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> n >> k;
    cin >> m;

    if (k == 1) {
    	cout << 0 << endl;
    	return 0;
    }

    for (int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++)
    		way[i][j] = inf;
    for (int i = 0; i < m; i++) {
    	int u, v, c;
    	cin >> u >> v >> c;
    	u--, v--;

    	way[u][v] = min(way[u][v], c);
    }

    for (int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++)
    		ans[0][i][j] = 0;
    int rans = inf;
    for (int i = 1; i < k; i++)
    	for (int j = 0; j < n; j++)
    		for (int p = 0; p < n; p++) {
    			ans[i][j][p] = inf;
    			for (int q = min(j, p); q <= max(j, p); q++) {
    				if (q != j) {
    					ans[i][j][p] = min(ans[i][j][p], min(ans[i - 1][q][p], ans[i - 1][q][j + (q > j ? 1 : -1)]) + way[j][q]);
    				}
    			}

    			if (i == k - 1) {
    				rans = min(rans, ans[i][j][p]);
    			}
    		}

    if (rans > inf / 2)
    	cout << -1 << endl;
    else
    	cout << rans << endl;

    return 0;
}