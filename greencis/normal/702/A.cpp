#include <bits/stdc++.h>
using namespace std;

int n, a[200105], ans = 1;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int cur = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i-1]) ++cur;
        else cur = 1;
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}