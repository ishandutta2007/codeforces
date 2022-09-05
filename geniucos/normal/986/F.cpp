#include<bits/stdc++.h>

using namespace std;

int N, nr, pr[2000009], ans[10009];
const int maxM = 31622800;
unsigned char isComposite[maxM >> 3];
pair < pair < long long, long long >, int > qr[10009];

long long mul (long long a, long long b, long long mod)
{
    long long ans = 0;
    while (b > 0)
    {
        if (b & 1LL)
        {
            ans += a;
            if (ans >= mod)
                ans -= mod;
        }
        a += a, b >>= 1LL;
        if (a >= mod)
            a -= mod;
    }
    return ans;
}

long long power (long long a, long long b, long long mod)
{
    long long ans = 1;
    while (b > 0)
    {
        if (b & 1LL)
            ans = mul (ans, a, mod);
        a = mul (a, a, mod), b >>= 1LL;
    }
    return ans;
}

vector < long long > primes;
const long long INF = 1LL << 60;
priority_queue < pair < long long, int > > PQ;
int smallP;
long long d[100009];
void init (long long K)
{
    primes.clear ();
    for (int i=1; i<=nr && 1LL * pr[i] * pr[i] <= K; i++)
        if (K % pr[i] == 0)
        {
            primes.push_back (pr[i]);
            while (K % pr[i] == 0)
                K /= pr[i];
        }
    if (K > 1)
        primes.push_back (K);
    if (primes.size () > 2)
    {
        smallP = primes[0];
        for (int i=0; i<smallP; i++)
            d[i] = INF;
        d[0] = 0, PQ.push ({0, 0});
        while (!PQ.empty ())
        {
            auto curr = PQ.top ();
            PQ.pop ();
            int nod = curr.second;
            if (curr.first != -d[nod]) continue;
            for (int i=1; i<primes.size (); i++)
                if (d[nod] + primes[i] < d[(nod + primes[i]) % smallP])
                    d[(nod + primes[i]) % smallP] = d[nod] + primes[i], PQ.push ({-d[(nod + primes[i]) % smallP], (nod + primes[i]) % smallP});
        }
    }
}

bool solve (long long N, long long K)
{
    if (primes.size () == 1)
        return (N % K == 0);
    if (primes.size () == 2)
    {
        long long P = primes[0], Q = primes[1];
        ///N = P*alpha+Q*beta -> Q * beta = N modulo P -> beta = N / Q modulo P
        long long beta = mul (N % P, power (Q % P, P - 2, P), P);
        return (1LL * beta * Q <= N);
    }
    return (d[N % smallP] <= N);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

for (int i=2; i * i <= maxM; i++)
    if ((isComposite[i >> 3] & (1 << (i & 7))) == 0)
        for (int j=i * i; j <= maxM; j+=i)
            isComposite[j >> 3] |= 1 << (j & 7);
for (int i=2; i <= maxM; i++)
    if ((isComposite[i >> 3] & (1 << (i & 7))) == 0)
        pr[++nr] = i;
scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%I64d %I64d", &qr[i].first.second, &qr[i].first.first), qr[i].second = i;
sort (qr + 1, qr + N + 1);
for (int i=1; i<=N; i++)
{
    init (qr[i].first.first);
    int j = i;
    while (j + 1 <= N && qr[j + 1].first.first == qr[i].first.first)
        j ++;
    for (int k=i; k<=j; k++)
        ans[qr[k].second] = solve (qr[k].first.second, qr[k].first.first);
    i = j;
}
for (int i=1; i<=N; i++)
    if (ans[i]) printf ("YES\n");
    else printf ("NO\n");
return 0;
}