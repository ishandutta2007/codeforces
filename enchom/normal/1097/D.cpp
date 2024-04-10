#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
typedef long long llong;

const llong MOD = 1000000007LL;
llong n;
int k;

llong FastPow(llong num,llong pw)
{
    if (pw == 0)
        return 1LL;
    if (pw == 1)
        return num;

    llong P = FastPow(num, pw/2LL);

    P = (P*P) % MOD;

    if (pw%2 == 1)
        P = (P*num) % MOD;

    return P;
}

llong div(llong q)
{
    return FastPow(q,MOD-2);
}

llong prob[101];
llong divs[101];

void getProbs(int ctr)
{
    int i,j,in;

    memset(prob,0,sizeof(prob));

    prob[ctr] = 1;

    for (i=1;i<=k;i++)
    {
        for (j=0;j<=ctr;j++)
        {
            prob[j] = prob[j] * divs[j+1];
            if (prob[j] >= MOD)
                prob[j] %= MOD;

            for (in=j+1;in<=ctr;in++)
            {
                prob[j] += prob[in] * divs[in+1];

                if (prob[j] >= MOD)
                    prob[j] %= MOD;
            }
        }
    }

    return;
}

int main()
{
    llong i,j;
    llong ans = 1LL;

    for (i=1;i<=100;i++)
    {
        divs[i] = div(i);
    }

    scanf("%lld",&n);
    //n = 32416190071LL;
    //n = 64LL*81LL*25LL*7LL*11LL*13LL*17LL*19LL*23LL*29LL*31LL;
    scanf("%d",&k);
    //k = 10000;

    i = 2;
    while(i <= n)
    {
        if (i * i > n)
            i = n;

        int ctr = 0;

        while(n % i == 0)
        {
            n /= i;
            ctr++;
        }

        if (ctr == 0)
        {
            i++;
            continue;
        }

        getProbs(ctr);

        llong newans = 0;

        //cout<<"Divisor "<<i<<" for "<<ctr<<" times"<<endl;
        for (j=0;j<=ctr;j++)
        {
            //cout<<"Prob for "<<j<<" is "<<prob[j]<<endl;
            newans += ( (prob[j] * FastPow(i%MOD, j)) % MOD ) * ans;
            if (newans >= MOD)
                newans %= MOD;
        }

        ans = newans;

        i++;
    }

    printf("%lld\n",ans);

    return 0;
}