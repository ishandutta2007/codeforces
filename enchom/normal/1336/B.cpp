#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long llong;

int t, test;
int n[4];
int vals[4][200111];

llong ans = -1;

llong sq(llong a)
{
    return a*a;
}

void tryAns(llong A, llong B, llong C)
{
    llong val = sq(A-B) + sq(B-C) + sq(A-C);

    if (ans == -1 || ans > val)
        ans = val;
}

int main()
{
    int i,j,in;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        for (i=1;i<=3;i++)
        {
            scanf("%d",&n[i]);
        }

        for (i=1;i<=3;i++)
        {
            for (j=1;j<=n[i];j++)
            {
                scanf("%d",&vals[i][j]);
            }

            sort(vals[i]+1, vals[i]+1+n[i]);
        }

        int order[4] = {0, 1, 2, 3};

        ans = -1;

        do
        {
            int R = order[1], G = order[2], B = order[3];
            int pR = 1, pB = 1;
            for (i=1;i<=n[G];i++)
            {
                int curG = vals[G][i];

                while(pR < n[R] && vals[R][pR+1] <= curG)
                    pR++;
                while(pB < n[B] && vals[B][pB] < curG)
                    pB++;

                if (vals[R][pR] <= curG && curG <= vals[B][pB])
                {
                    tryAns(vals[R][pR], curG, vals[B][pB]);
                }
            }
        }while(next_permutation(order+1, order+4));

        printf("%lld\n",ans);
    }

    return 0;
}