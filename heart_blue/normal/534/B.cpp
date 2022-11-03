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

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */
    int d, t;
    int a[200];
    int v1, v2;
    cin >> v1 >> v2;
    cin >> t >> d;
    a[1] = v1;
    a[t] = v2;
    for (int i = 2; i < t; i++)
    {
        a[i] = a[i - 1] + d;
    }
    for (int j = t - 1; j > 1; j--)
    {
        a[j] = min(a[j], a[j + 1] + d);
    }
    int sum = 0;
    for (int i = 1; i <= t; i++) sum += a[i];
    cout << sum << endl;
    return 0;
}