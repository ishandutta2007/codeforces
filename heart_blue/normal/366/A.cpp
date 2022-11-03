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
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a[4];
    int n;
    cin >> n;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++) cin >> a[j];
        for (int s = 0; s < 2; s++)
        {
            for (int t = 2; t < 4; t++)
            {
                if (a[s] + a[t] <= n)
                {
                    cout << i + 1 << ' ' << a[s] << ' ' << n - a[s] << endl;
                    exit(0);
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}