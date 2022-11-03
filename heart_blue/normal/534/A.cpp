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
const LL INF = 1e9 + 7;

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */
    int n;
    cin >> n;
    if (n == 3)
    {
        cout << 2 << endl;
        cout << 1 << ' ' << 3 << endl;
    }
    else if (n <= 2)
    {
        cout << 1 << endl;
        cout << 1 << endl;
    }
    else
    {
        int t = n / 2+1;
        cout << n << endl;
        if (n & 1) cout << n << ' ';
        for (int i = 1; i <= n / 2; i++)
        {
            cout << t << ' ' << i << ' ';
            t++;
        }
    }
    return 0;
}