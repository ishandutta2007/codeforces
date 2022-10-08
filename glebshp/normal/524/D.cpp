#pragma comment(linker, "/STACK:1000000000")
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
const int size = 200 * 1000 + 100;

int par[size];
int ans[size];
int n, m, t;

int getpar(int v) {
	if (par[v] != v)
		par[v] = getpar(par[v]);

	return par[v];
}

void join(int v1, int v2) {
	v1 = getpar(v1);
	v2 = getpar(v2);

	if (v1 != v2)
		par[v2] = v1;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &t);

    vector <pair <int, int> > events;

  	for (int i = 0; i < n; i++) {
  		int hr, mn, sec;
  		scanf("%d:%d:%d", &hr, &mn, &sec);
  		sec += mn * 60;
  		sec += hr * 3600;

  		events.pb(mp(sec, i));
  	} 

  //	cerr << "here " << endl;

  	sort(events.begin(), events.end());
  	for (int i = 0; i < n; i++)
  		par[i] = i;

  	set <pair <int, int> > active;
  	bool flag = false;
  	for (int i = 0; i < n; i++) {
  		int curt = events[i].fs;
  		while (!active.empty() && active.begin()->fs <= curt - t)
  			active.erase(active.begin());
  		active.insert(events[i]);

  		if ((int) active.size() == m)
  			flag = true;

  		while ((int) active.size() > m) {
//  			cerr << active.size() << endl;
  			pair <int, int> lst = *active.rbegin();
  			active.erase(*active.rbegin());
  			pair <int, int> prelst = *active.rbegin();
  			active.erase(*active.rbegin());
  			join(lst.sc, prelst.sc);

  			active.insert(lst);
  		}
  	}

  	vector <int> anses;
  	for (int i = 0; i < n; i++) {
  		ans[i] = getpar(i);
  		anses.pb(ans[i]);
  	}
  	sort(anses.begin(), anses.end());
  	anses.resize(unique(anses.begin(), anses.end()) - anses.begin());
  	for (int i = 0; i < n; i++) {
  		ans[i] = lower_bound(anses.begin(), anses.end(), ans[i]) - anses.begin();
  	}

  	if (!flag) {
  		printf("No solution\n");
  		return 0;
  	}

  	printf("%d\n", (int) anses.size());
  	for (int i = 0; i < n; i++)
  		printf("%d\n", ans[i] + 1);

    return 0;
}