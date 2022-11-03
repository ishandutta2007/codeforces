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
const LL INF = 1e17;
const int N = 1e5 + 10;
LL gcd(LL n, LL m)
{
    if (n%m) return gcd(m, n%m);
    else return m;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    LL l, r;
    int flag = 0;
    cin >> l >> r;
    for (LL i = l; i <= r; i++)
    {
        for (LL j = i + 1; j <= r; j++)
        {
            for (LL k = j + 1; k <= r; k++)
            {
                int t = 0;
                if (gcd(i, j) != 1) continue;
                if (gcd(i, k) == 1) continue;
                if (gcd(j, k) != 1) continue;

                flag = 1;
                cout << i << ' ' << j << ' ' << k << endl;
                break;

            }
            if (flag) break;
        }
        if (flag) break;
    }
    if (!flag) cout << -1 << endl;
    return 0;
}