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
int a[N];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    MEM(a, 0);
    int cnt = 1;
    a[0] = 1;
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        cur = (cur + i) % n;
        if (!a[cur]) a[cur] = 1, cnt++;
    }
    if (cnt == n) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}