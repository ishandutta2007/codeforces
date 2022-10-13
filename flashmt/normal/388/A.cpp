#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[111], n;
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a, a + n);
    vector <int> piles;
    for (int i = 0; i < n; i++)
    {
        int ok = 0;
        for (int j = 0; j < int(piles.size()); j++)
            if (piles[j] <= a[i])
            {
                piles[j]++;
                ok = 1;
                break;
            }
            
        if (!ok) piles.push_back(1);
    }
    
    cout << piles.size() << endl;
}