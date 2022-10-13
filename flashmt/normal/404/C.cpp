#include <bits/stdc++.h>
using namespace std;

int n, k, d[100100];
vector <int> dList[100100], a[100100];

int solve()
{
    if (dList[0].size() != 1) return 0;
    
    for (int i = 1; i < n; i++)
    {
        int thisSize = dList[i].size();
        long long lastSize = dList[i - 1].size();
        int each = (i == 1 ? k : k - 1);
        
        if (thisSize > lastSize * each) return 0;
        
        for (int j = 0; j < int(dList[i].size()); j++) 
        {
            int x = dList[i][j], y = dList[i - 1][j / each];
            a[x].push_back(y);
            a[y].push_back(x);
        }
    }
    
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) 
    {
        cin >> d[i];
        dList[d[i]].push_back(i);
    }
    
    if (!solve()) cout << "-1\n";
    else
    {
        cout << n - 1 << endl;
        for (int x = 1; x <= n; x++)
            for (int i = 0; i < int(a[x].size()); i++)
                if (a[x][i] > x) cout << x << ' ' << a[x][i] << endl;
    }
}