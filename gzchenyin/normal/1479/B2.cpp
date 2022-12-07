#include<cstdio>
using namespace std;
int n,a[100005],ans,nxt[100005],lst[100005],f[2];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<=n;i++)
    {
        lst[a[i]]=n+1;
    }
    for(int i=n;i>=1;i--)
    {
        nxt[i]=lst[a[i]];
        lst[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        lst[a[i]]=nxt[lst[a[i]]];
        if(f[0]==a[i] || f[1]==a[i]) continue;
        ans++;
        if(lst[f[0]]>lst[f[1]]) f[0]=a[i];
        else f[1]=a[i];
    }
    printf("%d\n",ans);
}