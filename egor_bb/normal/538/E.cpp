#include <iostream>
#include <ctime>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "test"
typedef long long ll;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int SZ = 70;
const double eps = 1e-15;

using namespace std;



vector <vector <int> > g;
int n, a[200005], m;

int dfs(int v, int p, int t){
	if (g[v].size() == 1 && v) return 1;
	if (t){
		int ans = INF;
		for (int i = 0; i < g[v].size(); i++){
			int to = g[v][i];
			if (to == p) continue;
			ans = min(ans, dfs(to, v, 1 - t));
		}
		return ans;
	} else {
		int ans = 0;
		for (int i = 0; i < g[v].size(); i++){
			int to = g[v][i];
			if (to == p) continue;
			ans += dfs(to, v, 1 - t);
		}
		return ans;
	}
}


int main(){
//  ifstream cin (problem".in");
//  ofstream cout(problem".in");
	cin >> n;
	if (n == 1){
		cout << "1 1";
		return 0;
	}
	m = n;
	g.resize(n);
	for (int i = 0; i < n - 1;i++){
		int t1, t2;
		cin >> t1 >> t2;
		t1--; t2--;
		if (g[t1].size() == 1)m--;
		if (g[t2].size() == 1)m--;
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	if (g[0].size() == 1) m--;
	int tmp = dfs(0, 0, 1);
	cout << m - tmp + 1 << ' ';
	tmp = dfs(0, 0, 0);
	cout << tmp << '\n';
}