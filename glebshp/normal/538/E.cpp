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
const int size = 250 * 1000;

vector <int> vertex[size];
int val[size];
bool isleaf[size];
int m = 0;
int n;

void dfs1(int v, int fr, int who) {
	if (isleaf[v]) {
		val[v] = 1;
		return;
	}	
	for (int i = 0; i < (int) vertex[v].size(); i++) {
		if (vertex[v][i] != fr) {
			dfs1(vertex[v][i], v, who ^ 1);
		}
	}	

	if (who == 0) {
		val[v] = m;
		for (int i = 0; i < (int) vertex[v].size(); i++)
			if (vertex[v][i] != fr) {
				val[v] = min(val[v], val[vertex[v][i]]);
			}
	} else {
		val[v] = 0;
		for (int i = 0; i < (int) vertex[v].size(); i++)
			if (vertex[v][i] != fr) {
		    	val[v] += val[vertex[v][i]];
		    }
	}
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
    	int v, u;
    	scanf("%d%d", &v, &u);
    	v--, u--;

    	vertex[v].pb(u);
    	vertex[u].pb(v);
    }
    for (int i = 0; i < n; i++) {
    	isleaf[i] = ((int) vertex[i].size() == 1u && i != 0) || (n == 1);
    	m += isleaf[i];
    }

    dfs1(0, -1, 0);
    cout << m - val[0]  + 1 << ' ';
    dfs1(0, -1, 1);
    cout << val[0] << endl;
//    dfs2(0, -1, 0);;
//    cout << val[0] << endl;

   	return 0;
}