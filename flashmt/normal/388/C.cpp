#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[111], ciel = 0, jiro = 0, s;
    vector <int> oddPiles;
    
    cin >> n;
    while (n--)
    {
        cin >> s;
        for (int i = 1; i <= s; i++) 
        {
            cin >> a[i];
            if (i * 2 <= s) ciel += a[i];
            if ((s + 1 - i) * 2 <= s) jiro += a[i];
        }
        
        if (s % 2) oddPiles.push_back(a[s / 2 + 1]);
    }
    
    sort(oddPiles.begin(), oddPiles.end(), greater<int>());
    for (int i = 0; i < oddPiles.size(); i += 2)
    {
        ciel += oddPiles[i];
        if (i + 1 < oddPiles.size()) jiro += oddPiles[i + 1];
    }
    
    cout << ciel << ' ' << jiro << endl;
}