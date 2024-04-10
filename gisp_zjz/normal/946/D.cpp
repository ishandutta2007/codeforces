#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=505;
const int inf=505*505*3;
char s[maxn];
int n,m,e,l,r,cnt,ans,a[maxn][maxn],dp[maxn*maxn],b[maxn][maxn],c[maxn],d[maxn];

int main()
{
    scanf("%d%d%d",&n,&m,&e);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s); l=0; r=-1;
        for (int j=1;j<=m;j++)
        {
            b[i][j]=b[i][j-1]+(s[j-1]-'0');
            if (l==0&&s[j-1]=='1') l=j;
            if (s[j-1]=='1') r=j;
        }
        c[i]=b[i][m];
        d[i]=r-l+1;
        ans+=d[i];
    }
    for (int i=1;i<=n;i++)
        for (int j=0;j<=m;j++)
            for (int k=j;k<=m;k++)
                a[i][c[i]-(b[i][k]-b[i][j])]=max(a[i][c[i]-(b[i][k]-b[i][j])],d[i]-(k-j));
    /*
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=c[i];j++) cout << a[i][j] << ' ';
        cout << endl;
    }
    */
    for (int i=1;i<=n;i++)
        for (int j=e;j>=1;j--)
            for (int k=0;k<=min(c[i],j);k++)
                dp[j]=max(dp[j],dp[j-k]+a[i][k]);
    cout << ans-dp[e] << endl;
}