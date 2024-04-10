#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n,m,k;
int father[200111];

int Find(int ver)
{
    if (father[ver]==0)
    return ver;
    else
    {
        father[ver]=Find(father[ver]);

        return father[ver];
    }
}

vector<int> Graph[200111];
int BigList[500111];
int L=0;

void DFS(int ver,int dad)
{
    int i;

    L++;
    BigList[L]=ver;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i]==dad)
        continue;

        DFS(Graph[ver][i],ver);

        L++;
        BigList[L]=ver;
    }

    return;
}

int main()
{
    int i,j;
    int a,b;
    int lim=0;
    int lastend=0;
    int l,r;
    int r1,r2;

    scanf("%d %d %d",&n,&m,&k);

    lim=(2*n)/k;

    if ( (2*n)%k!=0 )
    lim++;

    for (i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);

        r1=Find(a);
        r2=Find(b);

        if (r1!=r2)
        {
            father[r1]=r2;

            Graph[a].push_back(b);
            Graph[b].push_back(a);
        }
    }

    DFS(1,0);

    for (i=1;i<=k;i++)
    {
        if (lastend>=L)
        {
            printf("1 1");
        }
        else
        {
            l=lastend+1;
            r=l+lim-1;
            if (r>L)
            r=L;

            printf("%d",r-l+1);
            for (j=l;j<=r;j++)
            {
                printf(" %d",BigList[j]);
            }

            lastend=r;
        }
        printf("\n");
    }

    return 0;
}