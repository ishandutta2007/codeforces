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
    
    LL n, a, b;
    cin >> n >> a >> b;
    while (n--)
    {
        int x;
        cin >> x;
        LL maxv = x*a / b;
        int l = 0;
        int r = x;
        int ans = x;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (mid*a / b == maxv) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << x-ans << ' ';
    }
    return 0;
}