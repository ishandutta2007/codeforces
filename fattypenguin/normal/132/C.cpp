#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define REP(i,n) for (int i = 0;i < n;++i)
#define FILL(x,c) memset(x,c,sizeof(x))

int d[2] = {1,-1};

int f[2][2][201][2];
//  f[n][odd][where]

char s[107];
int n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin>>s;
    n = strlen(s);
    cin>>m;
    FILL(f[0],0x7f);
    f[0][0][100][0] = 0;
    REP(i,n)
    {
        int now = i & 1,next = now ^ 1;
        FILL(f[next],0x7f);
        REP(j,2) REP(k,201) REP(w,2)
        if (f[now][j][k][w] != 0x7f7f7f7f)
        {
            if (s[i] == 'F')
            {
                f[next][j][k+d[w]][w] = min(f[next][j][k+d[w]][w],f[now][j][k][w]);
                if (f[now][j][k][w]+1<=m)
                    f[next][j^1][k][w^1] = min(f[next][j^1][k][w^1],f[now][j][k][w] + 1);
            }
            else
            {
                f[next][j][k][w^1] = min(f[next][j][k][w^1],f[now][j][k][w]);
                int x= f[now][j][k][w]+1,y = m;
                if (f[now][j][k][w]+1<=m)
                    f[next][j^1][k+d[w]][w] = min(f[next][j^1][k+d[w]][w],f[now][j][k][w] + 1);
            }
        }
    }
    int ans = 0;
    REP(i,2) REP(k,201) REP(w,2)
        if (f[n&1][i][k][w] < 0x7f7f7f7f && ((m-f[n&1][i][k][w])&1)==0)
            ans = max(ans,abs(k-100));
    cout<< ans << endl;
    return 0;
}