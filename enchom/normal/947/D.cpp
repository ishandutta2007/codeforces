#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char S[100111];
char T[100111];
int n,m;
int q;

int bCountS[100111];
int bCountT[100111];

int SendingA[100111];
int TendingA[100111];

int getT(int L,int R)
{
    return bCountT[R]-bCountT[L-1];
}

int getS(int L,int R)
{
    return bCountS[R]-bCountS[L-1];
}

int main()
{
    int i,j;
    int L1,R1,L2,R2;
    int B1,B2;
    int A1,A2;

    scanf("%s",S+1);
    n=strlen(S+1);

    scanf("%s",T+1);
    m=strlen(T+1);

    for (i=1;i<=n;i++)
    {
        bCountS[i]=bCountS[i-1];

        if (S[i]=='B' || S[i]=='C')
            bCountS[i]++;

        //

        if (S[i]=='B' || S[i]=='C')
            SendingA[i]=0;
        else
            SendingA[i]=SendingA[i-1]+1;
    }

    for (i=1;i<=m;i++)
    {
        bCountT[i]=bCountT[i-1];

        if (T[i]=='B' || T[i]=='C')
            bCountT[i]++;

        //

        if (T[i]=='B' || T[i]=='C')
            TendingA[i]=0;
        else
            TendingA[i]=TendingA[i-1]+1;
    }

    scanf("%d",&q);

    for (i=1;i<=q;i++)
    {
        scanf("%d %d %d %d",&L1,&R1,&L2,&R2);

        B1=getS(L1,R1);
        B2=getT(L2,R2);

        if (B1==0)
        {
            A1=R1-L1+1;
        }
        else
        {
            A1=SendingA[R1];
        }

        if (B2==0)
        {
            A2=R2-L2+1;
        }
        else
        {
            A2=TendingA[R2];
        }

        if (B1>B2)
        {
            printf("0");
        }
        else if (B1<B2)
        {
            if ( (B2-B1)%2!=0 )
                printf("0");
            else
            {
                if (A1<A2)
                    printf("0");
                else
                {
                    if (B1==0 && A1==A2)
                        printf("0");
                    else
                        printf("1");
                }
            }
        }
        else
        {
            if (A1<A2)
                printf("0");
            else
            {
                if ( (A1-A2)%3==0 )
                    printf("1");
                else
                    printf("0");
            }
        }
    }

    return 0;
}