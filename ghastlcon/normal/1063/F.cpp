#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define N 1000020
#define M 20
#define S 26
using namespace std;

namespace SAM
{
    class Node
    {
    public:
        int s[S];
        int f;
        int l;

        Node(void) : f(-1), l(0)
        {
            memset(s, 0, sizeof(s));

            return;
        }
    };

    Node f[N];
    int c, d;
    vector<int> e[N];
    int l[N], r[N];
    int p[M][N];

    void InitSAM(void)
    {
        c = 1;

        return;
    }

    int InsertSAM(int k)
    {
        int p, b, q;

        p = d;
        f[d = c ++].l = f[p].l + 1;
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
                f[b].l = f[p].l + 1;
                f[q].f = f[d].f = b;

                for(; p != -1 && f[p].s[k] == q; p = f[p].f)
                    f[p].s[k] = b;
            }
        }

        return d;
    }

    void DFSSAM(int x)
    {
        static int k;
        int i;

        for(i = 1, p[0][x] = f[x].f; i < M; i ++)
        {
            p[i][x] = p[i - 1][x] == -1 ? -1 : p[i - 1][p[i - 1][x]];
            // printf("(%d,%d) : %d\n", i + 1, x + 1, p[i][x] + 1);
        }

        l[x] = k ++;
        for(i = 0; i < (signed)e[x].size(); i ++)
            DFSSAM(e[x][i]);
        r[x] = k - 1;

        return;
    }

    int MaxkSAM(int x, int k)
    {
        int i;

        for(i = M - 1; i > -1; i --)
            if(p[i][x] != -1 && f[p[i][x]].l >= k)
                x = p[i][x];

        return x;
    }
}

namespace Segwin
{
    int f[N << 1];

    void SetSegwin(int p, int v, int n)
    {
        for(f[p += n] = v; p >>= 1; )
            f[p] = max(f[p << 1], f[p << 1 | 1]);

        return;
    }

    int MaxSegwin(int l, int r, int n)
    {
        int o;

        for(l += n, r += n + 1, o = 0; l < r; l >>= 1, r >>= 1)
        {
            if(l & 1)
                o = max(o, f[l ++]);
            if(r & 1)
                o = max(o, f[-- r]);
        }

        return o;
    }
}

char a[N];
int d[N], f[N];

bool Check(int p)
{
    int x;

    x = SAM::MaxkSAM(d[p], f[p] - 1);
    // printf("%d(%d) : jump to %d\n", p, d[p] + 1, x + 1);
    if(Segwin::MaxSegwin(SAM::l[x], SAM::r[x], SAM::c) >= f[p] - 1)
        return true;

    x = SAM::MaxkSAM(d[p - 1], f[p] - 1);
    // printf("%d(%d) : jump2 to %d\n", p, d[p - 1] + 1, x + 1);

    return Segwin::MaxSegwin(SAM::l[x], SAM::r[x], SAM::c) >= f[p] - 1;
}

int main(void)
{
    int n;
    int i, j;

    scanf("%d %s", &n, a + 1);
    reverse(a + 1, a + n + 1);

    SAM::InitSAM();
    for(i = 1; i <= n; i ++)
        d[i] = SAM::InsertSAM(a[i] - 97);
    for(i = 1; i < SAM::c; i ++)
        SAM::e[SAM::f[i].f].push_back(i);
    SAM::DFSSAM(0);
    // for(i=0;i<SAM::c;i++)cout<<SAM::f[i].f+1<<" ";cout<<endl;

    // puts(a + 1);
    for(i = 1, j = 0; i <= n; i ++)
    {
        for(f[i] = f[i - 1] + 1; !Check(i); f[i] --)
        {
            j ++;
            // printf("at %d : insert %d(%d)\n", i, j, SAM::l[d[j]] + 1);
            Segwin::SetSegwin(SAM::l[d[j]], f[j], SAM::c);
        }
        // printf("%d : %d\n", i, f[i]);
    }
    printf("%d\n", *max_element(f, f + n + 1));

    return 0;
}