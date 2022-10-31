#include <iostream>
#include <ctime>
#include <set>
#include <fstream>
#include <cstdio>
#include <stack>
#include <map>
#include <vector>
#include <queue>
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
//const int SZ = 470;
const double eps = 1e-15;

using namespace std;



vector < vector <int> > g;
int n;
ll dp[200005], ans[200005], used[200005];

ll calc (int v, int p){
	ll num = 1;
	for (int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if (to == p) continue;
		num = (num * (calc(to, v) + 1)) % INF;
	}
	dp[v] = num;
	return num;
}

void dfs (int v, int p, ll k){
	ans[v] = (dp[v] * (k + 1)) % INF;
	vector <ll> nxt, go;
	for (int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if (to == p) continue;
		nxt.push_back(to);
	}
	go.resize(nxt.size(), k + 1);
	ll tmp = 1;
	for (int i = 0; i < nxt.size(); i++){
		go[i] = (go[i] * tmp) % INF;
		tmp = (tmp * (dp[nxt[i]] + 1)) % INF;
	}
	tmp = 1;
	for (int i  = int(nxt.size()) - 1; i >= 0; i--){
		go[i] = (go[i] * tmp) % INF;
		tmp = (tmp * (dp[nxt[i]] + 1)) % INF;
	}
	for (int i = 0; i < nxt.size(); i++){
		dfs(nxt[i], v, go[i]);
	}
}

int main(){
// ifstream cin (problem".in");
// ofstream cout(problem".in");
	scanf("%d", &n);
	g.resize(n);
	for (int i = 1; i < n; i++){
		int t;
		scanf("%d", &t);
		g[t - 1].push_back(i);
		g[i].push_back(t - 1);
	}
	calc(0, 0);
	dfs(0, 0, 0);
	for (int i = 0; i < n; i++){
		printf("%d ", ans[i] % INF);
	}
}