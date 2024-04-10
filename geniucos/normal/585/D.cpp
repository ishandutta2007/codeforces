#include<cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int N, a[30], b[30], c[30], X[30], ans[30], aux[30];
long long P[30], maxi;
bool ok;

map < pair < long long , long long > , pair < long long , long long > > hw;

void back (int pos, long long msk)
{
    if (pos == N / 2 + 1)
    {
        long long x = 0, y = 0, z = 0;
        for (int i=1; i<pos; i++)
        {
            x += a[i], y += b[i], z += c[i];
            if (X[i] == 0) x -= a[i];
            else
            if (X[i] == 1) y -= b[i];
            else z -= c[i];
        }
        if (hw.count (make_pair (x - y, x - z))) hw[make_pair (x - y, x - z)] = max (hw[make_pair (x - y, x - z)], make_pair (x, msk));
        else hw[make_pair (x - y, x - z)] = make_pair (x, msk);
        return ;
    }
    for (int i=0; i<3; i++)
        X[pos] = i, back (pos + 1, msk + 1LL * P[pos-1] * i);
}

void Print ()
{
    for (int i=1; i<=N; i++)
    {
        if (aux[i] == 0) printf ("MW\n");
        else
        if (aux[i] == 1) printf ("LW\n");
        else printf ("LM\n");
    }
}

void back2 (int pos)
{
    if (pos == N + 1)
    {
        long long x = 0, y = 0, z = 0;
        for (int i=N / 2 + 1; i<pos; i++)
        {
            x += a[i], y += b[i], z += c[i];
            if (ans[i] == 0) x -= a[i];
            else
            if (ans[i] == 1) y -= b[i];
            else z -= c[i];
        }
        pair < long long , long long > wanted = make_pair (y - x, z - x);
        if (hw.count (wanted))
        {
            long long msk = hw[wanted].second;
            long long wn = hw[wanted].first + x;
            if (ok == 0 || wn > maxi)
            {
                maxi = wn, ok = 1;
                for (int i=1; i<=N / 2; i++)
                    aux[i] = msk % 3, msk /= 3;
                for (int i=N / 2 + 1; i<=N; i++)
                    aux[i] = ans[i];
            }
        }
        return ;
    }
    for (int i=0; i<3; i++)
        ans[pos] = i, back2 (pos + 1);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d %d %d", &a[i], &b[i], &c[i]);
P[0] = 1;
for (int i=1; i<=N; i++)
    P[i] = 1LL * P[i-1] * 3;
back (1, 0);
ok = 0;
back2 (N / 2 + 1);
if (!ok) printf ("Impossible\n");
else Print ();
return 0;
}