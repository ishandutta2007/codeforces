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

const int size = 1000 * 1000 + 100;
int n, m;
int ans;
int s[size];
vector <int> vertex[size];
vector <int> cols[size];
int ansc[size];

void dfs(int v, int f) {
	set <int> used;
	for (int i = 0; i < s[v]; i++) {
		if (ansc[cols[v][i]] != -1)
			used.insert(ansc[cols[v][i]]);
	}	
	int cur = 0;
	for (int i = 0; i < s[v]; i++) {
		if (ansc[cols[v][i]] == -1) {
			while (used.count(cur)) {
				cur++;
			}
			ansc[cols[v][i]] = cur;
			used.insert(cur);
			cur++;
		}
	}

	for (auto& u : vertex[v]) {
		if (u != f)
			dfs(u, v);
	}
}

int main () {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
    	scanf("%d", &s[i]);
    	for (int j = 0; j < s[i]; j++) {
    		int d;
    		scanf("%d", &d);
    		d--;

    		cols[i].pb(d);
    	}
    }

    for (int i = 0; i < n - 1; i++) {
    	int u, v;
    	scanf("%d%d", &u, &v);
    	u--, v--;

    	vertex[u].pb(v);
    	vertex[v].pb(u);
    }

    ans = 1;
    for (int i = 0; i < n; i++)
    	ans = max(ans, s[i]);
    for (int i = 0; i < m; i++)
    	ansc[i] = -1;

    dfs(0, -1);

    printf("%d\n", ans);
    for (int i = 0; i < m; i++)
    	if (ansc[i] == -1)
    		ansc[i] = 0;
	for (int i = 0; i < m; i++)
		printf("%d%c", ansc[i] + 1, " \n"[i == m - 1]);

    return 0;
}