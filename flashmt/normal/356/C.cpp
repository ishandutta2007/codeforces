#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int oo = 27081993;

int solve134(int x, int y, int z)
{
    int res = x / 3 * 2;
    y += x / 3;
    x %= 3;
    
    if (!x) return res;
    
    if (x == 1)
    {
        if (y) return res + 1;
        if (z > 1) return res + 2;
        return oo;
    }
    
    if (z || y > 1) return res + 2;
    return oo;
}

int solve234(int x, int y, int z)
{
    int res = x / 3 * 2;
    y += res;
    x %= 3;
    
    if (!x) return res;
    
    if (x == 1)
    {
        if (z) return res + 1;
        if (y > 1) return res + 2;
        return oo;
    }
    
    return res + 2;
}

int main()
{
    int n, cnt[5] = {0}, x, total = 0;
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &x), cnt[x]++, total += x;
    
    int ans = total + 1;
    int used = min(cnt[1], cnt[2]);
    cnt[1] -= used;
    cnt[2] -= used;
    cnt[3] += used;
    
    if (cnt[1]) ans = min(ans, solve134(cnt[1], cnt[3], cnt[4]) + used);
    else
        if (cnt[2]) ans = min(ans, solve234(cnt[2], cnt[3], cnt[4]) + used);
        else ans = min(ans, used);
    
    if (ans > total) ans = -1;
    cout << ans << endl;
}