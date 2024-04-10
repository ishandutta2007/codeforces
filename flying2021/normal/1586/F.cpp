#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1010
using namespace std;
int n,k;
int mp[N][N];
void link(int l,int r,int L,int R,int c)
{
    // printf("link %d %d %d %d\n",l,r,L,R);
    for(int i=l;i<=r;i++)
        for(int j=L;j<=R;j++) mp[i][j]=c;
}
int mx=0;
void solve(int l,int r,int d)
{
    if(l==r) return;
    mx=max(mx,d);
    int m=(r-l+k)/k;
    for(int i=l;i<=r;i+=m)
        for(int j=i+m;j<=r;j+=m)
            link(i,i+m-1,j,min(r,j+m-1),d);
    for(int i=l;i<=r;i+=m) solve(i,min(i+m-1,r),d+1);
}
int main()
{
    int t=1;
    while(t --> 0)
    {
        scanf("%d%d",&n,&k);
        solve(1,n,1);
        printf("%d\n",mx);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++) printf("%d ",mp[i][j]);
    }
    return 0;
}