#include<iostream>
#include<cstdio>
using namespace std;
int n,q,k,a[100001],sum[100001],res[100001];
int main()
{
    scanf("%d%d%d",&n,&q,&k);
    for(register int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        sum[i]=a[i]-a[i-1]-1;
        sum[i-1]+=a[i]-a[i-1]-1;
    }
    res[0]=1;
    for(register int i=1;i<=n;++i)
        res[i]=res[i-1]+sum[i];
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(l==r)
            printf("%d\n",k-1);
        else
            printf("%d\n",res[r-1]-res[l]+(a[l+1]-2)+(k-a[r-1]-1));
    }
    return 0;
}