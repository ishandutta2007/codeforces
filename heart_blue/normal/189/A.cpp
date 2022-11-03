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

const int INF = 1e9 + 7;
const int N = 1e3 + 10;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int ans = 0;
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    for (int i = 0; i *a <= n; i++)
    {
        int m = n - i*a;
        for (int j = 0; j*b <= m; j++)
        {
            int t = m - j*b;
            if (t%c) continue;
            ans = max(ans, i + j + t / c);
            
        }
    }
    cout << ans << endl;
    return 0;
}