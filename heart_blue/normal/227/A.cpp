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
const int N = 3e3 + 10;
int check(LL a, LL b)
{
    if (a == 0)
    {
        if (b > 0) return 2;
        else return 4;
    }
    if (b == 0)
    {
        if (a > 0) return 1;
        else return 3;
    }
    if (a > 0)
    {
        if (b > 0) return 1;
        else return 4;
    }
    else
    {
        if (b > 0) return 2;
        else return 3;
    }

}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    LL a, b, c, d, x, y;
    cin >> a >> b >> c >> d >> x >> y;
    a = c - a, b = d - b;
    x -= c, y -= d;
    if (a*y == x*b)
    {
        cout << "TOWARDS" << endl;
    }
    else
    {
        swap(x, y);
        x = -x;
        if (check(a,b) == check(x,y)) cout << "RIGHT" << endl;
        else cout << "LEFT" << endl;
    }

    return 0;
}