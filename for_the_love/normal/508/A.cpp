#include <set>
#include <map>
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

typedef long double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int n, m, k, x, y, a[1005][1005];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	memset(a, -1, sizeof(a));
	for (int i = 0; i < k; i++){
		scanf("%d%d", &x, &y);
		if (a[x][y] == -1) a[x][y] = i;
	}
	int ans = 1e9 + 7;
	for (int i = 1; i < n; i++)
	for (int j = 1; j < m; j++)
	if (a[i][j] != -1 && a[i + 1][j] != -1 && a[i][j + 1] != -1 && a[i + 1][j + 1] != -1){
		ans = min(ans, max(max(a[i][j], a[i + 1][j]), max(a[i][j + 1], a[i + 1][j + 1])));
	}
	if (ans == 1e9 + 7) ans = -1;
	printf("%d\n", ans + 1);
}