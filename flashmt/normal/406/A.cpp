#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, Q, type, x, value = 0;
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &x);
            if (i == j) value ^= x;
        }

    cin >> Q;
    while (Q--)
    {
        scanf("%d", &type);
        if (type == 1)
        {
            scanf("%d", &x);
            value ^= 1;
        } 
        
        if (type == 2)
        {
            scanf("%d", &x);
            value ^= 1;
        }
        
        if (type == 3) printf("%d", value);
    }
}