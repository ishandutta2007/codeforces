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
const LL INF = 1e9+1;
const int N = 1e3 + 10;
int a[N][N];
int dp1[N][N], dp2[N][N], dp3[N][N], dp4[N][N];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    MEM(dp1, 0);
    MEM(dp2, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + a[i][j];
        }
    }
    for (int i = n; i > 0; i--)
    {
        for (int j = m; j > 0; j--)
        {
            dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]) + a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j > 0; j--)
        {
            dp3[i][j] = max(dp3[i - 1][j], dp3[i][j + 1]) + a[i][j];
        }
    }
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            dp4[i][j] = max(dp4[i + 1][j], dp4[i][j - 1]) + a[i][j];
        }
    }
    
    int ans = 0;
    for (int i = 2; i < n; i++)
    {
        for (int j = 2; j < m; j++)
        {
            ans = max(max(dp1[i][j - 1] + dp2[i][j + 1] + dp3[i - 1][j] + dp4[i + 1][j], dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j + 1] + dp4[i][j - 1]), ans);
        }
    }
    cout << ans << endl;

    return 0;
}