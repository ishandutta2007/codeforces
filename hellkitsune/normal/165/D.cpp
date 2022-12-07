#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct edge
{
    int id, dest;
    struct edge *next;
} edge;

const int maxn = 100000;
int n, m, i, a, b, v, cur, prev, k, op, inda, indb;
edge *e[maxn + 1], *p, *pp;
int en[maxn], vn[maxn + 1], ind[maxn + 1], vi[maxn + 1], s[maxn + 1], fen[maxn + 1];

void fen_add(int n, int x)
{
    for (++n; n <= maxn; n += n & (-n))
        fen[n] += x;
}

int fen_sum(int l, int r)
{
    if (l > r)
        return 0;
    int res = 0;
    for (; l > 0; l -= l & (-l))
        res -= fen[l];
    for (++r; r > 0; r -= r & (-r))
        res += fen[r];
    return res;
}

int main(void)
{
    cin >> n;
    for (i = 1; i <= n; i++)
        e[i] = NULL;
    for (i = 1; i < n; i++)
    {
        cin >> a >> b;
        p = new edge;
        p->id = i;
        p->dest = a;
        p->next = e[b];
        e[b] = p;
        p = new edge;
        p->id = i;
        p->dest = b;
        p->next = e[a];
        e[a] = p;
    }
    v = 1;
    for (i = 1; i <= n; i++)
    {
        a = 0;
        p = e[i];
        while (p)
        {
            ++a;
            p = p->next;
        }
        if (a > 2)
        {
            v = i;
            break;
        }
    }
    s[v] = 0;
    vi[v] = 0;
    vn[v] = 0;
    a = 1;
    k = 0;
    for (p = e[v]; p; p = p->next)
    {
        cur = p->dest;
        ind[k] = a;
        en[p->id] = a;
        vn[cur] = a++;
        vi[cur] = k;
        s[cur] = 1;
        pp = e[cur];
        prev = v;
        while (pp)
        {
            if (pp->dest == prev)
                pp = pp->next;
            if (pp == NULL)
                break;
            else
            {
                prev = cur;
                cur = pp->dest;
                en[pp->id] = a;
                vn[cur] = a++;
                vi[cur] = k;
                s[cur] = s[prev] + 1;
                pp = e[cur];
            }
        }
        ++k;
    }
    ind[0] = 0;
    ind[k] = a;
    for (i = 0; i < a; i++)
        fen[i] = 0;
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> op;
        switch (op)
        {
            case 1:
                cin >> a;
                fen_add(en[a], -1);
                break;
            case 2:
                cin >> a;
                fen_add(en[a], 1);
                break;
            case 3:
                cin >> a >> b;
                if (vi[a] == vi[b])
                {
                    if (vn[a] > vn[b])
                    {
                        a ^= b;
                        b = a ^ b;
                        a ^= b;
                    }
                    if (fen_sum(vn[a] + 1, vn[b]))
                        cout << "-1\n";
                    else
                        cout << abs(s[a] - s[b]) << '\n';
                }
                else
                {
                    if (fen_sum(ind[vi[a]], vn[a]) + fen_sum(ind[vi[b]], vn[b]))
                        cout << "-1\n";
                    else
                        cout << s[a] + s[b] << '\n';
                }
                break;
            default:
                ;
        }
    }
    return 0;
}