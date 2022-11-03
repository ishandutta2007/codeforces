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
const int N = 1e6 + 10;
vector<int> v;
bool check(int a, int b, int x, int y)
{
    if (a > b) swap(a, b);
    if (x > y) swap(x, y);
    if (a > x) swap(a, x), swap(b, y);
    if (a == x || b == y) return false;
    if (b <= x) return false;
    return b < y;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    v.resize(n);
    string ans = "no";
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (i == j) continue;
            if (check(v[i], v[i + 1], v[j], v[j + 1])) ans = "yes";
        }
    }
    cout << ans << endl;
    return 0;
}