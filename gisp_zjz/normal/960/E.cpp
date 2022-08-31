#include<bits/stdc++.h>
#define maxn 340000

using namespace std;
typedef long long ll;
const ll M=1e9+7;
vector <ll> h[maxn];
ll a[maxn][2],n,b[maxn],ans,p[2];

void dfs(int u,int fa,int f)
{
    for (int i=0;i<h[u].size();i++)
    {
        int v=h[u][i];
        if (v!=fa) dfs(v,u,f^1),a[u][0]+=a[v][0],a[u][1]+=a[v][1];
    }
    a[u][f]++;
}

void dfs2(int u,int fa,int f)
{
    ll o1=p[f],o2=p[f^1]+1,t=(p[f]*2+1+o1*o1-o2*o2)%M;
    for (int i=0;i<h[u].size();i++)
    {
        int v=h[u][i];
        if (v!=fa) dfs2(v,u,f^1),t=(t-a[v][f]*a[v][f]+a[v][f^1]*a[v][f^1])%M,o1-=a[v][f],o2-=a[v][f^1];
    }
    t=(t-o1*o1+o2*o2)%M;(ans+=t*b[u])%=M;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lld",&b[i]);
    for (int i=1;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        h[u].push_back(v);
        h[v].push_back(u);
    }
    dfs(1,0,0); p[0]=a[1][0]-1,p[1]=a[1][1]-1;
    dfs2(1,0,0);
    cout << (ans+M)%M << endl;
}