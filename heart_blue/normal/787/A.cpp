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
const int N = 1e5 + 10;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b < d)
        swap(b, d), swap(a, c);
    int ans = -1;
    for (int i = 0; i < N; i++)
    {
        if ((b + a * i - d) % c == 0)
        {
            ans = b + a * i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}