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
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int n,m,k;
    MEM(flag,0);
    scanf("%d%d%d", &n, &m, &k);
    int cur = 1;
    while (m--)
    {
        int x;
        scanf("%d", &x);
        flag[x] = 1;
    }
    while (k--)
    {
        if (flag[cur]) break;
        int x, y;
        scanf("%d%d", &x, &y);
        if (x != cur && y != cur) continue;
        if (x == cur) cur = y;
        else cur = x;
    }
    cout << cur << endl;
	return 0;
}