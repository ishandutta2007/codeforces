#include <bits/stdc++.h>
using namespace std;

int n, ans[300300];
pair <int,int> a[300300];

int main()
{
    ios::sync_with_stdio(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
    sort(a, a + n);
    
    ans[a[0].second] = a[0].first;
    for (int i = 1; i < n; i++) ans[a[i].second] = max(a[i].first, ans[a[i - 1].second] + 1);
    
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}