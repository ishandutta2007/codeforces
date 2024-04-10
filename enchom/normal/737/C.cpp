#include <iostream>
#include <stdio.h>
using namespace std;

int n,s;
int a[200111];
int mistakes=0;
int handful=0;

int ctr[200111];

int main()
{
    int i;
    int reached;
    int backend;

    scanf("%d %d",&n,&s);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);

        ctr[ a[i] ]++;
    }

    if (a[s]!=0)
    {
        ctr[ a[s] ]--;

        mistakes++;
        a[s]=0;
    }

    for (i=1;i<=n;i++)
    {
        if (i!=s && a[i]==0)
        {
            mistakes++;
            handful++;
        }
    }

    reached=0;

    for (i=1;i<=n-1;i++)
    {
        if (ctr[i]>0)
        {
            reached=i;
        }
        else
        {
            if (handful==0)
            break;

            handful--;

            ctr[i]++;

            reached=i;
        }
    }

    backend=n-1;

    while(backend>reached)
    {
        if (ctr[reached+1]>0)
        {
            reached++;
            continue;
        }

        if (ctr[backend]>0)
        {
            mistakes++;
            ctr[reached+1]++;
            ctr[backend]--;
        }
        else
        {
            backend--;
        }
    }

    printf("%d\n",mistakes);

    return 0;
}