#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char s[2001];
int n;

char p[501];
int m;

int Next[2001][26];
int Match[2001][2001];

void CalculateNextLetters()
{
    int i,j;

    memset(Next,-1,sizeof(Next));

    for (i=1;i<=n;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            if (Next[i][ s[j]-'a' ]==-1)
            {
                Next[i][ s[j]-'a' ]=j;
            }
        }
    }

    return;
}

void Fill(int l,int r)
{
    if (l<1 || r>n)
    return;
    if (Match[l][r]!=0)
    return;

    Match[l][r]=1;
    Fill(l-1,r);
    Fill(l,r+1);

    return;
}

void FindMatchings()
{
    int i,j;
    int cur;

    memset(Match,0,sizeof(Match));

    for (i=1;i<=n;i++)
    {
        if (s[i]==p[1])
        {
            cur=i;

            for (j=2;j<=m;j++)
            {
                cur=Next[cur][ p[j]-'a' ];

                if (cur==-1)
                break;
            }

            if (cur!=-1)
            {
                Fill(i,cur);
            }
        }
    }

    return;
}

int BS(int k)
{
    int l=1,r=k;
    int best=-1,mid;

    while(l<=r)
    {
        mid=(l+r)/2;

        if (Match[mid][k])
        {
            best=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }

    return best;
}

int F[2001][2001];

void DP()
{
    int i,j;
    int k;
    int mustremove;

    memset(F,-1,sizeof(F));

    F[0][0]=0;

    for (i=1;i<=n;i++)
    {
        for (j=0;j<=n;j++)
        {
            F[i][j]=F[i-1][j];

            if (j>0)
            {
                if (F[i-1][j-1]!=-1)
                {
                    if (F[i][j]==-1 || F[i][j]<F[i-1][j-1])
                    F[i][j]=F[i-1][j-1];
                }
            }

            if (s[i]==p[m])
            {
                k=BS(i);
                if (k==-1)
                continue;

                mustremove=(i-k+1)-m;

                if (j>=mustremove)
                {
                    if (F[k-1][j-mustremove]!=-1)
                    {
                        if (F[i][j]==-1 || F[i][j]<F[k-1][j-mustremove]+1)
                        {
                            F[i][j]=F[k-1][j-mustremove]+1;
                        }
                    }
                }
            }
        }
    }
}


int main()
{
    int i;

    scanf("%s",s+1);
    n=strlen(s+1);

    scanf("%s",p+1);
    m=strlen(p+1);

    CalculateNextLetters();
    FindMatchings();
    DP();

    for (i=0;i<=n;i++)
    {
        printf("%d",F[n][i]);
        if (i!=n)
        printf(" ");
    }
    printf("\n");

    return 0;
}