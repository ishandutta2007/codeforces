#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>



using namespace std;


#define rank rank1


int kk, n, m;
string a[10][10];
int parent[100000];
int rank[100000];
int c[100000];
bool b[100];
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};


void make_set(int v) {
	parent[v] = v;
	rank[v] = 1;
	c[v] = 1;
}


int find_set(int v) {
	if (parent[v] == v) {
		return v;
	}
	parent[v] = find_set(parent[v]);
	return parent[v];
}


bool set_union(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a == b) {
		return true;
	}
	if (rank[a] >= rank[b]) {
		parent[b] = a;
		c[a] += c[b];
		rank[a] = max(rank[a], rank[b] + 1);
	} else {
		parent[a] = b;
		c[b] += c[a];
		rank[b] = max(rank[b], rank[a] + 1);
	}
	return false;
}


int main() {
	cin >> kk >> n >> m;
	for (int i = 0; i < kk; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int i1, jj1;
	cin >> i1 >> jj1;
	i1--;
	jj1--;
	if (a[0][i1][jj1] != '.') {
		cout <<  0 << endl;
		return 0;
	}
	vector<pair<int, int> > v;
	for (int k = 0; k < kk; k++) {
		for (int j = 0; j < n; j++) {
			for (int g = 0; g < m; g++) {
				if (a[k][j][g] == '.') {
					for (int h = 0; h < 6; h++) {
						int k1 = k + dz[h];
						int j1 = j + dx[h];
						int g1 = g + dy[h];
						if (k1 < 0 || j1 < 0 || g1 < 0 || k1 >= kk || j1 >= n || g1 >= m || a[k1][j1][g1] == '#') {
							continue;
						} 
						v.push_back(make_pair((k * 10 + j) * 10 + g, (k1 * 10 + j1) * 10 + g1));
					}
				}
			}
		}
	}
	for (int j = 0; j < 100000; j++) {
		make_set(j);
	}
	for (int i = 0; i < (int)v.size(); i++) {
		int a = v[i].first;
		int b = v[i].second;
		set_union(a, b);
	}
 	cout << c[find_set((0 * 10 + i1) * 10 + jj1)] << endl;
    return 0;
}