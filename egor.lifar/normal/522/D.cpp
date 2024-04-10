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


using namespace std;


struct node{
	int l, r, y, min, mod;
	pair<int, int> x;
};


int n;
node d[500001];
int a[500000];
int next1[500000];


void calc(int v) {
	if (d[v].mod != -1) {
		d[v].min = (d[v].min == -1 ? d[v].mod: min(d[v].min, d[v].mod));
		d[d[v].l].mod = (d[d[v].l].mod == -1 ? d[v].mod: min(d[d[v].l].mod, d[v].mod));
		d[d[v].r].mod = (d[d[v].r].mod == -1 ? d[v].mod: min(d[d[v].r].mod, d[v].mod));
		d[v].mod = -1;
	}
}


void split(int v, pair<int, int> x, int &l, int &r) {
	if (v == 0) {
		l = 0;r = 0;
		return;
	}
	calc(v);
	if (x >= d[v].x) {
		split(d[v].r, x, d[v].r, r);
		l = v;
		calc(v);
	} else {
		split(d[v].l, x, l, d[v].l);
		r = v;
		calc(v);
	}
} 


void print(int v) {
	if (v == 0) {
		return;
	}
	print(d[v].l);
	cout << v << ' ' << d[v].min << endl;
	print(d[v].r);
}


int merge(int l, int r) {
	if (l == 0) {
		return r;
	}
	if (r == 0) {
		return l;
	}
	calc(l);
	calc(r);
	if (d[l].y > d[r].y) {
		d[l].r = merge(d[l].r, r);
		calc(l);
		return l;
	} else {
		d[r].l = merge(l, d[r].l);
		calc(r);
		return r;
	}
}


map<int, int> g;
int m;
pair<int, int> p[500000];
vector<pair<int, int> > s[500000];
int ans[500000];
map<pair<int, int>, int> h;
int root = 0;


int main() {
	cin >> n >> m; 
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		if (g.find(a[i]) == g.end()) {
			next1[i] = -1;
		} else {
			next1[i] = g[a[i]];
		}
		g[a[i]] = i;
	}
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		p[i] = make_pair(l - 1, r - 1);
		s[l - 1].push_back(make_pair(i, 1));
		s[r - 1].push_back(make_pair(i, -1));
	}
	int t = 0;
	d[0].min = -1;
	for (int i = 0; i < n; i++) {
	//	cout << next1[i] << endl;
		for (int j = 0; j < (int)s[i].size(); j++) {
			if (s[i][j].second == 1) {
				t++;
				d[t].x = make_pair(p[s[i][j].first].second, s[i][j].first);
				d[t].y = rand();
				d[t].mod = -1;
				d[t].min = -1;
				h[p[s[i][j].first]] = t;
				int l = 1, r = 1;
				split(root, make_pair(p[s[i][j].first].second, s[i][j].first), l, r);
				root = merge(l, t);
				root = merge(root, r);
			}
		}
		if (next1[i] != -1) {
			int l = 1, r = 1;
			split(root, make_pair(next1[i] - 1, 1000000000), l, r);
			d[r].mod = (d[r].mod == -1 ? next1[i] - i: min(d[r].mod, next1[i] - i));
		//	cout << d[r].mod << endl;
			root = merge(l, r);
			//cout << d[r].min << endl;
		}
		//print(root);
		//cout << root << endl;
	//	cout << "opa" << endl;
		for (int j = 0; j < (int)s[i].size(); j++) {
			if (s[i][j].second == -1) {
				int l = 1, r = 1;
		//		cout << p[s[i][j].first].second << endl;
				split(root, make_pair(p[s[i][j].first].second, s[i][j].first), l, r);
				int l1 = 1, r1 = 1;
				split(l, make_pair(p[s[i][j].first].second, s[i][j].first - 1), l1, r1);
				ans[s[i][j].first] = d[r1].min;
				//cout << r1 << endl;
				root = merge(l, r);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}