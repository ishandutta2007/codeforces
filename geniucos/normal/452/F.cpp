#include<bits/stdc++.h>

using namespace std;

int N, p[300009];
int baza1 = 3, baza2 = 5, mod1 = 1e9 + 7, mod2 = 1e9 + 9, put1[300009], put2[300009];

void init ()
{
    put1[0] = put2[0] = 1;
    for (int i=1; i<=N; i++)
        put1[i] = (1LL * put1[i - 1] * baza1) % mod1,
        put2[i] = (1LL * put2[i - 1] * baza2) % mod2;
}

pair < int, int > mrg (pair < int, int > a, pair < int, int > b, int la, int lb)
{
    pair < int, int > ans;
    ans.first = (1LL * a.first * put1[lb] + b.first) % mod1;
    ans.second = (1LL * a.second * put2[lb] + b.second) % mod2;
    return ans;
}

class hashString
{
public:
    pair < int, int > aint[1200009], ansQ;
    /*void build (int nod, int st, int dr)
    {
        if (st == dr) return ;
        int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
        build (f1, st, mij);
        build (f2, mij + 1, dr);
    }*/
    void update (int nod, int st, int dr, int pos)
    {
        if (st == dr)
        {
            aint[nod] = {1, 1};
            return ;
        }
        int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
        if (pos <= mij) update (f1, st, mij, pos);
        else update (f2, mij + 1, dr, pos);
        aint[nod] = mrg (aint[f1], aint[f2], mij - st + 1, dr - mij);
    }

    void query (int nod, int st, int dr, int x, int y)
    {
        if (x <= st && dr <= y)
        {
            if (x == st) ansQ = aint[nod];
            else ansQ = mrg (ansQ, aint[nod], st - x, dr - st + 1);
            return ;
        }
        int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
        if (x <= mij) query (f1, st, mij, x, y);
        if (mij < y) query (f2, mij + 1, dr, x, y);
    }

    pair < int, int > get_hash (int st, int dr)
    {
        query (1, 1, N, st, dr);
        return ansQ;
    }

    void fix_value (int pos) {update (1, 1, N, pos);}
}nrm, rev;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), init ();
for (int i=1; i<=N; i++)
    scanf ("%d", &p[i]);
for (int i=1; i<=N; i++)
{
    int l = min (p[i] - 1, N - p[i]), st = p[i] - l, dr = p[i] + l;
    pair < int, int > nrmHsh = nrm.get_hash (st, dr), revHsh = rev.get_hash (N - dr + 1, N - st + 1);
    if (nrmHsh != revHsh)
    {
        //printf ("%d at center\n", i);
        printf ("YES\n");
        return 0;
    }
    nrm.fix_value (p[i]), rev.fix_value (N - p[i] + 1);
}
printf ("NO\n");
return 0;
}