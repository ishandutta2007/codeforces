#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7,P=1e9+7;

int n,a[N];

int vis[N],p[N],ptot,phi[N];

vector<int>v;

vector<int>g[N];

void pre(int n)
{
    vis[1]=1;
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
            p[++ptot]=i,phi[i]=i-1;
        for(int j=1;j<=ptot&&i*p[j]<=n;j++)
        {
            phi[i*p[j]]=phi[i]*(p[j]-1);
            vis[i*p[j]]=1;
            if(i%p[j]==0)
            {
                phi[i*p[j]]=phi[i]*p[j];
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            g[j].push_back(i);
}

int s[N];

int calc(vector<int>&v)
{
    int ret=0,dlt=0;
    for(auto x:v)
        for(auto v:g[x])
        {
            ret=(ret+1ll*s[v]*phi[v])%P;
            dlt=(dlt+phi[v])%P;
            s[v]++;
        }
    for(auto x:v)
        for(auto v:g[x])
            s[v]--;
    return (ret*2ll+dlt)%P;
}

int main()
{
    pre(1e5);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ans=0;
    for(int d=1;d<=n;d++)
    {
        v.clear();
        for(int i=1;i*d<=n;i++)
            v.push_back(a[i*d]);
        ans=(ans+1ll*phi[d]*calc(v))%P;
    }
    printf("%d\n",ans);
}