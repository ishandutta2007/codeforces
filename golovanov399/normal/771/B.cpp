#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<string> names(n);
    for (int i = 0; i < n; i++)
    {
        names[i] = string() + (char)(i / 26 + 'A') + (char)(i % 26 + 'a');
    }
    
    for (int i = k - 1; i < n; i++)
    {
        string x;
        cin >> x;
        
        if (x == "NO")
            names[i] = names[i - (k - 1)];
    }
    
    for (int i = 0; i < n; i++)
        cout << names[i] << " ";
    cout << endl;
    
    return 0;
}