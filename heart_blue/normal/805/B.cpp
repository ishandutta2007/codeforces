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
#include <cassert>
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x), (y), sizeof(x))
const LL INF = 1e9 + 7;
const int N = 4e3 + 10;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i * 2 <= n; i++)
    {
        if (i & 1)
            putchar('a'), putchar('a');
        else
            putchar('b'), putchar('b');
    }
    if (n & 1)
    {
        n >>= 1;
        if (n & 1)
            putchar('b');
        else
            putchar('a');
    }

    return 0;
}