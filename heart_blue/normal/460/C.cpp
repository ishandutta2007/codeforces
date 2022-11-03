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
const int N = 2e5 + 10;
const int M = N;
int a[N];
int t[N];

int n, m, w;
bool check(int x)
{
    int cnt = 0;
    MEM(t, 0);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cnt -= t[i];
        if (a[i] + cnt < x)
        {
            total += x - cnt - a[i];
            t[i + w] = x - cnt - a[i];
            cnt = x - a[i];
            
            
        }
        if (total > m) return false;
    }
    return true;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> w;
    int maxv = 0;
    for (int i = 0; i < n; i++) cin >> a[i], maxv = max(a[i], maxv);
    maxv += m;
    int l = 1;
    int r = maxv;
    int ans = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (check(m)) ans = m, l = m + 1;
        else r = m - 1;
    }
    cout << ans << endl;

    
    return 0;

}