#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
 

using namespace std;


int n, m;
int c[100000];
set<int> s[1000001];
bool used[1000001];



int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		used[c[i]] = true;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		if (c[a] != c[b]) {
		s[c[a]].insert(c[b]);
		s[c[b]].insert(c[a]);
	}
	}
	pair<int, int> p = make_pair(-1, -1);
	for (int i = 1; i <= 1000000; i++) {
		if (used[i]) {
			p = max(p, make_pair((int)s[i].size(), -i));
		}
	}
	cout << -p.second << endl;
	return 0;	
}