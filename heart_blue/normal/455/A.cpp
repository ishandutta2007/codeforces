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
const int N = 4e5 + 10;
LL a[N];
LL dp[N][2];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    MEM(a, 0);
    MEM(dp, 0);
    int n;
    cin >> n;
    int x;
    int maxv = 0;
    for (int i = 0; i < n; i++) cin >> x, a[x]++,maxv = max(maxv, x);
    for (int i = 1; i <= maxv; i++)
    {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
        dp[i][1] = dp[i - 1][0] + i*a[i];
    }
    cout << max(dp[maxv][0], dp[maxv][1]) << endl;
    return 0;
}