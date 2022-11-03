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
int v[N];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a;
    int t;
    int m;
    cin >> a >> m;
    a %= m;
    int flag = 0;
    while (1)
    {
        if (a % m == 0) flag = 1;
        if (flag) break;
        if (v[a]) break;
        v[a] = 1;
        a += a%m;
        a %= m;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}