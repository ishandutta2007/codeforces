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

VI e[100007];
int n;

double ans = 0.0;

void dfs(int x, int fa, int path) {
	ans += 1.0 / (path + 1);
	TR(it, e[x]) {
		if (*it != fa) {
			dfs(*it, x, path + 1);
		}
	}
}

int main() {
	cin >> n;
	REP(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		e[u].PB(v);
		e[v].PB(u);
	}

	dfs(0, -1, 0);
	printf("%.10f\n", ans);


	return 0;
}