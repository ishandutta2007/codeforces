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


int a[15][15];

int main(){
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++){
		if (i == 1 || j == 1) a[i][j] = 1;
		else a[i][j] = a[i - 1][j] + a[i][j - 1];
		ans = max(ans, a[i][j]);
	}
	printf("%d\n", ans);
}