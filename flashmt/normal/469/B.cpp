#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int m, n, L, R;
    pair <int,int> a[55], b[55];
    cin >> m >> n >> L >> R;
    for (int i = 0; i < m; i++) cin >> a[i].first >> a[i].second;
    for (int i = 0; i < n; i++) cin >> b[i].first >> b[i].second;
    
    int ans = 0;
    for (int shift = L; shift <= R; shift++)
    {
        int ok = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (max(a[i].first, b[j].first + shift) <= min(a[i].second, b[j].second + shift)) 
                    ok = 1;
        ans += ok;
    }
    
    cout << ans << endl;
}