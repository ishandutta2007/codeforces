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
const LL INF = 1e9 + 1;
const int N = 1e6 + 10;
int a[N];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            for (int s = 1; s < 10; s++)
            {
                for (int t = 1; t < 10; t++)
                {
                    if (i + j != r1) continue;
                    if (s + t != r2) continue;
                    if (i + s != c1) continue;
                    if (j + t != c2) continue;
                    if (i + t != d1) continue;
                    if (j + s != d2) continue;
                    if (i == j) continue;
                    if (i == s) continue;
                    if (i == t) continue;
                    if (j == s) continue;
                    if (j == t) continue;
                    if (s == t) continue;
                    cout << i << ' ' << j << endl;
                    cout << s << ' ' << t << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}