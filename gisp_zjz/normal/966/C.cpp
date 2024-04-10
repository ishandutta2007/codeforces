#include<bits/stdc++.h>
#define maxn 6100700
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
ll a[maxn],p,n,k,ans[maxn],t,u,v,w,nm[maxn];
int pre[maxn],b[maxn][2],sz[maxn];
bool f;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        ans[0]^=a[i]; t=0;
        for (int j=60;j>=0;j--)
        {
            f=a[i]&(1ll<<j);
            if (!b[t][f]) b[t][f]=++p,pre[p]=t;
            t=b[t][f]; sz[t]++;
        }
        nm[t]=a[i];
    }
    for (int i=1;i<n;i++)
    {
        k=ans[i-1];
        if (k==0) {
            puts("No");return 0;
        }
        t=0; v=-1;
        for (int j=60;j>=0;j--)
        {
            f=k&(1ll<<j);
            if (!f) {
                t=b[t][0];
                if (!t) break;
            }
            else {
                u=b[t][1];
                if (sz[u]) v=u,w=j;
                t=b[t][0];
                if (!t) break;
            }
        }
        if (v==-1) {
            puts("No");return 0;
        }
        t=v;
        for (int j=w-1;j>=0;j--)
        {
            f=k&(1ll<<j);
            if (sz[b[t][f^1]]) t=b[t][f^1]; else t=b[t][f];
        }
        ans[i]=k^nm[t];
        while (t) sz[t]--,t=pre[t];
    }
    for (int i=1;i<=n;i++) a[i]=ans[n-i];
    //for (int i=1;i<=n;i++) cout << a[i] <<' ' ; cout << endl;
    printf("Yes\n"); cout << a[1];
    for (int i=1;i<n;i++) printf(" %lld",a[i]^a[i+1]);
    cout << endl;
    return 0;
}