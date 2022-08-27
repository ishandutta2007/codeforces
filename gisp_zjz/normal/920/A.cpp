#include<bits/stdc++.h>
#define maxn 205

using namespace std;
int query,n,k,c;
bool f[maxn],g[maxn];

int main()
{
    scanf("%d",&query);
    while (query--)
    {
        scanf("%d%d",&n,&k);
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        for (int i=0;i<k;i++)
        {
            int u;scanf("%d",&u);
            f[u]=true;
        }
        c=k; int r=1;
        while (c<n)
        {
            r++;
            for (int i=1;i<=n;i++)
            if (!f[i]){
                if (f[i-1]||f[i+1]) g[i]=true,c++;
            }
            for (int i=1;i<=n;i++) f[i]|=g[i];
        }
        printf("%d\n",r);
    }
}