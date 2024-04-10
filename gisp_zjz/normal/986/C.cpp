#include<bits/stdc++.h>
#define maxn 203902

using namespace std;
bool f[1<<22],g[1<<22];
int n,m,ans,r,k;

void dfs(int x){
    if (f[x]) return;
    f[x]=true;
    if (g[x]) g[x]=false,dfs(r-x);
    for (int i=0;i<n;i++) dfs(x&(r-(1<<i)));
}

int main(){
    cin >> n >> m;
    r=(1<<n)-1;
    for (int i=0;i<m;i++){
        scanf("%d",&k);
        g[k]=true;
    }
    for (int i=0;i<=r;i++) if (g[i]) dfs(r-i),ans++;
    cout << ans << endl;
}