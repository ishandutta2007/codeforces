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



ll n, par[200004], cost[200005], dp[200005][2];
vector <vector <int> > g;
ll ans = 0;
int root;

void dfs(ll v){
	ll mn = 1e18, cnt = 0, sum = 0;
	dp[v][1] = cost[v];
	dp[v][0] = 0;
	for (int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		dfs(to);
		mn = min(mn, abs(dp[to][0] - dp[to][1]));
		if (dp[to][0] < dp[to][1]){
			cnt++;
			sum += dp[to][1];
		} else {
			sum += dp[to][0];
		}
	}
	if (cnt & 1){
		dp[v][1] = max(sum, sum - mn + cost[v]);
		dp[v][0] = sum - mn;
	} else {
		dp[v][1] = cost[v] + sum;
		dp[v][0] = sum;
	}
}


int main(){
 //   ifstream cin (problem".in");
//  ofstream cout(problem".in");
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n; i++){
		cin >> par[i] >> cost[i];
		if (par[i] > 0){
			g[par[i] - 1].push_back(i);
		}
		else
			root = i;
	}
	dfs(root);
	cout << max(dp[root][0], dp[root][1]) << '\n';
}