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
const int INF = 1e9 + 3;
const int N = 1e2 + 10;
double dp[N][N][N];
int flag[N][N][N];
int r, s, p;
double getans(int i, int j, int k)
{
    if (i > r || j > s || k > p) return 0;
    if (flag[i][j][k]) return dp[i][j][k];
    flag[i][j][k] = 1;
    double t = i*(i - 1) + j*(j - 1) + k*(k - 1);
    int sum = i + j + k;
    if(sum != 1) t /= sum*(sum - 1);
    else t = 0;
    if (abs(t - 1) < 1e-7) t = 0;
    sum *= sum + 1;
    sum /= 2;
    return dp[i][j][k] = ((i*(j + 1)) *getans(i, j + 1, k) + j*(k + 1)*getans(i, j, k + 1) + k*(i + 1)*getans(i + 1, j, k)) / sum/(1-t);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> r >> s >> p;
    MEM(flag, 0);
    flag[r][s][p] = 1;
    dp[r][s][p] = 1;
    double ans[3] = { 0, 0, 0 };
    for (int i = 1; i <= r; i++) ans[0] += getans(i, 0, 0);
    for (int i = 1; i <= s; i++) ans[1] += getans(0, i, 0);
    for (int i = 1; i <= p; i++) ans[2] += getans(0, 0, i);
    double sum = ans[0] + ans[1] + ans[2];
    printf("%.15f %.15f %.15f\n", ans[0] / sum, ans[1] / sum, ans[2] / sum);
    return 0;
}