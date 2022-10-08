#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;
#define INF 1999999999

int n,k;
int arr[110001];
char str[21];

int Parse()
{
    if (str[1]=='?')
    return INF;

    int i;
    int L=strlen(str+1);
    bool ngt=false;
    int num=0;

    for (i=1;i<=L;i++)
    {
        if (str[i]=='-')
        {
            ngt=true;
            continue;
        }

        num*=10;
        num+=(int)(str[i]-'0');
    }

    if (ngt)
    num=-num;

    return num;
}

int Line[110001];
int L;

bool Fill(int L,int R,int lowbound,int upbound)
{
    if (L>R)
    return true;

    int i;

    if ((Int)upbound-(Int)lowbound-1LL<(Int)R-(Int)L+1LL)
    {
        return false;
    }

    if (upbound<=0) ///negative side
    {
        for (i=R;i>=L;i--)
        {
            Line[i]=upbound-(R-i+1);
        }
    }
    else if (lowbound>=0) ///positive side
    {
        for (i=L;i<=R;i++)
        {
            Line[i]=lowbound+(i-L+1);
        }
    }
    else ///both sides
    {
        int wantednegative=(R-L+1)/2;
        int wantedpositive=(R-L)/2;
        int b;

        if (lowbound<-wantednegative && upbound>wantedpositive) //both are fine
        {
            b=-wantednegative;
            for (i=L;i<=R;i++)
            {
                Line[i]=b;
                b++;
            }
        }
        else if (lowbound>=-wantednegative) //left is wrong
        {
            b=lowbound+1;
            for (i=L;i<=R;i++)
            {
                Line[i]=b;
                b++;
            }
        }
        else //right is wrong
        {
            b=upbound-1;
            for (i=R;i>=L;i--)
            {
                Line[i]=b;
                b--;
            }
        }
    }

    return true;
}

bool SolveLine()
{
    int lowbound=-INF;
    int beg=1;
    int i;
    int curnum=-INF;

    //cout<<"Processing line"<<endl;

    for (i=1;i<=L;i++)
    {
        if (Line[i]!=INF)
        {
            if (Line[i]<=curnum)
            return false;

            curnum=Line[i];
        }
    }

    //cout<<"here"<<endl;

    for (i=1;i<=L;i++)
    {
        if (Line[i]!=INF)
        {
            if (!Fill(beg,i-1,lowbound,Line[i]))
            return false;

            lowbound=Line[i];
            beg=i+1;
        }
    }

    if (!Fill(beg,L,lowbound,INF))
    return false;

    //cout<<"true as fuck"<<endl;

    return true;
}

int main()
{
    int i,j;

    scanf("%d %d",&n,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%s",str+1);

        arr[i]=Parse();
    }

    for (i=1;i<=k;i++)
    {
        L=0;
        for (j=i;j<=n;j+=k)
        {
            L++;
            Line[L]=arr[j];
        }

        if (!SolveLine())
        {
            printf("Incorrect sequence\n");
            return 0;
        }

        L=0;
        for (j=i;j<=n;j+=k)
        {
            L++;
            arr[j]=Line[L];
        }
    }

    for (i=1;i<=n;i++)
    {
        printf("%d",arr[i]);
        if (i!=n)
        printf(" ");
    }
    printf("\n");

    return 0;
}