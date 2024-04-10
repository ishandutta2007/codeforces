#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#define N 100020
#define S 26
using namespace std;

namespace Segment
{
    class Node
    {
    public:
        Node *s[2];
        int v;

        Node(void) : v(0)
        {
            s[0] = s[1] = NULL;

            return;
        }
    };

    void SetSegment(Node *&x, int l, int r, int p)
    {
        int m;

        if(!x)
            x = new Node();
        if(l == r)
        {
            x -> v = 1;

            return;
        }

        m = (l + r) >> 1;
        if(p <= m)
            SetSegment(x -> s[0], l    , m, p);
        else
            SetSegment(x -> s[1], m + 1, r, p);
        x -> v = (x -> s[0] ? x -> s[0] -> v : 0) + (x -> s[1] ? x -> s[1] -> v : 0);

        return;
    }

    Node *MergeSegment(Node *x, Node *y)
    {
        Node *t;

        if(!x)
            return y;
        if(!y)
            return x;

        t = new Node();
        if(!x -> s[0] && !x -> s[1])
            t -> v = 1;
        else
        {
            t -> s[0] = MergeSegment(x -> s[0], y -> s[0]);
            t -> s[1] = MergeSegment(x -> s[1], y -> s[1]);
            t -> v = (t -> s[0] ? t -> s[0] -> v : 0) + (t -> s[1] ? t -> s[1] -> v : 0);
        }

        return t;
    }
}

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
            return;
        }
    };

    Node f[N << 1];
    int c, d;
    Segment::Node *s[N << 1];
    int v[N], h[N << 1];

    void InitSAM(void)
    {
        c = 1;
        d = 0;

        return;
    }

    void InsertSAM(int n, int k, int i)
    {
        int p, q, b;

        if(f[d].s[k])
        {
            q = f[d].s[k];
            if(f[q].l == f[d].l + 1)
            {
                // printf("k = %d, d")
                Segment::SetSegment(s[q], 0, n - 1, i);
            }
            else
            {
                f[b = c ++] = f[q];
                f[b].l = f[d].l + 1;
                f[q].f = b;
                Segment::SetSegment(s[b], 0, n - 1, i);

                for(p = d; p != -1 && f[p].s[k] == q; p = f[p].f)
                    f[p].s[k] = b;
            }
            d = f[d].s[k];

            return;
        }

        p = d;
        f[d = c ++].l = f[p].l + 1;
        Segment::SetSegment(s[d], 0, n - 1, i);
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

        return;
    }

    void MergeSAM(void)
    {
        int i;

        for(i = 0; i < c; i ++)
            v[f[i].l] ++;
        for(i = 1; i < N; i ++)
            v[i] += v[i - 1];
        for(i = c - 1; i > -1; i --)
            h[-- v[f[i].l]] = i;

        for(i = c - 1; i > 0; i --)
            s[f[h[i]].f] = MergeSegment(s[f[h[i]].f], s[h[i]]);
        for(i = 0; i < c; i ++)
            if(!s[i])
                s[i] = new Segment::Node();

        // for(i=0;i<c;i++)cout<<f[i].l<<' ';cout<<endl;
        // for(i=0;i<c;i++)cout<<(s[i]?s[i]->v:0)<<' ';cout<<endl;

        return;
    }
}

string a[N];

int main(void)
{
    int n, k;
    int i, j, t, p, l;
    long long o;

    ios::sync_with_stdio(false);
    cin >> n >> k;
    SAM::InitSAM();
    for(i = 0; i < n; i ++)
    {
        cin >> a[i];
        for(j = SAM::d = 0; j < (signed)a[i].size(); j ++)
            SAM::InsertSAM(n, a[i][j] - 97, i);
        // cout<<SAM::c<<endl;
    }
    SAM::MergeSAM();

    for(i = 0; i < n; i ++)
    {
        for(j = p = l = o = 0; j < (signed)a[i].size(); j ++)
        {
            t = a[i][j] - 97;
            while(!SAM::f[p].s[t] || SAM::s[SAM::f[p].s[t]] -> v < k)
            {
                l --;
                if(l == -1)
                    break;
                if(l == SAM::f[SAM::f[p].f].l)
                    p = SAM::f[p].f;
            }

            // printf("string %d, char %d, at %d, len %d\n", i, j, p, l);

            if(l == -1)
                l = p = 0;
            else
            {
                l ++;
                p = SAM::f[p].s[t];
            }
            o += l;
        }
        cout << o << ' ';
    }
    cout << endl;

    return 0;
}