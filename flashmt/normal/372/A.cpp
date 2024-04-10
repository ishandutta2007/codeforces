#include <bits/stdc++.h>
using namespace std;

int n, a[500500], held[500500];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    
    int low = 1, high = n / 2, res = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2, ok = 1;
        for (int i = 0; i < mid; i++)
            if (a[i] * 2 > a[n - mid + i])
            {
                ok = 0; break;
            }
            
        if (ok) res = mid, low = mid + 1;
        else high = mid - 1;
    }
        
    cout << n - res << endl;
}