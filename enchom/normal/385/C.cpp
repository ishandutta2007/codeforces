#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 10000000

int amount[MAX+1];
int n;
bool prime[MAX+1];
int divs[MAX+1];
int presums[MAX+1];

int main()
{
    int k;
    int i,j;
    int q,l,r;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&k);
        amount[k]++;
    }

    for (i=1;i<=MAX;i++)
    {
        prime[i]=true;
    }
    prime[1]=false;

    for (i=2;i<=MAX;i++)
    {
        if (prime[i])
        {
            for (j=i;j<=MAX;j+=i)
            {
                divs[i]+=amount[j];
                prime[j]=false;
            }
        }
    }

    for (i=1;i<=MAX+1;i++)
    {
        presums[i]=presums[i-1]+divs[i];
    }

    scanf("%d",&q);

    for (i=1;i<=q;i++)
    {
        scanf("%d %d",&l,&r);

        if (l>MAX)
        {
            printf("0\n");
            continue;
        }

        if (r>MAX)
        r=MAX;

        printf("%d\n",presums[r]-presums[l-1]);
    }

    return 0;
}