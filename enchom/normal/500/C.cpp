#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n,m;
int w[1011];
int books[1011];

int order[1011];
int L=0;

bool seen[1011];

int Cost(int book)
{
    int i;
    int sum=0;
    int id;
    int rem;

    for (i=1;i<=n;i++)
    {
        if (order[i]==book)
        {
            id=i;
            break;
        }
        else
        sum+=w[ order[i] ];
    }

    rem=order[id];

    for (i=id;i>1;i--)
    {
        order[i]=order[i-1];
    }
    order[1]=rem;

    return sum;
}

int main()
{
    int i;
    int ans=0;

    memset(seen,false,sizeof(seen));

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }

    for (i=1;i<=m;i++)
    {
        scanf("%d",&books[i]);

        if (!seen[ books[i] ])
        {
            seen[ books[i] ]=true;
            L++;
            order[L]=books[i];
        }
    }

    for (i=1;i<=n;i++)
    {
        if (!seen[i])
        {
            L++;
            order[L]=i;

            seen[i]=true;
        }
    }

    for (i=1;i<=m;i++)
    {
        ans+=Cost(books[i]);
    }

    printf("%d\n",ans);

    return 0;
}