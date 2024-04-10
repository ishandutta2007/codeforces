#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long llong;

const llong MOD = 998244353;

char S[3111];
int n;
char T[3111];
int m;

llong F[3111][3111];
llong getF(int total, int sufEnd)
{
    if (total == 0)
    {
        return 0LL;
    }
    else if (total == 1)
    {
        if (T[sufEnd] == S[1])
            return 2LL;
        else
            return 0LL;
    }

    if (F[total][sufEnd] != -1)
        return F[total][sufEnd];

    int begInd = sufEnd - total + 1;

    F[total][sufEnd] = 0;

    if (begInd < 1)
        return 0;

    if (T[sufEnd] == S[total])
        F[total][sufEnd] += getF(total-1, sufEnd-1);
    if (T[begInd] == S[total])
        F[total][sufEnd] += getF(total-1, sufEnd);

    F[total][sufEnd] %= MOD;

    return F[total][sufEnd];
}

llong G[3111][3111];
llong getG(int curInd, int pref)
{
    if (curInd > n)
    {
        if (pref == 0)
            return 1LL;
        else
            return 0LL;
    }

    if (G[curInd][pref] != -1)
        return G[curInd][pref];

    G[curInd][pref] = 0;
    if (pref == 0)
        G[curInd][pref] = 1;

    G[curInd][pref] += getG(curInd+1, pref);
    if (pref == m) ///Discard left
        G[curInd][pref] += getG(curInd+1, pref);

    if (pref > 0 && T[pref] == S[curInd])
        G[curInd][pref] += getG(curInd+1, pref-1);

    G[curInd][pref] %= MOD;

    return G[curInd][pref];
}

int main()
{
    memset(F,-1,sizeof(F));
    memset(G,-1,sizeof(G));

    int i,j;

    scanf("%s",S+1);
    n = strlen(S+1);
    scanf("%s",T+1);
    m = strlen(T+1);

    ///Left-only
    llong ans = getG(1, m);

    for (i=1;i<=m;i++)
    {
        ///Filled up RHS at i
        if (S[i] == T[m])
        {
            //cout<<getG(i+1,m-i)<<" remainder"<<endl;
            //cout<<getF(i-1,m-1)<<" mult"<<endl;
            if (i > 1)
                ans += getF(i-1, m-1) * getG(i+1, m-i);
            else
                ans += getG(i+1, m-i);

            ans %= MOD;
        }

        //cout<<"At "<<i<<" its now "<<ans<<endl;
        //cout<<"F["<<i<<"]["<<m<<"] = "<<getF(i, m)<<endl;
        //cout<<"G["<<i+1<<"]["<<m-i<<"]="<<getG(i+1,m-i)<<endl;
    }

    printf("%lld\n",ans);
}