#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 600020
#define K 3
#define S 26
#define MOD 1000000007
using namespace std;

class Node
{
public:
    int f;
    int l;
    int s[S];

    Node(void) : f(-1), l(0)
    {
        return;
    }
};

int n[K];
char a[K][N];
Node f[N];
int c, d;
int g[K][N], t[N], v[N];
int o[N];

inline int ID(char c)
{
    return c - 97;
}

void InitSAM(void)
{
    c = 1;
    d = 0;

    return;
}

void InsertSAM(int v, int k)
{
    int b, p, q;

    p = d;
    if(f[p].s[k])
    {
        q = f[p].s[k];
        if(f[q].l == f[p].l + 1)
            g[v][d = q] = 1;
        else
        {
            f[d = c ++] = f[q];
            g[v][d] = 1;
            f[q].f = d;
            f[d].l = f[p].l + 1;
        
            for(; p != -1 && f[p].s[k] == q; p = f[p].f)
                f[p].s[k] = d;
        }

        return;
    }
    f[d = c ++].l = f[p].l + 1;
    g[v][d] = 1;

    for(; p != -1 && !f[p].s[k]; p = f[p].f)
        f[p].s[k] = d;

    if(p == -1)
        f[d].f = 0;
    else
    {
        q = f[p].s[k];
        if(f[q].l == f[p].l + 1)
            f[d].f = q;
        else
        {
            f[b = c ++] = f[q];
            f[q].f = f[d].f = b;
            f[b].l = f[p].l + 1;

            for(; p != -1 && f[p].s[k] == q; p = f[p].f)
                f[p].s[k] = b;
        }
    }

    return;
}

int main(void)
{
    int i, j, t;

    InitSAM();
    for(i = 0; i < K; i ++)
    {
        scanf("%s", a[i]);
        n[i] = strlen(a[i]);
        for(j = d = 0; j < n[i]; j ++)
            InsertSAM(i, ID(a[i][j]));
    }

    for(i = 0; i < c; i ++)
        ::t[f[i].l] ++;
    for(i = 1; i < N; i ++)
        ::t[i] += ::t[i - 1];
    for(i = c - 1; i > -1; i --)
        v[-- ::t[f[i].l]] = i;
    for(i = c - 1; i > 0; i --)
        for(j = 0; j < K; j ++)
            g[j][f[v[i]].f] += g[j][v[i]];
    // for(i=0;i<c;i++)cout<<v[i]<<' ';
    // cout<<endl;
    // for(i=0;i<c;i++){for(j=0;j<K;j++)cout<<g[j][i]<<' ';cout<<endl;}

    for(i = 1; i < c; i ++)
    {
        for(j = 0, t = 1; j < K; j ++)
            t = (long long)t * g[j][i] % MOD;
        // printf("%d : %d\n", i, t);
        (o[f[f[i].f].l + 1] += t) %= MOD;
        (o[f[i].l + 1] -= t) %= MOD;
    }

    for(i = 1; i <= min(n[0], min(n[1], n[2])); i ++)
        printf("%d ", o[i] = ((o[i] + o[i - 1]) % MOD + MOD) % MOD);
    printf("\n");


    return 0;
}