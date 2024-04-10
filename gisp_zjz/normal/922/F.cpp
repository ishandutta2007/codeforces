#include<bits/stdc++.h>
#define maxn 300030

using namespace std;

int a[maxn],n,k,s,j,ans;
bool f[maxn];

int main()
{
    for (int i=1;i<maxn;i++)
        for (int j=2;i*j<maxn;j++)
            a[i*j]++;
    scanf("%d%d",&n,&k);
    s=0;
    for (j=1;j<=n;j++)
    {
        s+=a[j];
        if (s>=k) break;
    }
    if (s<k) {puts("No"); return 0;}
    puts("Yes");
    memset(f,true,sizeof(f));
    for (int i=2;i<=j;i++)
        if (a[i]==1&&j/i<=s-k) f[i]=false,s-=j/i;
    ans=0;
    for (int i=1;i<=j;i++) ans+=f[i];
    printf("%d\n",ans);
    for (int i=1;i<=j;i++) if (f[i]) printf("%d ",i);
    printf("\n");
    return 0;
}