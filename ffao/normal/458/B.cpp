#define ll long long
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ll m,n,ma=-1,mb=-1,sa=0,sb=0,a[100005],b[100005],i,res=0,pa,pb;
    scanf("%I64d%I64d",&m,&n);
    for(i=0;i<m;i++)
    {
        scanf("%I64d",a+i);
        if(a[i]>ma)
            {
                ma=a[i];
                pa=i;
            }
        sa+=a[i];
    }
    for(i=0;i<n;i++)
    {
        scanf("%I64d",b+i);
        if(b[i]>mb)
            {
                mb=b[i];
                pb=i;
            }
        sb+=b[i];
    }
    if(ma>=mb)
    {
        res=sb;
        a[pa]=0;
        for(i=0;i<m;i++)
        {
            if(a[i]<sb)
                res+=a[i];
            else
                res+=sb;
        }
    }
    else
    {
        res=sa;
        b[pb]=0;
        for(i=0;i<n;i++)
        {
            if(b[i]<sa)
                res+=b[i];
            else
                res+=sa;
        }
    }
    cout<<res;
}