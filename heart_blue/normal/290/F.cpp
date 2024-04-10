#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int vis[N], a[N][N], deg[N];
int n, m;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (a[u][v] || u == v) continue;
        a[u][v] = a[v][u] = 1;
        deg[u]++, deg[v]++;
    }
    for (int st = 1; st <= n; st++) {
        memset(vis, 0, sizeof(vis));
        int turn, cur = st;
        vis[st] = 1;
        for (turn = 1; turn < n; turn++) {
            int p = 0;
            for (int i = 1; i <= n; i++) {
                if (a[cur][i] && !vis[i] && (p == 0 || deg[p] > deg[i])) {
                    p = i;
                }
            }
            if (p == 0) break;
            cur = p, vis[cur] = 1;
        }
        if (turn == n) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
	return 0;
}