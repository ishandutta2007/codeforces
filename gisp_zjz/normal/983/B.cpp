#include<bits/stdc++.h>
#define maxn 5001
#define F first
#define S second

using namespace std;
typedef long long ll;
int a[maxn][maxn],n,b[maxn],m,c[maxn][maxn],d[maxn][maxn];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    for (int i=1;i<=n;i++){
        for (int j=0;j+i<=n;j++) a[i][j]=b[i+j];
        for (int j=0;(1<<j)<=n-i;j++)
            for (int k=0;k+i<=n;k++)
                if (k&(1<<j)) a[i][k]^=a[i][k^(1<<j)];
    }
    for (int i=1;i<=n;i++)
    {
        c[i][i]=a[i][0];
        for (int j=i+1;j<=n;j++) c[i][j]=max(c[i][j-1],a[i][j-i]);
    }
    for (int j=n;j;j--)
        for (int i=j;i;i--)
            d[i][j]=max(d[i+1][j],c[i][j]);
    scanf("%d",&m);
    while (m--){
        int l,r;scanf("%d%d",&l,&r);
        printf("%d\n",d[l][r]);
    }
    return 0;
}