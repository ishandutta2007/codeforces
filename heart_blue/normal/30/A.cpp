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
const int N = 2e6;
int mypow(int a, int b)
{
    int ret = 1;
    while (b--) ret *= a;
    return ret;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    int a, b, n;
    cin >> a >> b >> n;
    if (a == 0)
    {
        if (b != 0) cout << "No solution" << endl;
        else cout << 0 << endl;
        return 0;
    }
    if (b%a)
    {
        cout << "No solution" << endl;
        return 0;
    }
    int c = b / a;
    if (c < 0 && n % 2 == 0)
    {
        cout << "No solution" << endl;
        return 0;
    }
    double d = pow(abs(c), 1.0 / n);
    if (c < 0) d = -d;
    if (mypow(ceil(d), n) == c)
    {
        cout << ceil(d) << endl;
        return 0;
    }
    if (mypow(floor(d), n) == c)
    {
        cout << floor(d) << endl;
        return 0;
    }
    cout << "No solution" << endl;
    return 0;
}