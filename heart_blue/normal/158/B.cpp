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
const int N = 4e4 + 10;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int a[5];
    MEM(a, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x] ++;
    }
    int ans = 0;
    ans += a[4];
    ans += a[3];
    a[1] -= min(a[3], a[1]);
    ans += a[2] / 2;
    a[2] &= 1;
    if (a[2])
    {
        ans++;
        a[1] -= min(a[2] * 2, a[1]);
    }
    ans += a[1] / 4;
    if (a[1] % 4) ans++;
    cout << ans << endl;
    return 0;
}