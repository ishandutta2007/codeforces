#include <bits/stdc++.h>
using namespace std;

const int maxn = 100100;
const int offset = (1<<18);
const int inf = 1e9 + 100;

int n, q;

int gcd (int ba, int bb)
{
    if (!bb) return ba;
    ba %= bb;
    return gcd(bb, ba);
}

struct tournament
{
    vector <int> najm [offset * 2];
    int nzd [offset * 2];
    int mini [offset * 2];
    void build()
    {
        for (int i = offset - 1; i > 0; i--)
        {
            nzd [i] = gcd(nzd [i * 2], nzd [i * 2 + 1]);
            mini [i] = min(mini [i * 2], mini [i * 2 + 1]);
            int lp = 0, dp = 0, vel1 = najm [i * 2].size(), vel2 = najm [i * 2 + 1].size();
            while (lp < vel1 || dp < vel2)
            {
                if (lp >= vel1)
                {
                    najm [i].push_back(najm [i * 2 + 1] [dp]);
                    dp++;
                }
                else if (dp >= vel2)
                {
                    najm [i].push_back(najm [i * 2] [lp]);
                    lp++;
                }
                else if (najm [i * 2] [lp] < najm [i * 2 + 1] [dp])
                {
                    najm [i].push_back(najm [i * 2] [lp]);
                    lp++;
                }
                else
                {
                    najm [i].push_back(najm [i * 2 + 1] [dp]);
                    dp++;
                }
            }
        }
        return;
    }
    int get (int cvor, int a, int b, int l, int r)
    {
        if (l >= a && r <= b) return nzd [cvor];
        if ((l + r) / 2 < a) return get(cvor * 2 + 1, a, b, (l + r) / 2 + 1, r);
        if ((l + r) / 2 + 1 > b) return get(cvor * 2, a, b, l, (l + r) / 2);
        return gcd(get(cvor * 2, a, b, l, (l + r) / 2), get(cvor * 2 + 1, a, b, (l + r) / 2 + 1, r));
    }
    int getmin (int cvor, int a, int b, int l, int r)
    {
        if (l >= a && r <= b) return mini [cvor];
        if (l > b || r < a) return inf;
        int mid = (l + r) / 2;
        return min(getmin(cvor * 2, a, b, l, mid), getmin(cvor * 2 + 1, a, b, mid + 1, r));
    }
    int getbrmin (int cvor, int a, int b, int l, int r, int najmanji)
    {
        if (l >= a && r <= b) return (upper_bound(najm [cvor].begin(), najm [cvor].end(), najmanji) - najm [cvor].begin());
        if (l > b || r < a) return 0;
        int mid = (l + r) / 2;
        return getbrmin(cvor * 2, a, b, l, mid, najmanji) + getbrmin(cvor * 2 + 1, a, b, mid + 1, r, najmanji);
    }
};

tournament T;

int main()
{
    for (int i = 0; i < offset; i++) T.nzd [offset + i] = 1;
    int x, qa, qb, trgcd, trmin, trspa;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        T.nzd [offset + i] = x;
        T.najm [offset + i].push_back(x);
        T.mini [offset + i] = x;
    }
    T.build();
    scanf("%d", &q);
    for (int qq = 0; qq < q; qq++)
    {
        scanf("%d%d", &qa, &qb);
        qa--; qb--;
        trgcd = T.get(1, qa, qb, 0, offset - 1);
        trmin = T.getmin(1, qa, qb, 0, offset - 1);
        trspa = T.getbrmin (1, qa, qb, 0, offset - 1, trmin);
        //cout << trgcd << " " << trmin << " " << trspa << endl;
        if (trgcd == trmin) printf("%d\n", qb - qa + 1 - trspa);
        else printf("%d\n", qb - qa + 1);
    }
    return 0;
}