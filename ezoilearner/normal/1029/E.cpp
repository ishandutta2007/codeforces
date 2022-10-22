#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=200005;
int n,u,v,cnt,idx,ans,head[N],fa[N],dfn[N],pos[N],dep[N],to[N*2],nxt[N*2];
bool ck[N],st[N];

void adde(int u,int v){
    to[++cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
}

void dfs(int u){
    pos[++idx]=u;
    int v;
    for(int i=head[u];i;i=nxt[i]){
        v=to[i];
        if(v!=fa[u]){
            fa[v]=u;
            dep[v]=dep[u]+1;
            fa[v]=u;dfs(v);
        }
    }
}

int solve(){
    for(int i=1;i<=n;i++){
        if(dep[i]<=2){
            ck[i]=true;
        }
    }
    for(int i=n;i>=1;i--){
        int u=pos[i];
        if(!ck[u]){
            if(!st[fa[u]]){
                st[fa[u]]=true;
                ans++;
            }
            ck[u]=true;
            ck[fa[u]]=true;
            ck[fa[fa[u]]]=true;
        }
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);adde(u,v);adde(v,u);
    }
    dfs(1);
    printf("%d\n",solve());
}