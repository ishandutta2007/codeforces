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
const int N = 1e5 + 10;
int a[N];
int flag[N];
void init()
{
    MEM(flag, 0);
    MEM(a, 0);
}
int lowbit(int x)
{
    return x&-x;
}
void add(int x)
{
    flag[x] = 1;
    while (x < N)
    {
        a[x]++;
        x += lowbit(x);
    }
}
int sum(int x)
{
    int ret = 0;
    while (x)
    {
        ret += a[x];
        x -= lowbit(x);
    }
    return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    init();
	int n;
    cin >> n;
    int last = n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        add(x);
        int up = i - sum(x - 1);
        if (n - x + 1 == up)
        {
            int f = 0;
            while (flag[last])
            {
                if (f) putchar(' ');
                printf("%d", last);
                last--;
                f = 1;
            }
        }
        puts("");
    }
	return 0;
}