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




ll min(ll a, ll b){
	if (a < b) return a;
	return b;
}

vector < vector <pii> > g;
int d[26][26], m, used[26];
string s[2], anss;

int main(){
//	ifstream cin ("in.txt");
	cin >> s[0] >> s[1];
	if (s[0].size() != s[1].size()){
		cout << -1;
		return 0;
	}
	anss = s[0];
	cin >> m;
	g.resize(26);
	for (int i = 0; i < m; i++){
		char a, b;
		int w;
		cin >> a >> b >> w;
		g[a - 'a'].pb(mp(b - 'a', w));
	}
	queue <int> q;
	for (int i = 0; i < 26; i++){
		q.push(i);
		for (int j = 0; j < 26; j++){
			d[i][j] = INF;
			used[j] = 0;
		}
		d[i][i] = 0;
		while (!q.empty()){
			int v = q.front();
			used[v] = 0;
			q.pop();
			for (int j = 0; j < g[v].size(); j++){
				int to = g[v][j].first, cost = g[v][j].second;
				if (cost + d[i][v] < d[i][to]){
					d[i][to] = cost + d[i][v];
					if (!used[to]){
						used[to] = 1;
						q.push(to);
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < s[0].size(); i++){
		if(s[0][i] != s[1][i]){
			int a = s[0][i] - 'a', b = s[1][i] - 'a', best = -1, cst = INF;
			for (int j = 0; j < 26; j++){
				if (d[a][j] + d[b][j] < cst){
					cst = d[a][j] + d[b][j];
					best = j;
				}
			}
			if (cst == INF){
				cout << -1;
				return 0;
			}
			ans += cst;
			anss[i] = char(best + 'a');
		}
	}
	cout << ans << '\n' << anss << '\n';
	return 0;
}