#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int a[N];
int l[N],r[N],u[N];//leftdown, rightdown
int lf[N],rf[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int tt=0;
    u[0]=1;
    for(int i=1,j=1;i<=n;i=j)
    {
        ++tt;
        for(j++;j<=n && a[j]>=a[j-1];j++);
        j--;
        u[tt]=j;
        for(j++;j<=n && a[j]<=a[j-1];j++);
        l[tt]=u[tt]-(u[tt-1]+r[tt-1]);
        r[tt]=j-u[tt]-1;
    }
    // for(int i=1;i<=tt;i++) printf("%d %d %d\n",l[i],u[i],r[i]);
    for(int i=1;i<=tt;i++) lf[i]=max(lf[i-1],max(l[i],r[i]));
    for(int i=tt;i;i--) rf[i]=max(rf[i+1],max(l[i],r[i]));
    int ans=0;
    for(int i=1;i<=tt;i++)
    {
        if(l[i]!=r[i] || l[i]%2) continue;
        if(max(l[i],r[i])>max(lf[i-1],rf[i+1])) ++ans;
    }
    printf("%d\n",ans);
    return 0;
}