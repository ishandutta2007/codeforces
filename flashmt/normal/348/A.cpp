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

int main()
{
    int n, a[100100];
    long long low = 0, high = 1LL << 40, ans = high;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], low = max(low, 1LL * a[i]);
    
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++) sum += mid - a[i];
        if (sum >= mid) ans = mid, high = mid - 1;
        else low = mid + 1;
    }
    
    cout << ans << endl;
}