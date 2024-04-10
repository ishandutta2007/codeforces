#include<bits/stdc++.h>

using namespace std;

int N, Q, st[200009], dr[200009], t[200009];
set < pair < int, int > > S;

int tata (int x)
{
    if (t[x] == x) return x;
    return t[x] = tata (t[x]);
}

void unite (int x, int y)
{
    x = tata (x);
    y = tata (y);
    if (x != y) t[x] = y;
}

int getV (int x)
{
    auto it = S.lower_bound (make_pair (x + 1, 0));
    it --;
    return it->first;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &Q);
for (int i=1; i<=N; i++)
    t[i] = i, S.insert (make_pair (i, i));
while (Q --)
{
    int x, y, type;
    scanf ("%d %d %d", &type, &x, &y);
    if (type <= 2)
    {
        if (type == 1) unite (x, y);
        else
        {
            auto it = S.lower_bound (make_pair (x + 1, 0));
            it --;
            int st = it->first;
            while (it->second < y)
            {
                unite (st, it->first);
                auto it2 = it;
                it ++, S.erase (it2);
            }
            int dr = it->second;
            unite (st, it->first), S.erase (it);
            S.insert (make_pair (st, dr));
        }
        continue;
    }
    if (tata (getV (x)) == tata (getV (y))) printf ("YES\n");
    else printf ("NO\n");
}
return 0;
}