#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> n >> m;
    for (int i = m; i <= n; i += m)
        if (i * 2 >= n) 
        {
            cout << i << endl;
            return 0;
        }
    cout << -1 << endl;     
}