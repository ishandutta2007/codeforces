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

vector <int> vertex[size];
int eq[size];
int realc[size];
set <int> others[size];
int u[size], v[size];
int n, m;

void dfs(int v) {
	for (auto& u : others[v]) {
		if (realc[u] == -1) {
			realc[u] = realc[v] + 1;
			dfs(u);
		}
	}	
}

int main () {	
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		vertex[i].pb(i);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u[i], &v[i]);
		u[i]--, v[i]--;

		vertex[u[i]].pb(v[i]);
		vertex[v[i]].pb(u[i]);
	}

	for (int i = 0; i < n; i++)
		sort(vertex[i].begin(), vertex[i].end());

	vector <pair <vector <int>, int> > classes;
	for (int i = 0; i < n; i++) {
		classes.pb(mp(vertex[i], i));
	}

	sort(classes.begin(), classes.end());
	int curc = 0;
	eq[classes[0].sc] = curc;
	for (int i = 1; i < n; i++) {
		if (classes[i - 1].fs != classes[i].fs)
			curc++;
		eq[classes[i].sc] = curc;
	}

    if (curc == 0) {
    	printf("YES\n");
    	for (int i = 0; i < n; i++)
    		printf("1%c", " \n"[i == n - 1]);
    } else {
//        for (int i = 0; i < n; i++)
  //      	cerr << i << ' ' << eq[i] << endl;
    	
    	for (int i = 0; i < m; i++) {
    //		cerr << u[i] << ' ' << v[i] << ' ' << eq[u[i]] << ' ' << eq[v[i]] << endl;
			others[eq[u[i]]].insert(eq[v[i]]);
			others[eq[v[i]]].insert(eq[u[i]]);    		
    	}

    	for (int i = 0; i <= curc; i++)
    		others[i].erase(i);

    	int cnt3 = 0;
    	int cnt1 = 0;
    	int any = -1;
    	int cnt2 = 0;
    	for (int i = 0; i <= curc; i++) {
    		if ((int) others[i].size() == 1) {
    			cnt1++;
    			any = i;
    		}
    		if ((int) others[i].size() == 2) {
    			cnt2++;
    		}
    		if ((int) others[i].size() > 2) {
    			cnt3++;
    		}
    	}

    //	cerr << curc << ' ' << cnt1 << ' ' << cnt2 << ' ' << cnt3 << endl;

    	if (cnt3 > 0 || cnt1 == 0) {
    		printf("NO\n");
    		return 0;
    	}

    	for (int i = 0; i <= curc; i++)
    		realc[i] = -1;
    	realc[any] = 0;
    	dfs(any);
    	for (int i = 0; i <= curc; i++) {
    		if (realc[i] == -1) {
    			printf("NO\n");
    			return 0;
    		}
    	}	

    	printf("YES\n");
    	for (int i = 0; i < n; i++) {
    		printf("%d%c", realc[eq[i]] + 1, " \n"[i == n - 1]);
    	}
    }

    return 0;
}