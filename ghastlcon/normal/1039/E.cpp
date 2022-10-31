#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <vector>
#include <utility>
#define N 100020
#define M 17
using namespace std;

class Node
{
public:
    Node *s[2];
    Node *p;
    Node *q;
    int z;
    bool f;

    Node(void) : z(1), f(false)
    {
        s[0] = s[1] = p = q = NULL;

        return;
    }

    bool Relation(void)
    {
        return this == p -> s[1];
    }

    void Maintain(void)
    {
        z = 1;
        if(s[0])
        {
            z += s[0] -> z;
            s[0] -> f ^= f;
        }
        if(s[1])
        {
            z += s[1] -> z;
            s[1] -> f ^= f;
        }
        if(f)
        {
            f = false;
            swap(s[0], s[1]);
        }

        return;
    }

    void Pushdown(void)
    {
        if(p)
            p -> Pushdown();
        Maintain();

        return;
    }
};

int a[N];
pair<int, int> b[N];
Node f[N];
int p[N], q[2][M][N], o[N];
vector<int> s[N];

void RotateLCT(Node *x)
{
    Node *p;
    int k;

    p = x -> p;
    k = x -> Relation();

    x -> q = p -> q;
    p -> q = NULL;

    x -> p = p -> p;
    if(x -> p)
        x -> p -> s[p -> Relation()] = x;

    p -> s[k] = x -> s[!k];
    if(p -> s[k])
        p -> s[k] -> p = p;

    x -> s[!k] = p;
    p -> p = x;

    p -> Maintain();
    x -> Maintain();

    return;
}

void SplayLCT(Node *x)
{
    x -> Pushdown();
    while(x -> p)
        if(x -> p -> p)
        {
            if(x -> Relation() == x -> p -> Relation())
                RotateLCT(x -> p);
            else
                RotateLCT(x);
            RotateLCT(x);
        }
        else
            RotateLCT(x);

    return;
}

void ExposeLCT(Node *x)
{
    SplayLCT(x);
    if(x -> s[1])
    {
        x -> s[1] -> q = x;
        x -> s[1] -> p = NULL;
        x -> s[1] = NULL;
    }

    return;
}

bool SpliceLCT(Node *x)
{
    SplayLCT(x);
    if(!x -> q)
        return false;

    ExposeLCT(x -> q);
    x -> q -> s[1] = x;
    x -> p = x -> q;
    x -> q = NULL;

    return true;
}

void AccessLCT(Node *x)
{
    for(ExposeLCT(x); SpliceLCT(x); )
        ;

    return;
}

void EvertLCT(Node *x)
{
    AccessLCT(x);
    SplayLCT(x);
    x -> f ^= 1;

    return;
}

Node *FindLCT(Node *x)
{
    AccessLCT(x);
    SplayLCT(x);
    for(; x -> s[0]; x = x -> s[0])
        ;
    SplayLCT(x);

    return x;
}

void LinkLCT(Node *x, Node *y)
{
    EvertLCT(y);
    AccessLCT(x);
    SplayLCT(x);
    y -> q = x;

    return;
}

void CutLCT(Node *x, Node *y)
{
    // if(FindLCT(x) != FindLCT(y))
    //     puts("?");
    EvertLCT(x);
    AccessLCT(y);
    SplayLCT(x);
    x -> s[1] = y -> p = NULL;

    return;
}

int DistanceLCT(Node *x, Node *y)
{
    EvertLCT(x);
    AccessLCT(y);
    SplayLCT(x);

    return x -> z;
}

Node *Last2LCT(Node *x, Node *y)
{
    EvertLCT(x);
    AccessLCT(y);
    SplayLCT(x);
 
    for(x = x -> s[1]; x -> s[0]; x = x -> s[0])
        ;
    SplayLCT(x);
 
    return x;
}

int EvalRMQ(int l, int r)
{
    int t;

    t = 31 - __builtin_clz(r - l + 1);

    return max(q[1][t][l], q[1][t][r - (1 << t) + 1]) - min(q[0][t][l], q[0][t][r - (1 << t) + 1]);
}

int Nextpos(int n, int x, int k)
{
    int l, m, r;

    for(l = x, r = n; l + 1 < r; )
    {
        m = (l + r) >> 1;
        if(EvalRMQ(x, m) > k)
            r = m;
        else
            l = m;
    }

    return r;
}

int main(void)
{
    int n, w, m;
    int i, j, k;
    Node *t;

    scanf("%d %d %d", &n, &w, &m);
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
        q[0][0][i] = q[1][0][i] = a[i];
    }
    for(i = 0; i < m; i ++)
    {
        scanf("%d", &b[i].first);
        b[i].first = w - b[i].first;
        b[i].second = i;
    }

    sort(b, b + m);
    for(i = 1; i < M; i ++)
        for(j = 0; j + (1 << i) - 1 < n; j ++)
        {
            q[0][i][j] = min(q[0][i - 1][j], q[0][i - 1][j + (1 << (i - 1))]);
            q[1][i][j] = max(q[1][i - 1][j], q[1][i - 1][j + (1 << (i - 1))]);
        }

    // for(i = 0; i < m; i ++)
    //     for(j = 0; j < n; j = Nextpos(n, j, b[i].first))
    //         o[b[i].second] ++;

    w = 200;
    for(i = 0; i < n; i ++)
    {
        p[i] = i;
        s[0].push_back(i);
    }
    for(i = 0; i < m; i ++)
    {
        for(j = 0; j < (signed)s[i].size(); j ++)
        {
            k = s[i][j];
            if(p[k] != k)
                CutLCT(&f[k], &f[p[k]]);

            p[k] = Nextpos(n, k, b[i].first);
            if(p[k] - k <= w)
            {
                LinkLCT(&f[k], &f[p[k]]);
                if(p[k] != n)
                    s[lower_bound(b, b + m, make_pair(EvalRMQ(k, p[k]), 0)) - b].push_back(k);
            }
            else
                LinkLCT(&f[k], &f[n + 1]);
        }

        for(j = 0; FindLCT(&f[j]) != FindLCT(&f[n]); )
        {
            t = Last2LCT(&f[n + 1], &f[j]);
            o[b[i].second] += DistanceLCT(&f[j], t);
            j = Nextpos(n, (int)(t - f), b[i].first);
        }
        o[b[i].second] += DistanceLCT(&f[j], &f[n]) - 1;
    }

    for(i = 0; i < m; i ++)
        printf("%d\n", o[i] - 1);

    return 0;
}