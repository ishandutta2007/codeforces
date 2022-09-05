#include<bits/stdc++.h>

using namespace std;

int currM, Nmax, nr, M, Q, mod, p25[100009], p26[100009], inv26[100009], inv[100009], fac[100009], ans[100009], qr[100009];
char curr[100009];
pair < int, int > v[100009];

int pow (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = (1LL * p * a) % mod;
        a = (1LL * a * a) % mod;
    }
    return p;
}

int comb (int N, int K)
{
    if (N < 0 || K < 0 || K > N) return 0;
    int ans = (1LL * fac[N] * inv[K]) % mod;
    ans = (1LL * ans * inv[N - K]) % mod;
    return ans;
}

void Try (int st, int dr)
{
    int M = v[st].first, N = M - 1, val = 0;
    for (int i=st; i<=dr; i++)
    {
        while (N < qr[v[i].second])
        {
            N ++;
            int curr = (1LL * comb (N - 1, M - 1) * p25[N - M]) % mod;
            val = ((long long) val + 1LL * curr * inv26[N]) % mod;
        }
        ans[v[i].second] = (1LL * val * p26[N]) % mod;
    }
}

bool cmp (pair < int, int > a, pair < int, int > b)
{
    if (a.first == b.first) return qr[a.second] < qr[b.second];
    return a.first < b.first;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &Q), Nmax = 100002, mod = 1e9 + 7, fac[0] = 1;
for (int i=1; i<=Nmax; i++)
    fac[i] = (1LL * fac[i - 1] * i) % mod;
inv[Nmax] = pow (fac[Nmax], mod - 2);
for (int i=Nmax - 1; i>=0; i--)
    inv[i] = (1LL * inv[i + 1] * (i + 1)) % mod;
p25[0] = p26[0] = 1;
for (int i=1; i<=Nmax; i++)
    p25[i] = (1LL * p25[i - 1] * 25) % mod, p26[i] = (1LL * p26[i - 1] * 26) % mod;
inv26[0] = 1, inv26[1] = pow (26, mod - 2);
for (int i=2; i<=Nmax; i++)
    inv26[i] = (1LL * inv26[i - 1] * inv26[1]) % mod;
gets (curr + 1), currM = strlen (curr + 1);
while (Q --)
{
    int type;
    scanf ("%d ", &type);
    if (type == 1)
    {
        gets (curr + 1), currM = strlen (curr + 1);
        continue;
    }
    int currN;
    scanf ("%d", &currN), qr[++nr] = currN;
    v[nr] = make_pair (currM, nr);
}
sort (v + 1, v + nr + 1, cmp);
for (int i=1; i<=nr; i++)
{
    int j;
    for (j=i; j<=nr; j++)
        if (v[i].first != v[j].first) break;
    j --;
    Try (i, j);
    i = j;
}
for (int i=1; i<=nr; i++)
    printf ("%d\n", ans[i]);

return 0;
}