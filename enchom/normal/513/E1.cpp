#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define INV -999999999

int F[53][403][403];
int n,k;
int nums[403];
int presum[403];

int GetSum(int l,int r)
{
    return presum[r]-presum[l-1];
}

pair<int,int> SS[53][403][403];

int GetPoint(int m,int val)
{
    int l,r,mid,best=-1;

    l=1;
    r=m;

    while(l<=r)
    {
        mid=(l+r)/2;

        if (val>SS[1][m][mid].first)
        {
            best=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }

    return best;
}

int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int MaxRemove[53][403][403];
int MaxAdd[53][403][403];

int main()
{
    int i,j,in,ja;
    int p;
    int v1,v2;
    int ans=INV;

    scanf("%d %d",&n,&k);

    presum[0]=0;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&nums[i]);
        presum[i]=presum[i-1]+nums[i];
    }

    for (i=0;i<=52;i++)
    {
        for (j=0;j<=402;j++)
        {
            for (in=0;in<=402;in++)
            {
                F[i][j][in]=INV;
                MaxAdd[i][j][in]=INV;
                MaxRemove[i][j][in]=INV;
            }
        }
    }

    for (i=1;i<=k;i++)
    {
        for (j=1;j<=n;j++)
        {
            for (in=j;in>=1;in--)
            {
                ///Computing F[i][j][in] , interval in~j at move k

                ///Find F[i-1][in-1][?]

                if (i>1)
                {
                    p=GetPoint(in-1,GetSum(in,j));

                    if (p!=-1)
                    {
                        if (MaxRemove[i-1][in-1][p]!=INV)
                        v1=MaxRemove[i-1][in-1][p]+GetSum(in,j);
                        else
                        v1=INV;
                    }
                    else
                    v1=INV;

                    if (SS[1][in-1][1].first>=GetSum(in,j))
                    {
                        if (p!=-1)
                        {
                            if (MaxAdd[i-1][in-1][p-1]!=INV)
                            v2=MaxAdd[i-1][in-1][p-1]-GetSum(in,j);
                            else
                            v2=INV;
                        }
                        else
                        {
                            if (MaxAdd[i-1][in-1][in-1]!=INV)
                            v2=MaxAdd[i-1][in-1][in-1]-GetSum(in,j);
                            else
                            v2=INV;
                        }
                    }
                    else
                    v2=INV;

                    F[i][j][in]=MAX(v1,v2);
                }
                else
                {
                    F[1][j][in]=0;
                }

                if (i==k)
                ans=MAX(ans,F[i][j][in]);
            }

            for (in=1;in<=j;in++)
            {
                SS[i][j][in]=make_pair(GetSum(in,j),in);
            }

            sort(SS[i][j]+1,SS[i][j]+1+j);
            reverse(SS[i][j]+1,SS[i][j]+1+j);

            if (F[i][j][ SS[i][j][1].second ]!=INV)
            MaxAdd[i][j][1]=F[i][j][ SS[i][j][1].second ]+SS[i][j][1].first;
            else
            MaxAdd[i][j][1]=INV;

            for (in=2;in<=j;in++)
            {
                if (F[i][j][ SS[i][j][in].second ]!=INV)
                MaxAdd[i][j][in]=MAX( MaxAdd[i][j][in-1] , F[i][j][ SS[i][j][in].second ]+SS[i][j][in].first );
                else
                MaxAdd[i][j][in]=MaxAdd[i][j][in-1];
            }

            if (F[i][j][ SS[i][j][j].second ]!=INV)
            MaxRemove[i][j][j]=F[i][j][ SS[i][j][j].second ]-SS[i][j][j].first;
            else
            MaxRemove[i][j][j]=INV;

            for (in=j-1;in>=1;in--)
            {
                if (F[i][j][ SS[i][j][in].second ]!=INV)
                MaxRemove[i][j][in]=MAX( MaxRemove[i][j][in+1] , F[i][j][ SS[i][j][in].second ]-SS[i][j][in].first );
                else
                MaxRemove[i][j][in]=MaxRemove[i][j][in+1];
            }
        }
    }

    printf("%d\n",ans);

    return 0;
}