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

int n;
int color[2 * 100007];
vector<int> g[2 * 100007];
ll sum[2 * 100007];
ll ma[2 * 100007];
ll dp[2 * 100007];


void dfs(int v, int pred) {
	sum[v] = color[v];
	ma[v] = -LINF;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (to != pred) {
			dfs(to, v);
			sum[v] += sum[to];
			ma[v] = max(ma[v], ma[to]);
		}
	}
	ma[v] = max(ma[v], sum[v]);
}

void dfs2(int v, int pred) {
	ll ma1 = -LINF, ma2 = -LINF;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (to != pred) {
			dfs2(to, v);
			dp[v] = max(dp[v], dp[to]);
			if (ma[to] > ma1) {
				ma2 = ma1;
				ma1 = ma[to];
			} else {
				if (ma[to] > ma2)
					ma2 = ma[to];
			}
		}
	}
	if (ma1 != -LINF && ma2 != -LINF)
		dp[v] = max(dp[v], ma1 + ma2);
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
	for (int i = 0; i < 2 * 100007; i++)
		dp[i] = -LINF;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &color[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		g[a].pub(b);
		g[b].pub(a);
	}
	dfs(0, -1);
	dfs2(0, -1);
	if (dp[0] == -LINF)
		cout << "Impossible";
	else
		cout << dp[0];
}