#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, cost, rate[111], ans = 0;
    
    cin >> n >> cost;
    for (int i = 0; i < n; i++) cin >> rate[i];
    
    for (int i = 1; i < n; i++) ans = max(ans, rate[i - 1] - rate[i] - cost);
    cout << ans << endl;
}