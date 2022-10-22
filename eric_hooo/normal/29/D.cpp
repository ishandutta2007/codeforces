#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, dis[310][310], a[610], p[610], t;

void Getpath(int u, int v){
	while (u != v){
		int i;
		for (i = 1; i <= n; i++){
			if (dis[u][i] == 1 && dis[i][v] + 1 == dis[u][v]) break; 
		}
		u = i;
		p[t++] = u;
	}
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			dis[i][j] = (i == j) ? 0 : INF;
		}
	}
	for (int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		dis[u][v] = dis[v][u] = 1;
	}
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	int k = 0;
	a[k++] = 1;
	while (cin >> a[k]) k++;
	a[k++] = 1;
	p[t++] = 1;
	for (int i = 0; i < k - 1; i++){
		Getpath(a[i], a[i + 1]);
	}
	if (t != 2 * n - 1){
		cout << "-1" << endl;
		return 0;
	}
	for (int i = 0; i < t; i++){
		cout << p[i] << " ";
	}
	cout << endl;
	return 0;
}