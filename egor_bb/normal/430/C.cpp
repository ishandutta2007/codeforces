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
#define INF 2000000000000000000

#define LL long long
#define mp make_pair
#define pb push_back
#define ULL unsigned long long

using namespace std;
	

	vector < vector <int> > g;
	int d, a1, a2;
	vector <int> ans, m1, m2, par, a1o, a2o;

void dfs (int v){
	if (d%2 == 1) m1[v] = (m1[v] + a1)%2;
	else m1[v] = (m1[v] + a2)%2;
	a1o[v] = a1;
	a2o[v] = a2;
	if (m1[v] != m2[v]){
		ans.pb (v+1);
		if (d%2==1) a1 = (a1+1)%2;
		if (d%2==0) a2 = (a2+1)%2;
	}
	for (int i=0; i<g[v].size(); i++){
		int to = g[v][i];
		if (to != par[v]){
			par[to] = v;
			d++;
			dfs (to);
			d--;
		}
	}
	a1 = a1o[v];
	a2 = a2o[v];
}

int main (){
	int n;
	cin >> n;
	int t1, t2;
	m1.resize (n);
	m2.resize (n);
	a1o.resize (n);
	a2o.resize (n);
	g.resize (n);
	par.resize (n, -1);
	for (int i=0; i<n-1; i++){
		cin >> t1 >> t2;
		g[t1-1].push_back (t2-1);
		g[t2-1].push_back (t1-1);
	}
	for (int i=0; i<n; i++){
		cin >> m1[i];
	}
	for (int i=0; i<n; i++){
		cin >> m2[i];
	}
	d=0;
	a1=0;
	a2=0;
	dfs (0);
	cout << ans.size() << '\n';
	for (int i=0; i<ans.size(); i++){
		cout << ans[i] << '\n';
	}
}