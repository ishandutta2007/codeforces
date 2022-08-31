#include<bits/stdc++.h>
#define maxn 2005

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

char s[maxn][maxn];
bool f[maxn][maxn];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%s",s[i]);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            f[i][j]=(s[i][j]=='#');
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            if (!f[i][j]) continue;
            for (int x=0;x<n;x++)
                for (int y=0;y<m;y++)
                {
                    if (x==i||y==j) continue;
                    if (f[x][j]&&f[i][y]&&!f[x][y]) {puts("No");return 0;}
                }
        }
    puts("Yes");
}