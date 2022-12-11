#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
  
using namespace std;
  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
  
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
 
/*
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }
*/

int n, m, wmax;
vector<int> g[1007];
int w[1007];
int b[1007];
bool was[1007];
vector<vector<int> > q;
int dp[1007][1007];

void dfs(int v) {
	q.back().pub(v);
	was[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (!was[to])
			dfs(to);
	}
}


const bool is_testing = 0;
int main() {
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
    //mt19937 rnd(time(NULL));
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        //freopen("just.in", "r", stdin);
        //freopen("just.out","w", stdout);
    }
	scanf("%d %d %d", &n, &m, &wmax);
	for (int i = 0; i < n; i++)
		scanf("%d", &w[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < m; i++) {
		int q1, q2;
		scanf("%d %d", &q1, &q2);
		q1--; q2--;
		g[q1].pub(q2);
		g[q2].pub(q1);
	}
	vector<int> s;
	q.pub(s);
	for (int i = 0; i < n; i++)
		if (!was[i]) {
			vector<int> s;
			q.pub(s);
			dfs(i);
		}
	for (int i = 0; i <= 1005; i++)
		for (int j = 0; j <= 1005; j++)
			dp[i][j] = -INF;
	dp[0][0] = 0;
	for (int i = 1; i < q.size(); i++) {
		int sumw = 0, sumb = 0, mab = 0;
		for (int x : q[i])
			sumb += b[x], sumw += w[x];
		for (int w1 = wmax; w1 >= 0; w1--) {
			dp[i][w1] = dp[i - 1][w1];
			if (w1 - sumw >= 0 && dp[i - 1][w1 - sumw] != -INF)
				dp[i][w1] = max(dp[i][w1], dp[i - 1][w1 - sumw] + sumb);
			for (int x : q[i])
				if (w1 - w[x] >= 0 && dp[i - 1][w1 - w[x]] != -INF)
					dp[i][w1] = max(dp[i][w1], dp[i - 1][w1 - w[x]] + b[x]);
			//cout << i << ' ' << w1 << ' ' << dp[i][w1] << endl;
		}
	}
	int ans = 0;
	for (int x = 0; x <= wmax; x++)
		if (dp[(int)q.size() - 1][x] != -INF)
			ans = max(ans, dp[(int)q.size() - 1][x]);
	cout << ans;
}