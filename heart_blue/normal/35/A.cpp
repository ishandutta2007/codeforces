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
const int N = 2e6;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    int a[4];
    int n;
    cin >> n;
    MEM(a, 0);
    a[n] = 1;
    int t = 3;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        swap(a[x], a[y]);
    }
    for (int i = 1; i <= 3; i++)
    {
        if (a[i])
        {
            cout << i << endl;
        }
    }
    return 0;
}