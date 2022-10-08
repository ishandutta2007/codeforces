#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;
#define MOD 1000000007LL
#define INF 2000000000

char s[5001];
int n;
int LCP[5002][5002];

void ComputeLCP()
{
    int i,j;

    for (i=1;i<=n;i++)
    {
        LCP[i][n+1]=0;
        LCP[n+1][i]=0;
    }
    LCP[n+1][n+1]=0;

    for (i=n;i>=1;i--)
    {
        for (j=n;j>=1;j--)
        {
            if (s[i]!=s[j])
            LCP[i][j]=0;
            else
            LCP[i][j]=LCP[i+1][j+1]+1;
        }
    }

    return;
}

int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int F[5002][5002];
int FSum[5002][5002];

int S[5002][5002];
int SMin[5002][5002];

void DP()
{
    int i,j;
    int sz;
    int k;
    int dif;

    for (i=1;i<=n;i++)
    {
        FSum[i][i+1]=0;
        SMin[i][i+1]=INF;
        for (j=i;j>=2;j--)
        {
            if (s[j]=='0')
            {
                F[i][j]=-1;
                S[i][j]=-1;
            }
            else
            {
                sz=(i-j+1);
                k=(j-sz);

                if (k>0)
                {
                    dif=LCP[k][j];
                    if (j+dif<=i)
                    {
                        if (s[j+dif]<s[k+dif])
                        k++;
                    }
                }
                else
                k=1;

                if (k>j-1)
                {
                    F[i][j]=-1;
                    S[i][j]=-1;
                }
                else
                {
                    F[i][j]=FSum[j-1][k];
                    S[i][j]=SMin[j-1][k]+1;
                }
            }

            if (F[i][j]!=-1)
            {
                FSum[i][j]=FSum[i][j+1]+F[i][j];

                if (FSum[i][j]>=MOD)
                FSum[i][j]-=MOD;
            }
            else
            {
                FSum[i][j]=FSum[i][j+1];
                SMin[i][j]=SMin[i][j+1];
            }

            if (S[i][j]!=-1)
            {
                SMin[i][j]=MIN(SMin[i][j+1],S[i][j]);
            }
            else
            {
                SMin[i][j]=SMin[i][j+1];
            }
        }

        F[i][1]=1;

        FSum[i][1]=FSum[i][2]+1;
        if (FSum[i][1]>=MOD)
        FSum[i][1]-=MOD;

        S[i][1]=1;
        SMin[i][1]=1;
    }

    return;
}

int pow2[5001];

int main()
{
    int i,j;
    int increment;
    int curval;
    int bestans=-1,curans;
    int p;
    bool addedtoomuch=false;

    pow2[0]=1;
    for (i=1;i<=5000;i++)
    {
        pow2[i]=pow2[i-1]*2;
        pow2[i]%=MOD;
    }

    scanf("%s",s+1);
    n=strlen(s+1);

    ComputeLCP();
    DP();

    printf("%d\n",FSum[n][1]);

    curval=0;
    p=0;
    for (i=n;i>=1;i--)
    {
        if (s[i]=='1' && p>20)
        {
            addedtoomuch=true;
        }

        curval=curval+pow2[p]*(s[i]-'0');
        curval%=MOD;

        p++;

        if (SMin[n][i]==INF || SMin[n][i]==-1)
        continue;

        curans=SMin[n][i]+curval;
        curans%=MOD;

        if (addedtoomuch)
        {
            if (bestans==-1)
            bestans=curans;
        }
        else
        {
            if (bestans==-1 || bestans>curans)
            {
                bestans=curans;
            }
        }
    }

    printf("%d\n",bestans);

    return 0;
}