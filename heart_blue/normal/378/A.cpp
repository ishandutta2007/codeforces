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

const LL INF = 1e7 + 7;
const int N = 1e3 + 10;


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a[3] = { 0 };
    int x, y;
    cin >> x >> y;
    for (int i = 1; i <= 6; i++)
    {
        int t1 = abs(x - i);
        int t2 = abs(y - i);
        if (t1 < t2) a[0]++;
        if (t1 == t2) a[1]++;
        if (t1 > t2) a[2]++;
    }
    cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
    return 0;
}