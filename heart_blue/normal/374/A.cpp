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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))

const LL INF = 1e7 + 7;
const int N = 2e5 + 10;

vector<int> v[N];
vector<pair<int, int>> vp;
int n, m, a, b, x, y;
int solve(int s, int t)
{
    if (abs(s - a) % x) return INF;
    if (abs(t - b) % y) return INF;
    int u = abs(s - a) / x;
    int v = abs(t - b) / y;
    if ((u - v) % 2) return INF;
    if (v && s - x < 1 && s + x > n) return INF;
    if (u && t - y < 1 && t + y > m) return INF;
    return max(u, v);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> a >> b >> x >> y;
    int ans = min(min(solve(n, m), solve(1, 1)), min(solve(1, m), solve(n, 1)));
    if (ans == INF) cout << "Poor Inna and pony!";
    else cout << ans << endl;
    return 0;
}