#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

#include <assert.h>

using namespace std;

#define rep(i,n) for (int i = 0;i < n;++i)
#define CLEAR(x) memset(x,0,sizeof(x))

int mat[21][21];
long long f[1 << 19][19];
int where[1 << 19];
int n,m;
long long ans = 0;

inline int lb(int x) {return x & -x;}

int main()
{
    cin >> n >> m;
    CLEAR(mat);
    rep(i,m)
    {
        int a,b;
        cin >> a >> b;
        --a,--b;
        mat[a][b] = mat[b][a] = 1;
    }
    rep(i,n) where[1 << i] = i;
    CLEAR(f);
    rep(i,n) f[1<<i][i] = 1;
    rep(i,(1<<n)) rep(j,n)
        if (f[i][j])
        {
            if (!f[i][j]) continue;
            for (int k = where[lb(i)]+1;k<n;++k)
                if(mat[k][j] && !((1<<k)&i))
                    f[i|(1<<k)][k] += f[i][j];
        }
    rep(i,(1<<n)) rep(j,n)
        if (f[i][j]>0&&mat[j][where[lb(i)]])
            ans += f[i][j];
    ans -= m;
    assert(!(ans&1));
    cout << ans/2 << endl;
    return 0;
}