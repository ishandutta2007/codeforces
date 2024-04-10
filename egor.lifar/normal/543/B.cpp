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


#define INF 1000 * 1000 * 1000


int n, m;
vector<int> v[100000];
int d[3001][3001];


void bfs(int u) {
	for (int j = 0; j < n; j++) {
		d[u][j] = INF;
	}
	d[u][u] = 0;
	queue<int> q;
	q.push(u);
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		for (int j = 0; j < (int)v[a].size(); j++) {
			int h = v[a][j];
			if (d[u][h] == INF) {
				d[u][h] = d[u][a] + 1;
				q.push(h);
			}
		}
	}
}


int main(){	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < n; i++) {
		bfs(i);
	}
	int s, f, l, s1, f1, l1;
	cin >> s >> f >> l >> s1 >> f1 >> l1;
	s--;f--;s1--;f1--;
	int ans = d[s][f] + d[s1][f1];
	if (ans >= INF || d[s][f] > l || d[s1][f1] > l1) {
		cout << -1 << endl;
		return 0;
	}
	//cout << ans << endl;
	int ans1 = INF;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (d[s][i] + d[i][j] + d[j][f] > l) {
				continue;
			}
			if (d[i][j] + min(d[s1][i] + d[j][f1], d[f1][i] + d[s1][j]) > l1) {
				continue;
			}
		//	cout << i + 1 << ' ' << j + 1 << endl;
			ans1 = min(ans1, d[s][i] + d[i][j] + d[j][f] + min(d[s1][i] + d[j][f1], d[f1][i] + d[s1][j]));
		}
	}
	cout << m - min(ans, ans1) << endl;
	return 0;
}