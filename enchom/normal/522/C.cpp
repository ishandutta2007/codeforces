#include <iostream>
#include <stdio.h>
using namespace std;

int t;
int m,k;
int a[100011];
bool Immortal[100011];
int F[100011],R[100011];

bool Gone[100011];

int main()
{
    int test;
    int i;
    bool HasFinished=false;
    bool FirstTime;
    int FT;
    int Choices;
    int FTChoices;
    int BlackSheep;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d",&m,&k);

        for (i=1;i<=k;i++)
        {
            scanf("%d",&a[i]);
            Gone[i]=false;
        }

        HasFinished=false;
        FirstTime=true;
        Choices=0;
        for (i=1;i<=m-1;i++)
        {
            scanf("%d %d",&F[i],&R[i]);

            if (R[i]==1 && FirstTime) ///special moment
            {
                FT=i;
                FTChoices=Choices;

                FirstTime=false;
            }

            if (F[i]==0)
            Choices++;
            else
            a[ F[i] ]--;
        }

        if (FirstTime) ///no dissapoints
        {
            for (i=1;i<=k;i++)
            {
                if (a[i]<=Choices)
                printf("Y");
                else
                printf("N");
            }
            printf("\n");
        }
        else
        {
            for (i=m-1;i>=FT;i--)
            {
                if (F[i]!=0)
                Immortal[ F[i] ]=true;
            }

            BlackSheep=999999999;
            for (i=1;i<=k;i++)
            {
                if (!Immortal[i])
                {
                    if (a[i]<=FTChoices)
                    {
                        Gone[i]=true;

                        if (a[i]<BlackSheep)
                        BlackSheep=a[i];
                    }
                }
            }

            for (i=1;i<=k;i++)
            {
                if (!Gone[i])
                {
                    if (a[i]<=Choices-BlackSheep)
                    {
                        Gone[i]=true;
                    }
                }
            }

            for (i=1;i<=k;i++)
            {
                if (Gone[i])
                printf("Y");
                else
                printf("N");
            }
            printf("\n");

            for (i=m-1;i>=FT;i--)
            {
                if (F[i]!=0)
                Immortal[ F[i] ]=false;
            }
        }
    }

    return 0;
}