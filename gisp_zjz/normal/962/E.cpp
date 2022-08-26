#include<bits/stdc++.h>
#define maxn 502030

using namespace std;
typedef long long ll;
ll a[maxn],n,p,q,r,x,y,ans,b[maxn],f,g,ff,gg,c[maxn];
char s[2];

int main()
{
    scanf("%d",&n); f=0; g=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%lld%s",&a[i],s);
        if (s[0]=='B') b[i]=1;
        else if (s[0]=='R') b[i]=-1;
        else b[i]=0;
    }
    r=0;
    for (int i=1;i<=n;i++) if (b[i]==0) c[++r]=i;
    if (r==0){
        for (int i=1;i<=n;i++)
        {
            if (b[i]==1){
                if (!p) p=i; q=i;
            }
            if (b[i]==-1){
                if (!x) x=i; y=i;
            }
        }
        cout << a[y]+a[q]-a[x]-a[p] << endl;
        return 0;
    }
    f=g=0;
    for (int i=1;i<c[1];i++)
    {
        if (b[i]==1){
            if (!f) f=1,ans+=a[c[1]]-a[i];
        }
        if (b[i]==-1){
            if (!g) g=1,ans+=a[c[1]]-a[i];
        }
    }
    f=g=0;
    for (int i=n;i>c[r];i--)
    {
        if (b[i]==1){
            if (!f) f=1,ans+=a[i]-a[c[r]];
        }
        if (b[i]==-1){
            if (!g) g=1,ans+=a[i]-a[c[r]];
        }
    }
    for (int i=1;i<r;i++)
    {
        x=c[i]; y=0;
        for (int j=c[i]+1;j<c[i+1];j++)
        {
            if (b[j]==1) y=max(y,a[j]-a[x]),x=j;
        }
        y=max(y,a[c[i+1]]-a[x]);
        x=c[i]; q=0;
        for (int j=c[i]+1;j<c[i+1];j++)
        {
            if (b[j]==-1) q=max(q,a[j]-a[x]),x=j;
        }
        q=max(q,a[c[i+1]]-a[x]);
        p=a[c[i+1]]-a[c[i]];
        ans+=min(p*2,p*3-y-q);
    }
    cout << ans << endl;
}