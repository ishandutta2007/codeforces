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
    
    int x, y;
    cin >> x >> y;
    int ans = 0;
    while (1)
    {
        ans ^= 1;
        if (ans & 1)
        {
            int t = 220;
            if (x * 100 + y * 10 < 220) break;
            int s = min(2, x);
            t -= s * 100;
            x -= s;
            y -= t / 10;
            if (x < 0 || y < 0) break;
        }
        else
        {
            if (x * 100 + y * 10 < 220) break;
            int t = 220;
            if (y >= 22) y -= 22, t -= 220;
            else if (y >= 12) y -= 12, t -= 120;
            else if (y >= 2) y -= 2, t -= 20;
            else break;
            x -= t / 100;
            if (x < 0) break;
        }
    }
    if (!ans) cout << "Ciel" << endl;
    else cout << "Hanako" << endl;
    return 0;
}