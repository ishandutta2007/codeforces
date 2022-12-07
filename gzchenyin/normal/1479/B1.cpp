#include<cstdio>
using namespace std;
int n,a[100005],ans,Now,nxt[100005],f[2];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=n;i>=1;i--)
    {
        if(a[i]==a[i-1]) Now=a[i];
        nxt[i]=Now;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i+1] || a[i]==a[i-1])
        {
            if(f[0]!=a[i]) ans++;
            if(f[1]!=a[i]) ans++;
            f[0]=a[i];
            f[1]=a[i];
            continue;
        }
        if(f[0]==a[i] && f[1]!=a[i])
        {
            ans++;
            f[1]=a[i];
            continue;
        }
        if(f[0]!=a[i] && f[1]==a[i])
        {
            ans++;
            f[0]=a[i];
            continue;
        }
        if(f[0]==nxt[i]) 
        {
            ans++;
            f[0]=a[i];
        }
        else
        {
            ans++;
            f[1]=a[i];
        }
    }
    printf("%d\n",ans);
}