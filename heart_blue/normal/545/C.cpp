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
const LL INF = 1000000007;
const int N = 2e5 + 10;
const double eps = 1e-6;
int dp[N][3];
LL x[N];
LL h[N];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> h[i];
    MEM(dp, 0);
    dp[0][1] = 1;
    dp[0][2] = 1;
    for (int i = 1; i < n; i++)
    {
        if (x[i - 1] + h[i - 1] >= x[i])
        {
            dp[i][2] = dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][2]++;
        }
        else
        {
            dp[i][2] = dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
            dp[i][2]++;
        }
        if (x[i - 1] + h[i] < x[i])
        {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
            if (x[i - 1] + h[i - 1] + h[i] < x[i]) dp[i][1] = max(dp[i][1], dp[i - 1][2]);
            dp[i][1]++;
        }
    }
    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;
    return 0;
}