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
const int N = 1e3 + 10;

map<int, int> m;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int x, t, a, b, da, db;
    cin >> x >> t >> a >> b >> da >> db;
    m[0] = 1;
    for (int i = 0; i < t; i++)
    {
        m[a - da*i] = 1;
        for (int j = 0; j < t; j++)
        {
            m[b - db*j] = 1;
            m[a + b - da*i - db*j] = 1;
        }
    }
    if (m.count(x)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}