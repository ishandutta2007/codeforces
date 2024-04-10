#include<bits/stdc++.h>
#define maxn 7001
#define x first
#define y second

using namespace std;
typedef pair<int,int> pi;
int a[maxn][2],cnt[maxn][2],p[2],n,b[maxn][2],r,o;
queue <pi> h;
bool f[maxn][2];

int main()
{
    scanf("%d",&n);
    scanf("%d",&p[0]); for (int i=0;i<p[0];i++) scanf("%d",&b[i][0]);
    scanf("%d",&p[1]); for (int i=0;i<p[1];i++) scanf("%d",&b[i][1]);
    for (int i=1;i<n;i++) cnt[i][0]=p[0],cnt[i][1]=p[1];
    a[0][0]=1; a[0][1]=1;
    h.push({0,0}); h.push({0,1});
    while (!h.empty())
    {
        pi tmp=h.front(); h.pop(); r=tmp.y^1;
        f[tmp.x][tmp.y]=true;
        for (int j=0;j<p[r];j++)
        {
            o=(tmp.x-b[j][r]+n)%n;
            if (a[tmp.x][tmp.y]==1) {if (!f[o][r]) a[o][r]=-1,h.push({o,r});}
            else {cnt[o][r]--; if (!cnt[o][r]&&!f[o][r]) a[o][r]=1,h.push({o,r});}
        }
    }
    for (int i=1;i<n;i++) if (a[i][0]==1) printf("Lose "); else if (a[i][0]==0) printf("Loop "); else printf("Win ");
    printf("\n");
    for (int i=1;i<n;i++) if (a[i][1]==1) printf("Lose "); else if (a[i][1]==0) printf("Loop "); else printf("Win ");
    printf("\n");
}