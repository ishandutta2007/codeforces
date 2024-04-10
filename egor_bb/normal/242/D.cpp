#pragma comment (linker, "/STACK:10000000")

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
#define INFll (1e18 + 7)
#define sort stable_sort

using namespace std;


int n, m, a[100005], used[100005], b[100005], ok[100005];
vector < vector <int> > g;


int main(){
	//ifstream in ("in.txt");
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int  t1, t2;
		cin >> t1 >> t2;
		g[t1 - 1].pb(t2 - 1);
		g[t2 - 1].pb(t1 - 1);
	}
	queue <int> q;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (!a[i]) {
			q.push(i);
			used[i] = 1;
		}
	}
	vector <int> ans;
	while (!q.empty()){
		int v = q.front();
		ans.pb(v);
		q.pop();
		b[v]++;
		for (int i = 0; i < g[v].size(); i++){
			int to = g[v][i];
			b[to]++;
			if (!used[to] && b[to] == a[to]) {
				q.push(to);
				used[to] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++){
		if (a[i] == b[i]){
			cout << -1;
			return 0;
		}
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << " ";
	return 0;
}