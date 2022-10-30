#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <bitset>
#define N 2020
using namespace std;

const bool d[3][2][2] = 
{
    {
        {false, true},
        {true, false},
    },
    {
        {true, false},
        {true, true},
    },
    {
        {true, true},
        {false, true},
    },
};

bitset<N> f[N];
bool c[N][2][2], o[N], z[N];

void Multiply(const bool a[2][2], bool b[2][2])
{
    bool c[2][2];

    c[0][0] = (a[0][0] & b[0][0]) ^ (a[0][1] & b[1][0]);
    c[0][1] = (a[0][0] & b[0][1]) ^ (a[0][1] & b[1][1]);
    c[1][0] = (a[1][0] & b[0][0]) ^ (a[1][1] & b[1][0]);
    c[1][1] = (a[1][0] & b[0][1]) ^ (a[1][1] & b[1][1]);
    memcpy(b, c, sizeof(bool) * 4);

    return;
}

int main(void)
{
    int n, m, k, x;
    char s[4];
    int i, j, l;

    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i ++)
        c[i][0][0] = c[i][1][1] = true;

    for(i = l = 0; i < m; i ++)
    {
        scanf("%s %d", s, &k);
        while(k --)
        {
            scanf("%d", &x);
            x --;
            if(s[0] == 'm')
            {
                f[l    ][x << 1    ] = c[x][0][0];
                f[l    ][x << 1 | 1] = c[x][0][1];
                f[l + 1][x << 1    ] = c[x][1][0];
                f[l + 1][x << 1 | 1] = c[x][1][1];
            }
            else if(s[0] == 'R' && s[1] == 'Y')
                Multiply(d[0], c[x]);
            else if(s[0] == 'R' && s[1] == 'B')
                Multiply(d[1], c[x]);
            else
                Multiply(d[2], c[x]);
        }

        if(s[0] == 'm')
        {
            scanf("%s", s);
            f[l    ][n << 1] = s[0] == 'R' || s[0] == 'B';
            f[l + 1][n << 1] = s[0] == 'Y' || s[0] == 'B';
            l += 2;
        }
    }

    // printf("before\n");
    // for(i = 0; i < l; i ++)
    // {
    //     for(j = 0; j < n * 2; j ++)
    //         printf("%d ", (int)f[i][j]);
    //     printf("= %d\n", (int)f[i][n * 2]);
    // }

    for(i = k = 0; i < l && k < (n << 1); i ++, k ++)
    {
        for(j = i; j < l && !f[j][k]; j ++)
            ;
        if(j == l)
        {
            z[k] = true;
            i --;
            continue;
        }

        swap(f[i], f[j]);
        for(j = i + 1; j < l; j ++)
            if(f[j][k])
                f[j] ^= f[i];
    }

    // printf("after\n");
    // for(i = 0; i < l; i ++)
    // {
    //     for(j = 0; j < n * 2; j ++)
    //         printf("%d ", (int)f[i][j]);
    //     printf("= %d\n", (int)f[i][n * 2]);
    // }

    for(i = 0; i < l; i ++)
    {
        f[i].flip(n << 1);
        if(f[i].none())
        {
            printf("NO\n");

            return 0;
        }
        f[i].flip(n << 1);
    }

    for(i = 0; i < l; i ++)
        for(j = k; j < (n << 1); j ++)
            f[i][j] = false;
    for(i = l - 1, j = k - 1; i > -1 && j > -1; i --)
    {
        if(z[j])
        {
            j --;i++;
            continue;
        }
        if(f[i][j])
        {
            o[j] = f[i][n << 1];
            for(k = i - 1; k > -1; k --)
                if(f[k][j])
                    f[k] ^= f[i];
            j --;
        }
    }

    // for(i = 0; i < n * 2; i ++)
    //     cout << o[i] << ' ';
    // cout << endl;

    printf("YES\n");
    for(i = 0; i < n; i ++)
    {
        k = o[i << 1 | 1] << 1 | o[i << 1];
        printf("%c", !k ? '.' : k == 1 ? 'R' : k == 2 ? 'Y' : 'B');
    }
    printf("\n");

    return 0;
}