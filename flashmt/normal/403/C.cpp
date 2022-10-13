#include <bits/stdc++.h>
using namespace std;

int n, a[2222][2222], num[2222], low[2222], st[2222], last, step, d[2222], region;

void visit(int x)
{
    num[x] = low[x] = ++step;
    st[++last] = x;
    for (int i = 1; i <= n; i++)
        if (a[x][i] && !d[i] && i != x)
        {
            if (num[i]) low[x] = min(low[x], num[i]);
            else
            {
                visit(i);
                low[x] = min(low[x], low[i]);
            }
        }           
        
    if (num[x] != low[x]) return;
    region++;
    while (1)
    {
        int y = st[last--];
        d[y] = 1;
        if (y == x) return;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
            
    for (int i = 1; i <= n; i++)
        if (!d[i])
            visit(i);
            
    cout << (region == 1 ? "YES" : "NO") << endl;
}