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
    int a[3][6] = {0, 1, 2, 2, 1, 0,
                   1, 0, 0, 1, 2, 2,
                   2, 2, 1, 0, 0, 1};
    int n, x;
    cin >> n >> x;
    n %= 6;
    for (int i = 0; i < 3; i++)
    {
        if (a[i][n] == x)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}