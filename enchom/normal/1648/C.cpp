#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

const llong MOD = 998244353LL;

llong fact[200111];
llong invFact[200111];
llong invNum[200111];

llong FastPow(llong k, llong p)
{
    if (p == 0LL)
        return 1LL;

    llong P = FastPow(k, p / 2LL);
    P = (P * P) % MOD;

    if (p % 2LL == 1LL)
        P = (P * k) % MOD;

    return P;
}

llong Inv(llong x)
{
    return FastPow(x, MOD - 2);
}

const int MAXVAL = 200000;

int n, m;
int bag[200111];

llong zVal;
llong IT[800111];
int LEAFOFFSET;

llong getSum(int R)
{
    if (R == 0)
        return 0LL;

    int ind = LEAFOFFSET + R;
    llong ans = IT[ind];

    while(ind > 1)
    {
        if (ind % 2 == 1)
            ans += IT[ind - 1];
        ind /= 2;
    }

    ans %= MOD;

    return ans;
}

void setVal(int k, llong v)
{
    int ind = k + LEAFOFFSET;

    IT[ind] = v;
    ind /= 2;

    while(ind > 0)
    {
        IT[ind] = (IT[2*ind] + IT[2*ind+1]);

        if (IT[ind] >= MOD)
            IT[ind] -= MOD;

        ind /= 2;
    }
}

int main()
{
    int i, j;

    fact[0] = 1LL;
    invFact[0] = Inv(1LL);
    for (i=1;i<=MAXVAL;i++)
    {
        fact[i] = (fact[i-1] * (llong)i) % MOD;
        invFact[i] = Inv(fact[i]);
        invNum[i] = Inv(i);
    }

    LEAFOFFSET = 1;
    while(LEAFOFFSET < MAXVAL)
        LEAFOFFSET *= 2;
    LEAFOFFSET--;

    scanf("%d %d", &n, &m);

    for (i=1;i<=n;i++)
    {
        int a;
        scanf("%d", &a);
        bag[a]++;
    }

    zVal = 1LL;
    for (i=1;i<=MAXVAL;i++)
    {
        if (bag[i] == 0)
            IT[LEAFOFFSET + i] = 0;
        else
            IT[LEAFOFFSET + i] = (fact[ bag[i] ] * invFact[ bag[i] - 1 ]) % MOD;

        if (bag[i] != 0)
        {
            //printf("Adding 1/%d! to zVal\n", bag[i]);
            //printf("Value at %d is %d! / %d!\n", i, bag[i], bag[i] - 1);
        }
        zVal *= invFact[ bag[i] ];
        zVal %= MOD;
    }

    for (i=LEAFOFFSET;i>=1;i--)
    {
        IT[i] = (IT[2*i] + IT[2*i+1]) % MOD;
    }

    llong answer = 0LL;
    int N = n;
    for (i=1;i<=m;i++)
    {
        int k;

        scanf("%d", &k);

        //printf("\nProcessing %d\n", k);

        llong ans = (fact[N - 1] * zVal) % MOD;
        ans *= getSum(k - 1);
        ans %= MOD;

        //printf("Getting %lld\n", ans);

        answer += ans;
        if (answer >= MOD)
            answer -= MOD;

        if (bag[k] > 0)
        {
            N--;
            zVal = (zVal * fact[ bag[k] ]) % MOD;
            zVal = (zVal * invFact[ bag[k] - 1 ]) % MOD;

            //printf("N becomes %d\n", N);
            //printf("zVal gets multiplied by %d! / %d!\n", bag[k], bag[k] - 1);

            bag[k]--;

            if (bag[k] == 0)
                setVal(k, 0);
            else
                setVal(k, (fact[ bag[k] ] * invFact[ bag[k] - 1 ]) % MOD);
        }
        else
        {
            if (N == 0)
                answer = (answer + 1) % MOD;

            break;
        }
    }

    printf("%lld\n", answer);

    return 0;
}