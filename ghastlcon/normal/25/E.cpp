#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 100020
#define M 3
using namespace std;

const int d[6][M] = 
{
    {0, 1, 2},
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 0, 1},
    {2, 1, 0},
};

char a[M][N];
int f[M][N], l[M];
bool k[M][M];

void InitKMP(char *s, int n, int *f)
{
    int i, j;

    f[0] = f[1] = 0;
    for(i = 1, j = 0; i < n; i ++)
    {
        while(j && s[j] != s[i])
            j = f[j];
        j = s[j] == s[i] ? j + 1 : 0;
        f[i + 1] = j;
    }

    // puts(s);
    // for(i = 0;i<=n;i++)cout<<f[i]<<' ';cout<<endl;

    return;
}

bool MatchKMP(char *a, int *f, int m, int n, char *s)
{
    int i, j;

    // printf("TRY %s %s\n", a, s);

    if(m > n)
        return false;
    for(i = j = 0; i < n; i ++)
    {
        while(j && a[j] != s[i])
            j = f[j];
        j = a[j] == s[i] ? j + 1 : 0;
        // cout<<a<<' '<<s<<' '<<i<<' '<<j<<endl;
        if(j == m)
            return true;
    }

    return false;
}

int Solve(int x, int y)
{
    int i, j;

    for(i = j = 0; i < l[x]; i ++)
    {
        while(j && a[y][j] != a[x][i])
            j = f[y][j];
        j = a[y][j] == a[x][i] ? j + 1 : 0;
    }

    return l[x] + l[y] - j;
}

int main(void)
{
    int i, j, o;

    for(i = 0; i < M; i ++)
    {
        scanf("%s", a[i]);
        InitKMP(a[i], l[i] = strlen(a[i]), f[i]);
    }

    for(i = 0; i < M; i ++)
        for(j = 0; j < M; j ++)
            if(i != j)
            {
                // printf("%d : %s\n", i, a[i]);
                k[i][j] = MatchKMP(a[i], f[i], l[i], l[j], a[j]);
            }
    // for(i=0;i<M;i++){for(j=0;j<M;j++)cout<<k[i][j]<<' ';cout<<endl;}

    if(k[1][0] && k[2][0])
    {
        printf("%d\n", l[0]);
        
        return 0;
    }
    else if(k[0][1] && k[2][1])
    {
        printf("%d\n", l[1]);
        
        return 0;
    }
    else if(k[0][2] && k[1][2])
    {
        printf("%d\n", l[2]);
        
        return 0;
    }

    // while(1){int a,b;cin>>a>>b;cout<<Solve(a-1,b-1)<<endl;}

    for(i = 0, o = N * 3; i < 6; i ++)
    {
        if(k[d[i][0]][d[i][1]])
            o = min(o, Solve(d[i][1], d[i][2]));
        if(k[d[i][2]][d[i][1]])
            o = min(o, Solve(d[i][0], d[i][1]));
        if(k[d[i][1]][d[i][0]] || k[d[i][1]][d[i][2]])
            o = min(o, Solve(d[i][0], d[i][2]));
        o = min(o, Solve(d[i][0], d[i][1]) + Solve(d[i][1], d[i][2]) - l[d[i][1]]);
    }
    printf("%d\n", o);

    return 0;
}