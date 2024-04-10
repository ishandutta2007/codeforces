#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

const llong MOD = 998244353LL;

llong fact[200111];

int n,k;
int ans[200111];

int relevant = 0;
llong booster = 1LL;

llong k2pows[200111];
llong twopows[200111];

llong inv2 = 499122177LL;

llong FastPow(llong k, llong p)
{
    if (p == 1LL)
        return k;
    else if (p == 0LL)
        return 1LL;

    llong P = FastPow(k, p/2);
    P = (P * P) % MOD;

    if (p % 2 == 1)
        P = (P * k) % MOD;

    return P;
}

llong C(int K, int N)
{
    llong bot = (fact[K] * fact[N-K]) % MOD;

    /*cout<<"Choose "<<K<<" of "<<N<<endl;
    cout<<fact[N]<<" top"<<endl;
    cout<<bot<<" bottom"<<endl;
    cout<<FastPow(bot, MOD-2)<<" invbot"<<endl;*/
    return (FastPow(bot, MOD-2) * fact[N]) % MOD;
}

int main()
{
    int i;

    fact[0] = 1LL;
    twopows[0] = 1LL;
    for (i=1;i<=200100;i++)
    {
        fact[i] = fact[i-1] * (llong)i;
        fact[i] %= MOD;

        twopows[i] = twopows[i-1] * 2LL;
        twopows[i] %= MOD;
    }

    scanf("%d %d",&n,&k);

    if (k > 1)
    {
        k2pows[0] = 1LL;
        for (i=1;i<=200100;i++)
        {
            k2pows[i] = k2pows[i-1] * (llong)(k-2LL);
            k2pows[i] %= MOD;
        }
    }

    for (i=1;i<=n;i++)
    {
        scanf("%d",&ans[i]);
    }

    for (i=1;i<n;i++)
    {
        if (ans[i] == ans[i+1])
        {
            booster *= (llong)k;
            booster %= MOD;
        }
        else
            relevant++;
    }

    if (ans[1] == ans[n])
    {
        booster *= (llong)k;
        booster %= MOD;
    }
    else
        relevant++;

    //cout<<"Total of "<<relevant<<" relevant"<<endl;

    llong ans = 0;
    for (i=1;i<=relevant;i++)
    {
        //cout<<endl;
        ///Choosing i definite answers
        llong v = C(i, relevant) * k2pows[relevant - i];
        v %= MOD;

        //cout<<"Choosing "<<i<<" relevant"<<endl;
        //cout<<v<<" ways to choose positions and zeroes"<<endl;
        //cout<<C(i, relevant)<<" for positions and "<<k2pows[relevant-i]<<" for zeroes"<<endl;

        llong ways = twopows[i];

        //cout<<twopows[i]<<" twopow"<<endl;

        if (i % 2 == 0)
            ways -= C(i/2, i);

        if (ways < 0)
            ways += MOD;

        //cout<<"still "<<ways<<endl;

        ways *= inv2;
        ways %= MOD;

        //cout<<ways<<" ways to win"<<endl;

        v = (v * ways) % MOD;

        //cout<<"Final way = "<<v<<endl;

        ans += v;
        if (ans >= MOD)
            ans -= MOD;
    }

    ans *= booster;
    ans %= MOD;

    printf("%lld\n",ans);

    return 0;
}