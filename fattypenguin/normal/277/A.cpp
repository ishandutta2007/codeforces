#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

bool know[1000][1000];
int mat[1000][1000];

int vis[1000];
	int n, m;

void dfs(int u) {
	vis[u] = true;
	for (int i = 0; i < n; ++i) {
		if (!vis[i] && mat[u][i]) {
			dfs(i);
		}
	}
}

int main() {
	cin >> n >> m;
	bool allZero = true;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			allZero = false;
			int t;
			scanf("%d", &t);
			know[i][t - 1] = true;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				if (know[i][k] && know[j][k]) {
					mat[i][j] = true;
				}
			}
		}
	}

	int cost = 0;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			dfs(i);
			++cost;
		}
	}

	if (allZero) {
		cost = n + 1;
	}
	cout << cost - 1 << endl;

	return 0;
}