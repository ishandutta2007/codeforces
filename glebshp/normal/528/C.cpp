#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 500 * 1000 + 100;

int v[size], u[size];
int n, m;
int deg[size];

set <int> vertex[size];
vector <pair <int, int> > ans;

void dfs(int vt) {
	while (!vertex[vt].empty()) {
		int cur = *vertex[vt].begin();
		if (vt != v[cur])
			swap(v[cur], u[cur]);
		vertex[v[cur]].erase(cur);
		vertex[u[cur]].erase(cur);

		dfs(u[cur]);
		ans.pb(mp(v[cur], u[cur]));
	}
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
    	scanf("%d%d", &v[i], &u[i]);
    	v[i]--, u[i]--;

    	deg[v[i]]++;
    	deg[u[i]]++;
    }

    int lst = -1;
    for (int i = 0; i < n; i++) {
    	if (deg[i] & 1) {
    		if (lst == -1) {
    			lst = i;
    		} else {
    			v[m] = lst;
    			u[m] = i;
    			m++;
    			lst = -1;
    		}
    	}
    }

    if (m & 1) {
    	v[m] = 0;
    	u[m] = 0;
    	m++;    
    }

    for (int i = 0; i < m; i++) {
    	vertex[v[i]].insert(i);
    	vertex[u[i]].insert(i);
    }

	dfs(0);

	assert((int) ans.size() == m);
	for (int i = 0; i < (int) ans.size(); i++)
		if (i & 1)
			swap(ans[i].fs, ans[i].sc);
	printf("%d\n", m);
	for (int i = 0; i < (int) ans.size(); i++)
		printf("%d %d\n", ans[i].fs + 1, ans[i].sc + 1);

    return 0;
}