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

const int INF = 1e6 + 3;
const int N = 1e3 + 1;
char ch[N][N];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    MEM(ch, 0);
    int a, b, c, d;
    int n, m;
    cin >> n >> m;
    a = n;
    b = 0;
    c = m;
    d = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ch[i][j];
            if (ch[i][j] == '*') a = min(a, i), b = max(b, i), c = min(j, c), d = max(j, d);
        }
    }
    for (int i = a; i <= b; i++)
    {
        for (int j = c; j <= d; j++)
        {
            cout << ch[i][j];
        }
        cout << endl;
    }
    return 0;
}