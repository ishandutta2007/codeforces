#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long a,b,n,ll,t,m,x[5000001],s[5000001];
inline int ef(int l,int r)
{
    if(l==r)
        if(l==ll-1)
            return -1;
        else
            return l;
    if(x[(l+r+1)/2]<=t && s[(l+r+1)/2]-s[ll-1]<=t*m)
        return ef((l+r+1)/2,r);
    else
        return ef(l,(l+r+1)/2-1);
}
int main()
{
    int i;
    cin>>a>>b>>n;
    x[1]=s[1]=a;
    for(i=2;i<=5000000;i++)
    {
        x[i]=x[i-1]+b;
        s[i]=s[i-1]+x[i];
    }
    while(n>0)
    {
        n--;
        scanf("%d%d%d",&ll,&t,&m);
        printf("%d\n",ef(ll-1,5000000));
    }
    return 0;
}