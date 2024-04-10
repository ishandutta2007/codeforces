#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int n,t,c,a[200005],f[200005][30];
int ans;


int main()
{
    scanf("%d%d%d",&n,&t,&c);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)f[i][0]=a[i];
    for(int i=1;i<=20;i++)
    {
        if((1<<i)>n)break;
        for(int j=1;j<=n-(1<<i)+1;j++)
        f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
    }
    int C,cnt;
    for(C=1,cnt=0;(C<<1)<c;C<<=1,cnt++);
    for(int i=1;i<=n-c+1;i++)
    {
        int Max=max(f[i][cnt],f[i+c-C][cnt]);
        if(Max<=t)ans++;
    }
    printf("%d\n",ans);
    return 0;
}