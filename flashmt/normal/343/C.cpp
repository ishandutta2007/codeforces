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

int m, n;
long long h[100100], p[100100];

int possible(long long range)
{
    int j = 0;
    for (int i = 0; i < n && j < m; i++)
        if (p[j] >= h[i])
            while (j < m && p[j] - h[i] <= range) j++;
        else
            if (h[i] - p[j] <= range)
            {
                int jj = j;
                while (j < m && p[j] <= h[i]) j++;
                while (j < m && p[j] - p[jj] + min(p[j] - h[i], h[i] - p[jj]) <= range) j++;
            }
    return j >= m;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) scanf("%I64d", h + i);
    for (int i = 0; i < m; i++) scanf("%I64d", p + i);
    
    long long low = 0, high = 1LL << 50, ans = high;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (possible(mid)) ans = mid, high = mid - 1;
        else low = mid + 1;
    }       
    
    cout << ans << endl;
}