#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long double Double;
typedef long long Int;

int nums[200111];
Int psums[200111];
Double invsums[200111];

Double regioncost[200111];

Int GetSum(int L,int R)
{
    return psums[R]-psums[L-1];
}

Double GetInv(int L,int R)
{
    return invsums[R]-invsums[L-1];
}

Double GetReg(int L,int R)
{
    return regioncost[R]-regioncost[L-1]-(Double)GetSum(1,L-1)*GetInv(L,R);
}

int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

Double MIN(Double a,Double b)
{
    if (a<b)
    return a;
    else
    return b;
}

struct line
{
    Double a,b;
};

Double Cross(line A,line B)
{
    return (A.b-B.b)/(B.a-A.a);
}

vector<line> UE[52];

void AddLine(int ind,line L)
{
    while(UE[ind].size()>1)
    {
        if (Cross( UE[ind][ (int)UE[ind].size()-2 ],L )<Cross( UE[ind][ (int)UE[ind].size()-1 ],UE[ind][ (int)UE[ind].size()-2 ] ))
        {
            UE[ind].pop_back();
        }
        else
        break;
    }

    UE[ind].push_back(L);

    return;
}

line Find(int ind,Double val)
{
    int l=1,r=(int)UE[ind].size()-1;
    int mid,best=0;

    while(l<=r)
    {
        mid=(l+r)/2;

        if (Cross(UE[ind][mid],UE[ind][mid-1])<val)
        {
            best=mid;
            l=mid+1;
        }
        else
        r=mid-1;
    }

    return UE[ind][best];
}

int main()
{
    //freopen("t.txt","r",stdin);

    int n,k;
    int i,j,in;
    int pch;
    Double val;
    Double newval;
    int cur,op;
    int l,r,mid,best;
    Double v1,v2;
    int cb;
    int dist;
    int ctr=0;
    int badseq;
    Double FVal;
    line LN;

    scanf("%d %d",&n,&k);

    psums[0]=0;
    invsums[0]=0.0;
    regioncost[0]=0.0;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&nums[i]);

        psums[i]=psums[i-1]+(Int)nums[i];
        invsums[i]=invsums[i-1]+1.0/(Double)nums[i];
        regioncost[i]=regioncost[i-1]+(Double)psums[i]/(Double)nums[i];
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=k;j++)
        {
            if (j>i)
            continue;

            if (i==j)
            {
                FVal=(Double)i;
            }
            else if (j==1)
            {
                FVal=GetReg(1,i);
            }
            else
            {
                LN=Find(j-1,invsums[i]);

                FVal=LN.a*invsums[i]+LN.b+regioncost[i];
            }

            LN.a=(Double)(-psums[i]);
            LN.b=FVal-regioncost[i]+(Double)psums[i]*invsums[i];

            AddLine(j,LN);
        }
    }

    printf("%.8f\n",(double)FVal);

    return 0;
}