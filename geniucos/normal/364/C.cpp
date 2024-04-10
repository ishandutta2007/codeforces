#include<bits/stdc++.h>

using namespace std;

int lim, nr, N, R[5009], ans[5009], a[5009], pr[5009], C[5009], Lft[30009], rap[30009];
bool cr[5009];
vector < int > v[5009];
bitset < 50000002 > ap;

bool pair_up (int nod)
{
    if (C[nod]) return 0;
    C[nod] = 1;
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (Lft[*it] == 0)
        {
            Lft[*it] = nod;
            R[nod] = *it;
            return 1;
        }
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (pair_up (Lft[*it]))
        {
            Lft[*it] = nod;
            R[nod] = *it;
            return 1;
        }
    return 0;
}

int Match ()
{
    bool ok = 1;
    while (ok)
    {
        for (int i=1; i<=N; i++)
            C[i] = 0;
        ok = 0;
        for (int i=1; i<=N; i++)
            if (R[i] == 0) ok |= pair_up (i);
    }
    int cnt = 0;
    for (int i=1; i<=N; i++)
        if (R[i]) cnt ++;
    return cnt;
}

int get_id (int val)
{
    int p = 1, u = nr;
    while (p <= u)
    {
        int mij = (p + u) >> 1;
        if (rap[mij] == val) return mij;
        if (rap[mij] < val) p = mij + 1;
        else u = mij - 1;
    }
}

void add_prim (int L)
{
    for (int i=nr; i>=1; i--)
    {
        int aux = rap[i];
        while (aux * pr[L] <= lim)
        {
            aux *= pr[L];
            rap[++nr] = aux;
        }
    }
    sort (rap + 1, rap + nr + 1);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=2; i * i <= N; i++)
    if (cr[i] == 0)
        for (int j=i * i ;j<=N; j+=i)
            cr[j] = 1;
for (int i=2; i<=N; i++)
    if (cr[i] == 0) pr[++nr] = i;
for (int i=1; i<=N; i++)
    a[i] = 1;
lim = 2 * N * N;
/*int cnt = 0;
for (int i=1; i<=lim; i++)
{
    int aux = i;
    for (int j=1; j<=5; j++)
        while (aux % pr[j] == 0) aux /= pr[j];
    cnt += (aux == 1);
}
printf ("%d\n", cnt);
return 0;*/
rap[1] = nr = 1;
int st = 1, dr = 6;
if (N >= 1500) st = 5;
for (int i=1; i<st; i++)
    add_prim (i);
for (int L = st; L <= dr; L ++)
{
    add_prim (L);
    for (int i=1; i<=N; i++)
        a[i] = 1;
    for (int j=L; j>=1; j--)
    {
        sort (a + 1, a + N + 1);
        for (int i=1; i<=N / 2; i++)
        {
            a[i] *= pr[j];
            if (a[i] > lim)
            {
                printf ("QQ\n");
                return 0;
            }
        }
    }
    ap.reset ();
    bool ok = 1;
    for (int i=N; i>=1; i--)
    {
        ans[i] = a[i];
        int j = 1;
        while (j <= nr && a[i] * rap[j] <= lim && ap[a[i] * rap[j]] == 1) j ++;
        if (j > nr || a[i] * rap[j] > lim)
        {
            ok = 0;
            break;
        }
        else ans[i] = a[i] * rap[j];
        ap[ans[i]] = 1;
    }
/*    for (int i=1; i<=N; i++)
        for (int j=1; j <= nr && rap[j] * a[i] <= lim; j++)
            v[i].push_back (get_id (rap[j] * a[i]));*/
    if (ok)
    {
//        printf ("Right Side: %d\n", nr);
//        for (int i=1; i<=N; i++)
  //          R[i] = rap[R[i]];
  /*      for (int i=1; i<=L; i++)
            printf ("%d ", pr[i]);
        printf ("\n");*/
      //  int max_used = 0;
        for (int i=1; i<=N; i++)
    //    {
            printf ("%d ", ans[i]);
//            if (R[i] > max_used) max_used = R[i];
  //      }
        printf ("\n");
        /*printf ("%d out of %d\n", max_used, lim);
        for (int i=1; i<=L; i++)
        {
            int curr = 0;
            for (int j=1; j<=N; j++)
            {
                curr += (R[j] % pr[i] == 0);
                while (R[j] % pr[i] == 0) R[j] /= pr[i];
            }
            if (curr < N / 2)
            {
                printf ("WA\n");
                return 0;
            }
        }
        for (int i=1; i<=N; i++)
            if (R[i] != 1)
            {
                printf ("WA\n");
                return 0;
            }*/
        return 0;
    }
    for (int i=1; i<=N; i++)
        v[i].clear (), Lft[R[i]] = 0, R[i] = 0;
}
return 0;
}