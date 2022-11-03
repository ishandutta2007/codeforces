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

const int INF = 1e5 + 7;
const int N = 1e3 + 10;


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    int maxv = 0;
    int minv = INF;
    while (n--)
    {
        int x;
        cin >> x;
        minv = min(minv, x);
        maxv = max(maxv, x);
    }
    maxv = max(maxv, minv * 2);
    while (m--)
    {
        int x;
        cin >> x;
        if (x <= maxv)
        {
            maxv = -1;
            break;
        }
    }
    cout << maxv << endl;
    return 0;
}