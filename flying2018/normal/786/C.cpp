#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
#define B 2000
using namespace std;
int a[N],g[N],n;
bool f[N];
int work(int x)
{
    for(int i=1;i<=n;i++) f[i]=g[i]=0;
    int t=1,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(g[a[i]]!=t) f[a[i]]=0,g[a[i]]=t;
        if(!f[a[i]]) ++cnt,f[a[i]]=1;
        if(cnt>x){++t;f[a[i]]=1,g[a[i]]=t;cnt=1;}
    }
    return t;
}
int p[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=min(B,n);i++) p[i]=work(i);
    for(int pre=p[B],l=B+1,r=n,res=B+1;l<=n;l=res+1,r=n)
    {
        res=n;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(work(mid)==pre) l=mid+1;
            else r=mid-1,res=mid;
        }
        pre=p[res]=work(res);
    }
    for(int i=1;i<=n;i++)
    if(!p[i]) p[i]=p[i-1];
    for(int i=1;i<=n;i++) printf("%d ",p[i]);
    return 0;
}