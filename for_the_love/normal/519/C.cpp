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
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = 0;
	for (int i = 0; i <= n; i++)
	if (i * 2 <= m){
		ans = max(ans, i + min(m - i * 2, (n - i) / 2));
	}	
	printf("%d\n", ans);
}