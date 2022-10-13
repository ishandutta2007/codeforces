#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, a[100100], low, high, step[1000100];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    cin >> high >> low;
    
    sort(a, a + n);
    n = unique(a, a + n) - a;
    for (int i = 0; i <= high - low; i++) step[i] = 1;
    
    for (int i = 0; i < n; i++)
    {
        long long cur = low;
        if (cur % a[i]) cur += a[i] - cur % a[i];
        while (cur <= high) step[cur - low] = max(step[cur - low], a[i] - 1), cur += a[i];
    }
    
    int ans = 0, cur = low, maxNext = low + step[0];
    while (cur < high)
    {
        int old = cur;
        cur = maxNext; 
        ans++;
        if (cur >= high) break;
        maxNext = 0;
        for (int i = old + 1; i <= cur; i++) maxNext = max(maxNext, step[i - low] + i);
    }
    
    cout << ans << endl;
}