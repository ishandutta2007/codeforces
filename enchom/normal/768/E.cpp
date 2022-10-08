#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
#include <string.h>
#include <set>
using namespace std;
typedef unsigned long long UInt;

int ans=0;
int moves[1111];
int L=0;
int counter=0;
UInt B=97;
int Starter[62];

vector<int> Kids[1000111];
int SG[1000111];

int Add()
{
    int i;
    int sum=0,need;
    bool good=false;

    counter++;

    SG[counter]=-1;

    return counter;
}

void Batrak(int sum,int cantake,int myid)
{
    if (sum<0)
    return;
    if (sum==0)
    {
        return;
    }
    if (cantake>sum)
    return;

    int i,kid;

    for (i=cantake;i<=sum;i++)
    {
        L++;
        moves[L]=i;

        kid=Add();

        Kids[myid].push_back(kid);

        Batrak(sum-i,i+1,kid);

        L--;
    }

    return;
}

int GetSG(int ver)
{
    if (SG[ver]!=-1)
    return SG[ver];

    int i;
    bool mex[72];
    int val;

    memset(mex,false,sizeof(mex));

    for (i=0;i<Kids[ver].size();i++)
    {
        val=GetSG( Kids[ver][i] );

        mex[val]=true;
    }

    for (i=0;i<=70;i++)
    {
        if (!mex[i])
        {
            SG[ver]=i;
            break;
        }
    }

    return SG[ver];
}

int SGS[62];

int main()
{
    int i;
    int n,a;
    int XS=0;

    for (i=1;i<=60;i++)
    {
        L=1;
        moves[1]=i;

        Starter[i]=Add();

        Batrak(i,1,Starter[i]);
    }

    for (i=1;i<=60;i++)
    {
        SGS[i]=GetSG(Starter[i]);
    }

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a);

        XS^=SGS[a];
    }

    if (XS==0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}