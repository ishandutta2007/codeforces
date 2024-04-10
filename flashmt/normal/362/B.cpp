#include <bits/stdc++.h>
using namespace std;


int main()
{
    int dirty[3333] = {0}, m, n;
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> dirty[i];
    sort(dirty, dirty + m);
    
    for (int i = 2; i < m; i++)
        if (dirty[i] == dirty[i - 1] + 1 && dirty[i] == dirty[i - 2] + 2)
        {
            puts("NO");
            return 0;
        }
        
    if (m > 0 && (dirty[0] == 1 || dirty[m - 1] == n))
    {
        puts("NO");
        return 0;
    }
        
    puts("YES");
}