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
int a[N];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int maxv = -1;
    int key = 0;
    for (int i = 0; i < n; i++) if (maxv < a[i]) maxv = a[i], key = i;
    ans += key;
    while (key--)
    {
        swap(a[key], a[key + 1]);
    }
    int minv = INF;
    for (int i = n - 1; i >= 0; i--) if (minv > a[i]) minv = a[i], key = i;
    cout << ans + (n - 1 - key) << endl;
    return 0;
}