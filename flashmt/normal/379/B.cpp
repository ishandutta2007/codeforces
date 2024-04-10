#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    
    int n, coins[333];
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> coins[i];
    
    for (int i = 0; i < n; i++)
    {
        while (coins[i]--)
        {
            if (i) cout << "PLR";
            else cout << "PRL";
        }
        if (i + 1 < n) cout << "R";
    }
}