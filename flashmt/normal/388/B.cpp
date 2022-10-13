#include <bits/stdc++.h>
using namespace std;

int a[1010][1010], n;

void addPath(int pos, int digit)
{
    int prev = 0, next;
    for (int i = 0; i < 10; i++)
    {
        int lim = 10;
        if (i == pos) lim = digit;
        else
            if (i > pos) lim = 1;
            
        next = n + lim;
        if (i == 9) next = 1;
            
        for (int j = 0; j < lim; j++) 
        {
            a[prev][n + j] = a[n + j][prev] = 1;
            a[next][n + j] = a[n + j][next] = 1;
        }
        
        prev = next;
        if (i < 9) n = next + 1;
        else n++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    
    int k;
    cin >> k;
    
    n = 2;
    for (int i = 0; k; i++)
    {
        addPath(i, k % 10);
        k /= 10;
    }
    
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cout << (a[i][j] ? 'Y' : 'N');
        cout << "\n";
    }
}