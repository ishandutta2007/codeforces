#include<bits/stdc++.h>

using namespace std;

int N, x11, cnt[5009], f[5009];
long long offset, ans, aib[5009];
vector < int > v[2];

void update (int pos, int val)
{
    /*if (val == +1) printf ("+%d\n", 5001 - pos);
    else printf ("-%d\n", 5001 - pos);*/
    f[pos] += val;
    long long curr = 1LL * val * (5001 - pos);
    while (pos <= 5000)
        cnt[pos] += val,
        aib[pos] += curr,
        pos += pos - (pos & (pos - 1));
}

long long query (int vals)
{
//    printf ("query %d\n", vals);
    int pos = 0;
    long long ans = 0;
    for (int i=12; i>=0; i--)
        if ((pos + (1 << i)) <= 5000 && cnt[pos + (1 << i)] < vals)
            pos += (1 << i), vals -= cnt[pos], ans += aib[pos];
    int extraF = min (vals, f[pos + 1]);
    return ans + 1LL * extraF * (5001 - (pos + 1));
}

int main ()
{
//freopen ("c.in", "r", stdin);
//freopen ("c.out", "w", stdout);

scanf ("%d\n", &N);
for (int i=1; i<=N; i++)
{
    char c1, c2;
    int x;
    scanf ("%c%c %d\n", &c1, &c2, &x), c1 -= '0', c2 -= '0';
    if (c1 + c2 == 0) update (5001 - x, +1);
    else
    if (c1 + c2 == 2) offset += x, x11 ++;
    else v[c1].push_back (x);
}
sort (v[0].begin (), v[0].end ());
sort (v[1].begin (), v[1].end ());
reverse (v[0].begin (), v[0].end ());
reverse (v[1].begin (), v[1].end ());
int pref0 = v[0].size () - 1, pref1 = v[1].size () - 1;
long long curr = offset;
for (auto it : v[0])
    curr += it;
for (auto it : v[1])
    curr += it;
for (int M = N; M >= x11; M --)
{
    while (pref0 >= 0 && 2 * (x11 + pref0) >= M)
        curr -= v[0][pref0], update (5001 - v[0][pref0], +1), pref0 --;
    while (pref1 >= 0 && 2 * (x11 + pref1) >= M)
        curr -= v[1][pref1], update (5001 - v[1][pref1], +1), pref1 --;
    if (2 + pref0 + pref1 + x11 > M || 2 * (1 + pref0 + x11) < M || 2 * (1 + pref1 + x11) < M) continue;
    long long maybe = curr + query (M - pref0 - pref1 - x11 - 2);
    //printf ("(%d %d %d) -> %lld = %lld + \n", M, pref0, pref1, maybe, curr);
    if (maybe > ans)
        ans = maybe;
}
printf ("%I64d\n", ans);
return 0;
}