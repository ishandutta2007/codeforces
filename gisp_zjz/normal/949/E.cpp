#include<bits/stdc++.h>
#define maxn 1048576

using namespace std;
int n,k,ans[50],a[maxn],c[50],m,r;
bool f[maxn][20];

void update(int x)
{
    if (x>=k) return;
    k=x; for (int i=0;i<x;i++) ans[i]=c[i];
}

void dfs(int x,int y,int z)
{
    if (z==2){
        if (f[0][x]) c[y++]=(1<<x);
        if (f[2][x]) c[y++]=-(1<<x);
        update(y);
        return ;
    }
    bool g=false;
    for (int i=0;i<=z;i++)
        if ((i&1)&&f[i][x]) g=true;
    if (!g){
        for (int i=0;i<=z/2;i++) f[i][x+1]=false;
        for (int i=0;i<=z;i+=2) if (f[i][x]) f[i/2][x+1]=true;
        dfs(x+1,y,z/2);
    }
    else{
        for (int i=0;i<=z/2;i++) f[i][x+1]=false;
        for (int i=0;i<=z;i++) if (f[i][x]) f[i/2][x+1]=true;
        c[y]=(1<<x); dfs(x+1,y+1,z/2);
        for (int i=0;i<=z/2;i++) f[i][x+1]=false;
        for (int i=0;i<=z;i++) if (f[i][x]) f[(i+1)/2][x+1]=true;
        c[y]=-(1<<x); dfs(x+1,y+1,z/2);
    }
}

int main()
{
    scanf("%d",&n); k=20; m=19; r=(1<<m);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) f[a[i]+r/2][0]=true;
    dfs(0,0,r);
    cout << k << endl;
    for (int i=0;i<k;i++) cout << ans[i] << ' ';
    cout << endl;
}