#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int n, x, a, q, akt, i, poz[4], t[N];

int main()
{
    ios_base::sync_with_stdio(0);
    
    scanf("%d%d", &n, &q);
    
    poz[1] = 0;
    poz[2] = 1;
    
    while(q--)
    {
        scanf("%d", &a);
        if (a == 1)
        {
            scanf("%d", &x);
        }
        
        for(i = 1; i <= 2; i++)
        {
            if (a == 1)
            {
                poz[i] += n + x;
                poz[i] %= n;
            }
            else
            {
                if (poz[i] % 2 == 0)
                {
                    poz[i]++;
                }
                else
                {
                    poz[i]--;
                }
            }
        }
    }
    
    
    t[(n + poz[1] - 1) % n] = 1;
    akt = 1;
    for(i = poz[1]; i < poz[1] + n; i += 2)
    {
        t[i % n] = akt;
        akt += 2;
    }
    
    akt = 2;
    for(i = poz[2]; i < poz[2] + n; i += 2)
    {
        t[i % n] = akt;
        akt += 2;
    }
    
    for(i = 0; i < n; i++)
    {
        
        
        
        
        
        printf("%d ", t[i]);
    }
    printf("\n");
    
    
return 0;
}