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
    int l, r;
    cin >> l >> r;
    int key = 2;
    int ans = r / 2 - (l - 1) / 2;
    if (ans < r / 3 - (l - 1) / 3)
        ans = r / 3 - (l - 1) / 3, key = 3;
    if (ans < r / l)
        ans = r / l, key = l;
    cout << key << endl;
    return 0;
}