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

int a[N], b[N], c[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) cin >> b[i];
    for (int i = 0; i < n - 2; i++) cin >> c[i];
    int l, r;
    sort(a, a + n);
    sort(b, b + n - 1);
    sort(c, c + n - 2);
    b[n] = -1;
    c[n - 1] = -1;
    l = r = 0;
    while (l < n)
    {
        if (a[l] == b[r])
        {
            l++, r++;
            continue;
        }
        cout << a[l] << endl;
        break;
    }
    l = r = 0;
    while (l < n - 1 )
    {
        if (b[l] == c[r])
        {
            l++, r++;
            continue;
        }
        cout << b[l] << endl;
        break;
    }
    return 0;
}