#pragma comment (linker, "/STACK:100000000000")

#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
#include <algorithm>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fs first
#define sc second
#define INF (1e9 + 7)
#define INFll (1e17 + 7)
#define sort stable_sort

using namespace std;



ll clr[100005], c[505], m, k, n, p = 0, d[505][505], par[100005], sz[100005], ok[505];

ll min(ll a, ll b){
	if (a < b) return a;
	return b;
}

int getroot (int v){
	if (par[v] == v) return v;
	return (par[v] = getroot(par[v]));
}

int merge(int u, int v){
	if (sz[u] > sz[v]) swap(u, v);
	par[u] = v;
	sz[v] += sz[u];
	return sz[v];
}



int main(){
//	ifstream cin ("in.txt");
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++){
		par[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < k; i++){
		for (int j = 0; j < k; j++){
			d[i][j] = INFll;
		}
		d[i][i] = 0;
		cin >> c[i];
		if (c[i] == 1) ok[i] = 1;
		for (int j = 0; j < c[i]; j++)
			clr[p++] = i;
	}
	for (int i = 0; i < m; i++){
		int u, v, cost;
		cin >> u >> v >> cost;
		u--; v--;
		if (clr[u] != clr[v]){
			d[clr[u]][clr[v]] = min(d[clr[u]][clr[v]], cost);
			d[clr[v]][clr[u]] = d[clr[u]][clr[v]];
			if (!cost){
				int u1 = getroot(u), v1 = getroot(v);
				if (u1 != v1){
					merge(u1, v1);
				}
			}
		} else if (!cost){
			int u1 = getroot(u), v1 = getroot(v);
			if (u1 != v1){
				merge(u1, v1);
			}
		}
	}
	p = 0;
	for (int i = 0; i < k; i++){
		int s = getroot(p++);
		for (int j = 1; j < c[i]; j++){
			int tmp = getroot(p++);
			if (tmp != s){
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes\n";
	for (int q = 0; q < k; q++){
		for (int i = 0; i < k; i++){
			for (int j = 0; j < k; j++){
				if (d[i][q] < INFll && d[q][j] < INFll)
					d[i][j] = min(d[i][j], d[i][q] + d[q][j]);
			}
		}
	}
	for (int i = 0; i < k; i++){
		for (int j = 0; j < k; j++){
			if (d[i][j] != INFll) cout << d[i][j] << " ";
			else cout << "-1 ";
		}
		cout << '\n';
	}
	return 0;
}