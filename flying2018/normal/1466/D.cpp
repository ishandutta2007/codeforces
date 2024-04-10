#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200010
#define ll long long
using namespace std;
int w[N],deg[N];
ll wn[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;
        scanf("%d",&n);
        ll ans=0;
        for(int i=1;i<=n;i++) scanf("%d",&w[i]),ans+=w[i];
        for(int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            deg[x]++,deg[y]++;
        }
        int tot=0;
        for(int i=1;i<=n;i++)
            for(int j=2;j<=deg[i];j++) wn[++tot]=w[i];
        sort(wn+1,wn+tot+1,greater<ll>());
        for(int i=1;i<n;i++) printf("%lld ",ans),ans+=wn[i];
        puts("");
        for(int i=1;i<=n;i++) deg[i]=wn[i]=0;
    }
    return 0;
}