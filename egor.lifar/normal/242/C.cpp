#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>


using namespace std;



int n;
int k[100000], l[100000], r[100000];
queue<pair<int, int> > q;
map<pair<int, int>, int> d; 
map<pair<int, int>, bool> good;

void bfs(int a, int b) {
	q.push(make_pair(a, b));
	d[make_pair(a, b)] = 0;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		if (good.find(make_pair(p.first, p.second + 1)) != good.end()) {
			if (d.find(make_pair(p.first, p.second + 1)) == d.end()) {
				d[make_pair(p.first, p.second + 1)] = d[p] + 1;
				q.push(make_pair(p.first, p.second + 1));
			}
		}
		if (good.find(make_pair(p.first, p.second - 1)) != good.end()) {
			if (d.find(make_pair(p.first, p.second - 1)) == d.end()) {
				d[make_pair(p.first, p.second - 1)] = d[p] + 1;
				q.push(make_pair(p.first, p.second - 1));
			}
		}
		if (good.find(make_pair(p.first + 1, p.second)) != good.end()) {
			if (d.find(make_pair(p.first + 1, p.second)) == d.end()) {
				d[make_pair(p.first + 1, p.second)] = d[p] + 1;
				q.push(make_pair(p.first + 1, p.second));
			}
		}
		if (good.find(make_pair(p.first + 1, p.second + 1)) != good.end()) {
			if (d.find(make_pair(p.first + 1, p.second + 1)) == d.end()) {
				d[make_pair(p.first + 1, p.second + 1)] = d[p] + 1;
				q.push(make_pair(p.first + 1, p.second + 1));
			}
		}
		if (good.find(make_pair(p.first + 1, p.second - 1)) != good.end()) {
			if (d.find(make_pair(p.first + 1, p.second - 1)) == d.end()) {
				d[make_pair(p.first + 1, p.second - 1)] = d[p] + 1;
				q.push(make_pair(p.first + 1, p.second - 1));
			}
		}
		if (good.find(make_pair(p.first - 1, p.second)) != good.end()) {
			if (d.find(make_pair(p.first - 1, p.second)) == d.end()) {
				d[make_pair(p.first - 1, p.second)] = d[p] + 1;
				q.push(make_pair(p.first - 1, p.second));
			}
		}
		if (good.find(make_pair(p.first - 1, p.second + 1)) != good.end()) {
			if (d.find(make_pair(p.first - 1, p.second + 1)) == d.end()) {
				d[make_pair(p.first - 1, p.second + 1)] = d[p] + 1;
				q.push(make_pair(p.first - 1, p.second + 1));
			}
		}
		if (good.find(make_pair(p.first - 1, p.second - 1)) != good.end()) {
			if (d.find(make_pair(p.first - 1, p.second - 1)) == d.end()) {
				d[make_pair(p.first - 1, p.second - 1)] = d[p] + 1;
				q.push(make_pair(p.first - 1, p.second - 1));
			}
		}
	}
}



int main() {
	int x0, y0, x, y;
	cin >> y0 >> x0 >> y >> x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &k[i], &l[i], &r[i]);
		for (int j = l[i]; j <= r[i]; j++) {
			good[make_pair(k[i], j)] = true;
		}
	}
	if (y - y0 + 1 > n) {
		cout << -1 << endl;
		return 0;
	}
	bfs(y0, x0);
	if (d.find(make_pair(y, x)) == d.end()) {
		cout << -1 << endl;
	} else {
		cout << d[make_pair(y, x)] << endl;
	}
    return 0;
}