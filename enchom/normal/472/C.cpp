#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define INF 999999999

int n;
int p[100001];

char fname[100001][51];
int fL[100001];

char sname[100001][51];
int sL[100001];

bool F[100001][2];

int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

bool IsLess(int id1,int fs1,int id2,int fs2)
{
    int L=INF;
    int i;
    char c1,c2;
    int L1,L2;

    if (fs1==0)
    L1=fL[id1];
    else
    L1=sL[id1];

    if (fs2==0)
    L2=fL[id2];
    else
    L2=sL[id2];

    L=MIN(L1,L2);

    for (i=1;i<=L;i++)
    {
        if (fs1==0)
        c1=fname[id1][i];
        else
        c1=sname[id1][i];

        if (fs2==0)
        c2=fname[id2][i];
        else
        c2=sname[id2][i];

        if (c1<c2)
        return true;
        else if (c1>c2)
        return false;
    }

    return L1<L2;
}

int main()
{
    int i;
    int cur,last;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%s",fname[i]+1);
        scanf("%s",sname[i]+1);

        fL[i]=strlen(fname[i]+1);
        sL[i]=strlen(sname[i]+1);
    }

    for (i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }

    F[1][0]=true;
    F[1][1]=true;

    for (i=2;i<=n;i++)
    {
        last=p[i-1];
        cur=p[i];

        ///F[i][0]
        if (F[i-1][0] && IsLess(last,0,cur,0))
        F[i][0]=true;
        else if (F[i-1][1] && IsLess(last,1,cur,0))
        F[i][0]=true;
        else
        F[i][0]=false;

        ///F[i][1]
        if (F[i-1][0] && IsLess(last,0,cur,1))
        F[i][1]=true;
        else if (F[i-1][1] && IsLess(last,1,cur,1))
        F[i][1]=true;
        else
        F[i][1]=false;
    }

    if (F[n][1] || F[n][0])
    printf("YES\n");
    else
    printf("NO\n");

    return 0;
}