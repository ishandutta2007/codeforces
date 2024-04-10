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
#define rank sdlkfsdjlf

const double pi = acos(-1.0);
const int size = 2000 * 1000;

set <pair <int, int> > vertex[size];
int n;
int rank[size];
int par[size];

int getrank(int v) {
	if (vertex[v].empty())
		return 1;
	if (vertex[v].size() == 1u) {
		return vertex[v].begin()->fs;
	} else {
		set <pair <int, int> >::iterator it = vertex[v].end();
		--it;
		int h = it->fs;
		--it;
		return max(h, it->fs + 1);
	}
}

int getans() {
	if (vertex[0].empty())
		return 0;
	return vertex[0].rbegin()->fs;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    rank[0] = 0;
    par[0] = -1;
    for (int i = 0; i < n; i++) {
    	scanf("%d", &par[i + 1]);
    	par[i + 1]--;
    	int p = i + 1;
    	rank[p] = 1;
    	vertex[par[p]].insert(mp(rank[p], p));
    	p = par[p];
    	while (p != -1) {
    		int np = getrank(p);
    		if (np > rank[p]) {
    			if (par[p] != -1) {
    				vertex[par[p]].erase(mp(rank[p], p));
    				vertex[par[p]].insert(mp(np, p));
    			}
    			rank[p] = np;
    			p = par[p];
    		} else {
    			break;
    		}
    	}
    	printf("%d ", getans());
    }

    return 0;
}