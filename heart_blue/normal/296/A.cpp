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
const int N = 1e3 + 10;
int a[N];
int main()
{
    //freopen("input.txt","r",stdin);
    int n;
    MEM(a, 0);
    int x;
    cin >> n;
    int maxv = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[x]++;
        maxv = max(maxv, x);
    }
    int ans = 0;
    for (int i = 0; i <= maxv; i++)
    {
        ans = max(ans, a[i]);
    }
    if (ans <= (n + 1) / 2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}