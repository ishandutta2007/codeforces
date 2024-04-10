#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 1000020
#define S 2
using namespace std;

namespace SAM
{
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

    Node f[N];
    int c, d;
    int g[N], t[N], v[N];

    inline int ID(char c)
    {
        return c == ')';
    }

    void InitSAM(void)
    {
        c = 1;
        d = 0;

        return;
    }

    void InsertSAM(int k, int i)
    {
        int b, p, q;

        p = d;
        f[d = c ++].l = f[p].l + 1;
        g[d] = i;

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

    void RightSAM(int n)
    {
        int i;

        for(i = 0; i < c; i ++)
            t[f[i].l] ++;
        for(i = 1; i <= n; i ++)
            t[i] += t[i - 1];
        for(i = c - 1; i > -1; i --)
            v[-- t[f[i].l]] = i;
        for(i = c - 1; i > 0; i --)
            g[f[v[i]].f] = g[v[i]];
        // for(i=0;i<c;i++)printf("vertex %d, father %d, length %d, pos %d\n",i,f[i].f,f[i].l,g[i]);

        return;
    }
}

namespace Chairman
{
    class Node
    {
    public:
        Node *s[2];
        int v;

        Node(int _v = 0) : v(_v)
        {
            s[0] = s[1] = NULL;

            return;
        }
    };

    Node *r[N];
    int f[N];

    void InsertChairman(Node *&x, Node *k, int l, int r, int p, int v)
    {
        int m;

        if(l == r)
        {
            x = new Node(k -> v + v);

            return;
        }

        m = (l + r) >> 1;
        x = new Node();
        if(p <= m)
        {
            InsertChairman(x -> s[0], k -> s[0], l    , m, p, v);
            x -> s[1] = k -> s[1];
        }
        else
        {
            InsertChairman(x -> s[1], k -> s[1], m + 1, r, p, v);
            x -> s[0] = k -> s[0];
        }
        x -> v = x -> s[0] -> v + x -> s[1] -> v;

        return;
    }

    int SumChairman(Node *x, int l, int r, int s, int t)
    {
        int m;

        if(l > t || r < s)
            return 0;
        if(l >= s && r <= t)
            return x -> v;

        m = (l + r) >> 1;

        return SumChairman(x -> s[0], l, m, s, t) + SumChairman(x -> s[1], m + 1, r, s, t);
    }
}

int n;
char a[N];
int f[N];

int BSFind(int p)
{
    int l, m, r;

    if(!(Chairman::f[p] + n))
        return 1;

    for(l = 0, r = p; l + 1 < r; )
    {
        m = (l + r) >> 1;
        if(Chairman::SumChairman(Chairman::r[p], 0, n * 2, 0, Chairman::f[p] + n - 1) - Chairman::SumChairman(Chairman::r[m - 1], 0, n * 2, 0, Chairman::f[p] + n - 1))
            l = m;
        else
            r = m;
    }

    return r;
}

int main(void)
{
    int i, l, r;
    long long o;

    scanf("%d %s", &n, a + 1);

    SAM::InitSAM();
    Chairman::r[0] = new Chairman::Node();
    Chairman::r[0] -> s[0] = Chairman::r[0] -> s[1] = Chairman::r[0];
    for(i = 1; i <= n; i ++)
    {
        SAM::InsertSAM(SAM::ID(a[i]), i);
        Chairman::f[i] = Chairman::f[i - 1] + (a[i] == '(' ? 1 : -1);
        Chairman::InsertChairman(Chairman::r[i], Chairman::r[i - 1], 0, n * 2, Chairman::f[i] + n, 1);
    }
    SAM::RightSAM(n);

    // for(i=1;i<=n;i++)cout<<Chairman::f[i]<<' ';cout<<endl;
    // while(1){int a,b,c,d;cin>>a>>b>>c>>d;cout<<Chairman::SumChairman(Chairman::r[b],0,n*2,c+n,d+n)-Chairman::SumChairman(Chairman::r[a-1],0,n*2,c+n,d+n)<<endl;}

    for(i = 1; i <= n; i ++)
        f[i] = i - BSFind(i) + 1;
    // for(i=1;i<=n;i++)cout<<f[i]<<' ';cout<<endl;return 0;

    for(i = 1, o = 0; i < SAM::c; i ++)
        if(a[SAM::g[i]] == ')')
        {
            l = SAM::f[SAM::f[i].f].l + 1;
            r = SAM::f[i].l;
            r = min(r, f[SAM::g[i]]);

            // printf("vertex %d at %d [%d, %d]\n",i,SAM::g[i],l,r);
            // cout<<o<<endl;
            if(l <= r)
                o += Chairman::SumChairman(Chairman::r[SAM::g[i] - l], 0, n * 2, Chairman::f[SAM::g[i]] + n, Chairman::f[SAM::g[i]] + n) - (SAM::g[i] - r - 1 > -1 ? Chairman::SumChairman(Chairman::r[SAM::g[i] - r - 1], 0, n * 2, Chairman::f[SAM::g[i]] + n, Chairman::f[SAM::g[i]] + n) : (!Chairman::f[SAM::g[i]] ? -1 : 0));
            // cout<<o<<endl;
        }
    printf("%lld\n", o);

    return 0;
}