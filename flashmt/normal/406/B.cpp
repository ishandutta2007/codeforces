#include <bits/stdc++.h>
using namespace std;

int used[1000100];

int main()
{
    int n, x;
    
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &x), used[x] = 1;
    
    cout << n << endl;
    
    int has = 0;
    for (int i = 1; i <= 1000000; i++)
        if (used[i] && !used[1000001 - i])
        {
            printf("%d ", 1000001 - i); 
            used[1000001 - i] = 1;
            has++;
        }
        
    for (int i = 1; i <= 1000000; i++)
        if (!used[i] && !used[1000001 - i] && has < n)
        {
            printf("%d %d ", i, 1000001 - i);
            used[i] = used[1000001 - i] = 1;
            has += 2;
        }
}