#include<bits/stdc++.h>
#define maxn 505050

using namespace std;
int n,m,k,pre[maxn],d[maxn],dep[maxn],mx;
vector <int> h[maxn],g[maxn];

void dfs(int u,int fa){
    for (int i=0;i<h[u].size();i++){
        int v=h[u][i];
        if (v==fa) continue;
        if (!dep[v]) d[u]++,pre[v]=u,dep[v]=dep[u]+1,dfs(v,u);
        else if (dep[u]>dep[v]) g[u].push_back(v);
    }
    mx=max(mx,dep[u]);
}

void go(int u,int v){
    while (u!=v){
        printf("%d ",u);
        u=pre[u];
    }
    printf("%d\n",v);
}

void work(int x){
    //cout<<d[x]<<endl;
    assert(g[x].size()>=2);
    int y=g[x][0],z=g[x][1];
    if (dep[y]<dep[z]) swap(y,z);
    //cout<<dep[x]<<' '<<dep[y]<<' '<<dep[z]<<endl;system("pause");
    if ((dep[x]-dep[y]+1)%3) {
        printf("%d\n",dep[x]-dep[y]+1);
        go(x,y);
    }
    else if ((dep[x]-dep[z]+1)%3) {
        printf("%d\n",dep[x]-dep[z]+1);
        go(x,z);
    }
    else {
        printf("%d\n",dep[y]-dep[z]+2);
        printf("%d ",x); go(y,z);
    }
}

int main(){
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        h[u].push_back(v);
        h[v].push_back(u);
    }
    dep[1]=1;  mx=1; dfs(1,0);
    if (1ll*mx*k>=1ll*n){
        puts("PATH"); printf("%d\n",mx);
        int pos=1; for (int i=2;i<=n;i++) if (dep[i]==mx) pos=i;
        for (int i=1;i<=mx;i++){
            printf("%d ",pos);
            pos=pre[pos];
        }
        puts("");
        return 0;
    }
    puts("CYCLES");
    for (int i=1;i<=n;i++) if (!d[i]){
        work(i);
        k--; if (!k) break;
    }
    assert(k==0);
    return 0;
}