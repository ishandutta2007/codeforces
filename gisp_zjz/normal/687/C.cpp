#include<bits/stdc++.h>
#define maxn 505

using namespace std;
bool f[maxn][maxn];
int a[maxn],n,m,ans;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    f[0][0]=1;
    for (int i=0;i<n;i++)
    {
        for (int j=m;j>=a[i];j--)
        {
            for (int k=0;k<=j;k++) f[j][k]|=f[j-a[i]][k];
            for (int k=j;k>=a[i];k--) f[j][k]|=f[j-a[i]][k-a[i]];
        }
    }
    ans=0;
    for (int i=0;i<=m;i++) if (f[m][i]) ans++;
    printf("%d\n",ans);
    for (int i=0;i<=m;i++) if (f[m][i]) printf("%d ",i); printf("\n");
}