#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int val[210000];
vector<int> wt[210000];
vector<int> dp[210000];
vector< pii > adj[210000];
int n, k;

pair<int,int> totwt[210000][2];
int full[210000];
pair<int,int> notfull[210000][2];
int state[210000];

int rec(int v, int p, int goal);

void upd(int follow_idx, int v, int goal) {
	int newv = adj[v][follow_idx].first;
	int newp = adj[v][follow_idx].second;

	rec(newv, newp, goal);
	
	if (wt[newv][newp] >= goal) {
		full[v] += dp[newv][newp];
	}
	else {
		if (notfull[v][1].second < dp[newv][newp]) notfull[v][1] = {dp[newv][newp], follow_idx};
		if (notfull[v][0] < notfull[v][1]) swap(notfull[v][0], notfull[v][1]); 
	}

	if (totwt[v][1].first > wt[newv][newp]) totwt[v][1] = {wt[newv][newp], follow_idx};
	if (totwt[v][0] > totwt[v][1]) swap(totwt[v][0], totwt[v][1]);
}

int rec(int v, int p, int goal) {
	int &ret = dp[v][p];
	if (ret != -1) return ret;
	if (val[v] < goal) return ret = 0;

	if (state[v] == -1) {
		for (int i = 1; i < (int)adj[v].size(); i++) if (i != p) {
			upd(i, v, goal);
		}
		state[v] = p;
	}
	else if (state[v] && state[v] != p) {
		upd(state[v], v, goal);
		state[v] = 0;
	}

	wt[v][p] = (totwt[v][0].second != p ? totwt[v][0].first : totwt[v][1].first);
	wt[v][p] = min(wt[v][p], val[v]);

	ret = 1 + full[v] + notfull[v][0].first;
	if (state[v] != p) {
		if (notfull[v][0].second == p) ret += (notfull[v][1].first - notfull[v][0].first);
		if (wt[adj[v][p].first][adj[v][p].second] >= goal) ret -= dp[adj[v][p].first][adj[v][p].second];
	}

	return ret;
}

bool check(int goal) {
	for (int i = 1; i <= n; i++) {
		state[i] = -1;
		full[i] = 0;
		notfull[i][0] = notfull[i][1] = {0, -1};
		totwt[i][0] = totwt[i][1] = {1000000000, -1};
		for (int j = 0; j < (int)adj[i].size(); j++) {
			dp[i][j] = -1;
		}
	} 

	for (int i = 1; i <= n; i++) {
		if (rec(i, 0, goal) >= k) return true;
	}

	return false;
}

int main() {
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
	for (int i = 1; i <= n; i++) adj[i].push_back({-1,-1});

	for (int i = 0; i < n-1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);

		int uT = adj[u].size();
		int vT = adj[v].size();

		adj[u].push_back( {v, vT} );
		adj[v].push_back( {u, uT} );
	}

	for (int i = 0; i <= n; i++) {
		wt[i].resize(adj[i].size(), -1);
		dp[i].resize(adj[i].size(), -1);
	}

	int st = 0, ed = 1000000;
	while (st < ed) {
		int md = (st+ed+1)/2;
		if (check(md)) st = md;
		else ed = md-1;
	}
	printf("%d\n", st);
}