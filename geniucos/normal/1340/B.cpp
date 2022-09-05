#include<bits/stdc++.h>

using namespace std;

int N, K, x[2018], dp[2018][2018], msk[10], nrb[2018];
string d[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int getMask (string s)
{
    int msk = 0;
    for (int i=0; i<7; i++)
        if (s[i] == '1')
            msk |= 1 << i;
    return msk;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

for (int i=0; i<10; i++)
    msk[i] = getMask (d[i]);
for (int i=1; i<128; i++)
    nrb[i] = nrb[i >> 1] + (i & 1);
scanf ("%d %d\n", &N, &K);
for (int i=1; i<=N; i++)
{
    char sir[10];
    scanf ("%s", sir);
    string curr = sir;
    x[i] = getMask (curr);
}
dp[N + 1][0] = 1;
for (int i=N + 1; i>1; i--)
    for (int j=0; j<=K; j++)
        if (dp[i][j])
            for (int k=0; k<10; k++)
                if ((msk[k] & x[i - 1]) == x[i - 1])
                    dp[i - 1][j + nrb[msk[k] ^ x[i - 1]]] = 1;
if (!dp[1][K])
{
    printf ("-1\n");
    return 0;
}
for (int i=1; i<=N; i++)
{
    int j = 9;
    while (j >= 0)
    {
        if ((msk[j] & x[i]) == x[i])
        {
            int cnt = nrb[msk[j] ^ x[i]];
            if (cnt <= K && dp[i + 1][K - cnt])
            {
                K -= cnt;
                break;
            }
        }
        j --;
    }
    assert (j >= 0 && (msk[j] & x[i]) == x[i]);
    printf ("%d", j);
}
assert (K == 0);
printf ("\n");
return 0;
}