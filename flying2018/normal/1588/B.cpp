#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 100010
#define ll long long
using namespace std;
ll qry(int l,int r)
{
    printf("? %d %d\n",l,r);
    fflush(stdout);ll res=0;
    scanf("%lld",&res);
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;scanf("%d",&n);
        ll all=qry(1,n);
        int l=1,r=n;ll res=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(qry(1,mid)==all) r=mid-1,res=mid;
            else l=mid+1;
        }
        ll pr=all-qry(1,res-1)+1;
        all-=pr*(pr-1)/2;res-=pr;
        ll pl=all-qry(1,res-1)+1;res=res-pl+1;
        printf("! %lld %lld %lld\n",res,res+pl,res+pl+pr-1);
        fflush(stdout);
    }
    return 0;
}