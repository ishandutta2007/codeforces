#include<bits/stdc++.h>
#define maxn 150

using namespace std;
char s[maxn];
bool f[maxn][maxn];
int p,q,n,k,r,x,y,u,v,d;

int main()
{
    cin >> n >> k;
    for (int i=0;i<n;i++)
    {
        scanf("%s",s);
        for (int j=0;j<n;j++)
            f[i+1][j+1]=(s[j]=='.');
    }
    p=1; q=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (!f[i][j]) continue;
            x=i; y=i;
            while (f[x][j]) x--;
            while (f[y][j]) y++;
            x=max(i-k,x); y=min(i+k,y);
            u=j; v=j;
            while (f[i][u]) u--;
            while (f[i][v]) v++;
            u=max(j-k,u); v=min(j+k,v);
            d=max(0,y-x-k)+max(0,v-u-k);
            if (d>r) p=i,q=j,r=d;
        }
    cout << p << ' ' << q << endl;
}