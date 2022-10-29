#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, LL> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

DB p; int n, m;
DB f[2005][2005];
int main(){
	scanf("%d%lf%d", &n, &p, &m);
	f[0][0] = 1;
	for (int i = 1; i <= m; i++)
	for (int j = 0; j <= n; j++){
		if (j == n) f[i][j] += f[i - 1][j]; else f[i][j] += f[i - 1][j] * (1 - p);
		if (j) f[i][j] += f[i - 1][j - 1] * p;
	}
	DB ans = 0;
	for (int i = 1; i <= n; i++)
		ans += f[m][i] * i;
	printf("%.8lf\n", ans);
}