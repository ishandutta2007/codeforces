#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n;
int p[1000111];
vector<int> cycles[1000111];
bool TFO[1000111];

int c[1000111];
int cL=0;

int c2[1000111];
int c2L=0;

void GetCycle(int v)
{
    if (cL>=1 && v==c[1])
    return;

    TFO[v]=true;

    cL++;
    c[cL]=v;

    GetCycle(p[v]);

    return;
}

int corder[1000111];
int L2=0;

int q[1000111];

void Odd()
{
    int i;
    int ind=1;

    for (i=1;i<=cL;i++)
    {
        corder[ind]=c[i];

        ind+=2;
        if (ind>cL)
        ind-=cL;
    }

    for (i=1;i<cL;i++)
    {
        q[ corder[i] ]=corder[i+1];
    }
    q[ corder[cL] ]=corder[1];

    return;
}

void Even()
{
    int i;
    int ind=0;

    for (i=1;i<=cL;i++)
    {
        ind++;
        corder[ind]=c[i];

        ind++;
        corder[ind]=c2[i];
    }

    for (i=1;i<ind;i++)
    {
        q[ corder[i] ]=corder[i+1];
    }
    q[ corder[ind] ]=corder[1];

    return;
}

int main()
{
    int i,j,in;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }

    for (i=1;i<=n;i++)
    {
        if (!TFO[i])
        {
            cL=0;

            GetCycle(i);

            cycles[cL].push_back(i);
        }
    }

    for (i=1;i<=n;i++)
    {
        if (i%2==0)
        {
            if ((int)cycles[i].size()%2==1)
            {
                printf("-1\n");
                return 0;
            }
        }
    }

    for (i=1;i<=n;i++)
    {
        if (i%2==1)
        {
            for (j=0;j<cycles[i].size();j++)
            {
                cL=0;

                GetCycle(cycles[i][j]);

                Odd();
            }
        }
        else
        {
            for (j=0;j<cycles[i].size();j+=2)
            {
                cL=0;

                GetCycle(cycles[i][j]);

                for (in=1;in<=cL;in++)
                {
                    c2[in]=c[in];
                }
                c2L=cL;

                cL=0;

                GetCycle(cycles[i][j+1]);

                Even();
            }
        }
    }

    for (i=1;i<=n;i++)
    {
        printf("%d",q[i]);

        if (i!=n)
        printf(" ");
    }
    printf("\n");

    return 0;
}