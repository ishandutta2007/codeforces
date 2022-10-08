#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long llong;

int n;
char str[200111];
int K;

int sum[200111];
int zerofol[200111];
int nextone[200111];

llong ANSWER = 0;

void countLarges(int sum, int L, int R)
{
    if (sum == 0)
        return;

    int Ldown, Rup;

    Ldown = L / sum;
    if (L % sum != 0)
        Ldown++;

    Rup = R / sum;

    Ldown = max(Ldown, K+1);

    if (Ldown <= Rup)
        ANSWER += (llong)Rup - (llong)Ldown + 1LL;

    return;
}

void countLargeMultiplier()
{
    int i;

    for (i=1;i<=n;i++)
    {
        int cursum = str[i] == '1' ? 1 : 0;
        int curpos = i;

        while(cursum * K <= n && curpos <= n)
        {
            countLarges(cursum, curpos-i+1, curpos-i+1+zerofol[curpos]);

            curpos = nextone[curpos + 1];
            cursum++;
        }
    }
}

llong values[200111];

void countSmallMultiplier()
{
    int i,j;

    for (i=1;i<=K;i++)
    {
        for (j=1;j<=n;j++)
        {
            values[j] = (llong)sum[j] * (llong)i - (llong)j;
        }
        values[n+1] = 0;

        sort(values+1,values+1+n+1);

        llong cv = values[1];
        int curcount = 1;

        for (j=2;j<=n+1;j++)
        {
            if (values[j] == cv)
                curcount++;
            else
            {
                ANSWER += ((llong)curcount * (llong)(curcount - 1))/2LL;
                cv = values[j];
                curcount = 1;
            }
        }
        ANSWER += ((llong)curcount * (llong)(curcount - 1))/2LL;
    }

    return;
}

int main()
{
    int i,j;

    scanf("%s",str+1);
    n = strlen(str+1);

    K = 1;
    while(K * K < n / 2)
        K++;

    sum[0] = 0;
    for (i=1;i<=n;i++)
    {
        sum[i] = sum[i-1] + (str[i] - '0');
    }

    zerofol[n] = 0;
    nextone[n] = str[n] == '1' ? n : n+1;
    nextone[n+1] = n+1;
    for (i=n-1;i>=1;i--)
    {
        if (str[i+1] == '0')
            zerofol[i] = zerofol[i+1] + 1;
        else
            zerofol[i] = 0;

        if (str[i] == '1')
            nextone[i] = i;
        else
            nextone[i] = nextone[i+1];
    }

    countLargeMultiplier();

    countSmallMultiplier();

    printf("%lld\n",ANSWER);

    return 0;
}