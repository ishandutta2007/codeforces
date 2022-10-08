#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

int n;
int nums[200111];
Int sums[200111];

Int Sum(int l,int r)
{
    if (l>r)
    return 0;

    return sums[r]-sums[l-1];
}

int main()
{
    int i;
    int l,r,mid,best;
    pair<Int,Int> cur,prev;
    pair<Int,Int> BestAns=make_pair(0,1);
    bool onecenter=true;
    int center=1,dist=0;

    scanf("%d",&n);

    sums[0]=0;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&nums[i]);
    }

    sort(nums+1,nums+1+n);

    for (i=1;i<=n;i++)
    {
        sums[i]=sums[i-1]+(Int)nums[i];
    }

    for (i=1;i<=n;i++) ///Fix middle
    {
        best=0;

        l=1;
        r=n;

        while(l<=r)
        {
            mid=(l+r)/2;

            if (i-mid<1 || n-mid+1<=i)
            {
                r=mid-1;
                continue;
            }

            cur.first=(Int)nums[i]+Sum(i-mid,i-1)+Sum(n-mid+1,n);
            cur.second=2LL*mid+1LL;

            prev.first=(Int)nums[i]+Sum(i-mid+1,i-1)+Sum(n-mid+2,n);
            prev.second=2LL*mid-1LL;

            if (cur.first*prev.second>prev.first*cur.second)
            {
                best=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }

        cur.first=(Int)nums[i]+Sum(i-best,i-1)+Sum(n-best+1,n);
        cur.second=2LL*best+1LL;

        cur.first-=cur.second*(Int)nums[i];
        if (cur.first<0)
        continue;

        if (cur.first*BestAns.second>BestAns.first*cur.second)
        {
            BestAns=cur;
            onecenter=true;
            center=i;
            dist=best;
        }
    }

    ///

    for (i=1;i<n;i++) ///Fix middle two
    {
        best=0;

        l=1;
        r=n;

        while(l<=r)
        {
            mid=(l+r)/2;

            if (i-mid<1 || n-mid+1<=i+1)
            {
                r=mid-1;
                continue;
            }

            cur.first=(Int)nums[i]+(Int)nums[i+1]+Sum(i-mid,i-1)+Sum(n-mid+1,n);
            cur.second=2LL*mid+2LL;

            prev.first=(Int)nums[i]+(Int)nums[i+1]+Sum(i-mid+1,i-1)+Sum(n-mid+2,n);
            prev.second=2LL*mid;

            if (cur.first*prev.second>prev.first*cur.second)
            {
                best=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }

        cur.first=(Int)nums[i]+(Int)nums[i+1]+Sum(i-best,i-1)+Sum(n-best+1,n);
        cur.second=2LL*best+2LL;

        cur.first-=(cur.second/2)*( (Int)nums[i+1]+(Int)nums[i] );
        if (cur.first<0)
        continue;

        //cout<<"Getting "<<cur.first<<"/"<<cur.second<<endl;
       // cout<<"Champion "<<BestAns.first<<"/"<<BestAns.second<<endl;

        if (cur.first*BestAns.second>BestAns.first*cur.second)
        {
            BestAns=cur;
            onecenter=false;
            center=i;
            dist=best;
        }
    }

    ///

    if (onecenter)
    {
        printf("%d\n",dist*2+1);

        for (i=center-dist;i<=center;i++)
        {
            if (i!=center-dist)
            printf(" ");

            printf("%d",nums[i]);
        }

        for (i=n-dist+1;i<=n;i++)
        {
            printf(" %d",nums[i]);
        }
        printf("\n");
    }
    else
    {
        printf("%d\n",dist*2+2);

        for (i=center-dist;i<=center+1;i++)
        {
            if (i!=center-dist)
            printf(" ");

            printf("%d",nums[i]);
        }

        for (i=n-dist+1;i<=n;i++)
        {
            printf(" %d",nums[i]);
        }
        printf("\n");
    }

    return 0;
}