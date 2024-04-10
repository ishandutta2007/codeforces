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

const int INF = 1e9 + 7;
const int N = 1e3 + 10;



int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int x, y;
    cin >> x >> y;
    int t = abs(x) + abs(y);
    int a[4] = { t, 0, 0, t };
    if (x < 0) a[0] = -a[0];
    if (y < 0) a[3] = -a[3];
    if (a[0] > a[2]) swap(a[0], a[2]), swap(a[1], a[3]);
    for (int i = 0; i < 4; i++) cout << a[i] << ' ';
    return 0;
}