#pragma comment (linker, "/STACK:100000000")

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <string>
#define INF 1e18

#define LL long long
#define mp make_pair
#define pb push_back
#define ULL unsigned long long

using namespace std;
	

	vector < vector <int> > g;
	vector <int> cl;
	int q = 0;
	int n;

void dfs (int v){
	cl[v] = q;
	if (cl[g[v][0]]==0) dfs (g[v][0]);
}


void swap (int i, int j){
	g[i][0] = g[j][0] + g[i][0];
	g[j][0] = g[i][0] - g[j][0];
	g[i][0] = g[i][0] - g[j][0];
}

int calc (){
	int ans = 0;
	vector <int> t;
	t.resize (q+1, 0);
	for (int i=0; i<n; i++) t[cl[i]]++;
	for (int i=1; i<=q; i++){
		ans += t[i]-1;
	}
	return ans;
}

int main (){
	cin >> n;
	g.resize (n);
	cl.assign (n, 0);
	int t;
	for (int i=0; i<n; i++){
		cin >> t;
		g[i].pb (t-1);
	}
	int m;
	cin >> m;
	for (int i=0; i<n; i++){
		if (cl[i] == 0){
			q++;
			dfs (i);
		}
	}
	int w = calc();
	if (m == w){
		cout << 0;
	} 
	if (m > w){
		cout << m-w << '\n';
		for (int i = 0; i < m-w; i++){
			int v1 = 0, v2 = 1;
			while (cl[v1]==cl[v2]) v2++;
			cout << v1+1 << " " << v2 + 1 << " ";
			swap (v1, v2);
			q = 0;
			cl.assign (n, 0);
			for (int i=0; i<n; i++){
				if (cl[i] == 0){
					q++;
					dfs (i);
				}
			}
		}
	}
	if (m < w){
		cout << w-m << '\n';
		for (int i = 0; i < w-m; i++){
			int v1 = 0, v2 = 0;
			while (g[v1][0] == v1) v1++;
			while (cl[v1]!=cl[v2] || v1==v2) v2++;
			cout << v1+1 << " " << v2 + 1 << " ";
			swap (v1, v2);
			q = 0;
			cl.assign (n, 0);
			for (int i=0; i<n; i++){
				if (cl[i] == 0){
					q++;
					dfs (i);
				}
			}
		}
	}
}