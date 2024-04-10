#include<bits/stdc++.h>
#define maxn 1000005

using namespace std;
typedef long long ll;
ll n,t,a[maxn],ans,c[maxn],k;
bool f[maxn];

void dfs(int x)
{
    f[x]=false; t++;
    if (f[a[x]]) dfs(a[x]);
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    memset(f,true,sizeof(f));
    ans=0;k=0;
    for (int i=1;i<=n;i++) if (f[i]) {t=0;dfs(i);c[k++]=t;}
    sort(c,c+k);
    if (k>1)
    {
        k--;c[k-1]+=c[k];
    }
    for (int i=0;i<k;i++) ans+=c[i]*c[i];
    printf("%I64d\n",ans);
    return 0;
}