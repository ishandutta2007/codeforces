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
const int N = 2e5 + 1;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int r, g, b;
    cin >> r >> g >> b;
    int ans = 0;
    r = r / 2 + r % 2;
    g = g / 2 + g % 2;
    b = b / 2 + b % 2;
    if (r != 0) r = (r - 1) * 3 + 30;
    if (g != 0) g = (g - 1) * 3 + 1 + 30;
    if (b != 0) b = (b - 1) * 3 + 2 + 30;
    cout << max(r, max(g, b)) << endl;
    return 0;
}