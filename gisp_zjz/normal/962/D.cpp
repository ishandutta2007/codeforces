#include<bits/stdc++.h>
#define maxn 500050

using namespace std;
typedef long long ll;
map<ll,ll>s;
ll f[maxn][50],a[maxn],b[maxn],c[maxn],n,k,r,ans[maxn];
bool g[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        while (a[i]%2==0) a[i]/=2,b[i]++;
        if (s.find(a[i])==s.end()) s[a[i]]=++r;
        c[i]=s[a[i]];
    }
    memset(g,true,sizeof(g)); k=n;
    for (int i=1;i<=n;i++)
    {
        while (f[c[i]][b[i]]) {
            g[f[c[i]][b[i]]]=false; k--;
            f[c[i]][b[i]]=0;
            b[i]++;
        }
        f[c[i]][b[i]]=i;
    }
    cout << k << endl;
    for (int i=1;i<=n;i++) if (g[i]) printf("%lld ",a[i]<<b[i]);
    printf("\n");
}