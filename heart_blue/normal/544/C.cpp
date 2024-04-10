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
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
int dp[N][N];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, b, mod;
    cin >> n >> m >> b >> mod;
    MEM(dp, 0);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        for (int j = 1; j <= m; j++)
        {
            for (int k = a; k <= b; k++)
            {
                dp[j][k] += dp[j - 1][k - a];
                dp[j][k] %= mod;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= b; i++)
    {
        ans += dp[m][i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}