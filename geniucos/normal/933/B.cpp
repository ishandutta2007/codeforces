#include<bits/stdc++.h>

using namespace std;

int K;
long long P;
const long long INF = 1e18 + 2;
vector < int > ans;

void solve (long long val)
{
    if (0 <= val && val < K)
    {
        ans.push_back (val);
        return ;
    }
    int r = val % K;
    if (r < 0) r += K;
    ans.push_back (r);
    val -= r;
    solve (-val / K);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d %d", &P, &K);
solve (P);
printf ("%d\n", ans.size ());
for (auto it : ans)
    printf ("%d ", it);
printf ("\n");
//printf ("%I64d\n", INF);
/*lft[0] = 0, rgt[0] = K - 1;
if (0 <= P && P < K)
{
    printf ("1\n%I64d\n", P);
    return 0;
}
for (int i=1;; i++)
{
    long long l, r;
    if (rgt[i - 1] <= INF / K) l = -1LL * rgt[i - 1] * K;
    else l = -INF;
    if (lft[i - 1] <= INF / K) r = -1LL * lft[i - 1] * K;
    else r = INF;
    r += K - 1;
    if (l <= P && P <= r)
    {
        solve (i, P);

        return 0;
    }
}
assert (0);*/
return 0;
}