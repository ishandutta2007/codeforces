#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int fa[N],dep[N],w[N],dp[N],x[N],y[N],z[N],A[N];
vector<int>S[N];
int get(int x) {
    return x==fa[x]?x:fa[x]=get(fa[x]);
}
void dfs(int x) {
    dep[x]=dep[fa[x]]+1;
    for(int y:S[x]) {
        if(fa[x]==y)continue;
        fa[y]=x;
        dfs(y);
    }
}
void DP(int x) {
    int W=w[x]&1;
    dp[x]=W;
    for(int y:S[x]) {
        if(y==fa[x])continue;
        DP(y);
        W+=w[y]&1;
        dp[x]+=dp[y];
    }
    dp[x]-=W/2;
}
int main() {
    int n,m,a,b,q;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++) {
        scanf("%d%d",&a,&b);
        if(get(a)==get(b))continue;
        S[a].push_back(b);
        S[b].push_back(a);
        fa[fa[a]]=fa[b];
    }
    fa[1]=0;
    dfs(1);
    scanf("%d",&q);
    for(int i=1;i<=q;i++) {
        scanf("%d%d",x+i,y+i);
        a=x[i],b=y[i];
        if(dep[a]<dep[b])swap(a,b);
        while(dep[a]>dep[b])w[a]++,a=fa[a];
        while(a!=b) {
            w[a]++,w[b]++;
            a=fa[a],b=fa[b];
        }
        z[i]=a;
    }
    int FL=0;
    for(int i=2;i<=n;i++)
        if(w[i]%2)FL++;
    if(!FL) {
        puts("YES");
        for(int i=1;i<=q;i++) {
            a=x[i],b=y[i];
            printf("%d\n",dep[a]+dep[b]-2*dep[z[i]]+1);
            while(a!=z[i]) {
                printf("%d ",a);
                a=fa[a];
            }
            printf("%d ",z[i]);
            int top=0;
            while(b!=z[i]) {
                A[++top]=b;
                b=fa[b];
            }
            while(top) {
                printf("%d ",A[top--]);
            }
            puts("");
        }
    } else {
        puts("NO");
        DP(1);
        printf("%d\n",dp[1]);
    }
    return 0;
}