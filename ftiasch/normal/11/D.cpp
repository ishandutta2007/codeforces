// Codeforces Beta Round #11
// Problem D -- A Simple Task
#include <iostream>
#include <cstring>

#define maxN 19
#define maxM 524288 // 1 << 19

using namespace std;

int n, m, g[maxN][maxN], qx[maxN * maxM], qs[maxN * maxM];
long long f[maxN][maxM];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    memset(g, 0, sizeof(g));
    for(int i = 0; i != m; ++ i)
    {
        int a, b;
        cin >> a >> b;
        g[a - 1][b - 1] = g[b - 1][a - 1] = true;
    }
    long long ans = 0;
    for(int i = 0; i != n; ++ i)
    {
        memset(f, 0, sizeof(f));
        int hd = 0, tl = 0;
        f[qx[tl] = i][qs[tl] = 1 << i] = 1, tl ++;
        while(hd != tl)
        {
            if(g[i][qx[hd]])
                ans += f[qx[hd]][qs[hd]];
            for(int j = i; j != n; ++ j)
                if(g[qx[hd]][j] && !(qs[hd] & (1 << j)))
                {
                    int temp = qs[hd] | (1 << j);
                    if(!f[j][temp])
                        qx[tl] = j, qs[tl] = temp, tl ++;
                    f[j][temp] += f[qx[hd]][qs[hd]];
                }
            hd ++;
        }
    }
    cout << (ans - m) / 2 << "\n";
    return 0;
}