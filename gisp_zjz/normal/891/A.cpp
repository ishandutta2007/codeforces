#include<bits/stdc++.h>
#define maxn 2000

using namespace std;

int a[maxn][maxn],n,k;

int gcd(int x,int y)
{
    if (x%y==0) return y; else return gcd(y,x%y);
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[1][i]);
    k=0; for (int i=1;i<=n;i++) if (a[1][i]==1) k++;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;i+j-1<=n;j++) if (a[i][j]==1){printf("%d\n",max(i,2)+n-2-k); return 0;}
        for (int j=1;i+j<=n;j++){
            a[i+1][j]=gcd(a[i][j],a[i][j+1]);
        }
    }
    printf("-1\n");return 0;
}