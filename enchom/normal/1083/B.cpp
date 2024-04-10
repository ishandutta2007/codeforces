#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

int n;
llong k;
char s[500111];
char t[500111];
llong ans = 0;

llong chances[500111];

llong MIN(llong a,llong b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    int i;
    int beg;

    scanf("%d",&n);
    scanf("%lld",&k);

    scanf("%s",s+1);
    scanf("%s",t+1);

    beg = n + 1;
    for (i=1;i<=n;i++)
    {
        if (s[i] != t[i])
        {
            beg = i;
            break;
        }
    }

    if (k == 1)
    {
        printf("%d\n",n);
        return 0;
    }

    ans = 2LL * (llong)n - (llong)(beg - 1);
    k -= 2;

    if (beg > n)
    {
        printf("%lld\n",ans);
        return 0;
    }

    ///Dev from S
    for (i=n;i>beg;i--)
    {
        ///Deviation at i
        if (s[i] == 'a')
        {
            chances[i]++;
        }

        //chances *= 2LL;
        //if (chances > k)
        //    chances = k + 1LL;
    }

    ///Dev from t
    //chances = 1LL;
    for (i=n;i>beg;i--)
    {
        ///Deviation at i
        if (t[i] == 'b')
        {
            chances[i]++;
        }

        //chances *= 2LL;
        //if (chances > k)
        //    chances = k + 1LL;
    }

    for (i=beg+1;i<=n;i++)
    {
        //cout<<"AT "<<i<<endl;
        //cout<<"ChancesA = "<<chancesA[i]<<endl;
        //cout<<"ChancesB = "<<chancesB[i]<<endl;

        ans += MIN(chances[i], k);
        chances[i+1] += chances[i] * 2LL;
        if (chances[i+1] > k)
            chances[i+1] = k + 1LL;

        /*llong total = chancesA[i] + chancesB[i];
        ans += MIN(c)

        if (chancesA[i] > 0 && k > 0)
        {
            chancesA[i]--;
            k--;
            ans++;
            ans += (llong)(n-i);
        }

        if (chancesB[i] > 0 && k > 0)
        {
            chancesB[i]--;
            k--;
            ans++;
            ans += (llong)(n-i);

            //cout<<"Added and got "<<ans<<endl;
            //cout<<"k down to "<<k<<endl;
        }

        llong taken = MIN(chancesA[i], k);

        chancesA[i] -= taken;
        k -= taken;
        ans += taken * (llong)(n-i);

        taken = MIN(chancesB[i], k);

        chancesB[i] -= taken;
        k -= taken;
        ans += taken * (llong)(n-i);*/
    }

    printf("%lld\n",ans);

    return 0;
}