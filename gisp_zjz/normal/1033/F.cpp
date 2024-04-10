#include<bits/stdc++.h>
using namespace std;
int ans,cnt[4096],f[555555],g[555555],p[13],n,m,k,w,r,d[12];
int c[6][2]={{2,0},{-1,1},{0,-1},{1,2},{0,1},{1,0}};
char s[12];

void dfs(int p,int o,int msk){
    if (p==w) {ans+=cnt[msk]*f[o];return;}
    int x=c[d[p]][0],y=c[d[p]][1];
    if (x!=-1) dfs(p+1,o*3+x,msk*2);
    if (y!=-1) dfs(p+1,o*3+y,msk*2+1);
}

int main(){
    cin >> w >> n >> m;
    p[0]=1; for (int i=1;i<=w;i++) p[i]=p[i-1]*3;
    for (int i=0;i<n;i++){
        cin >> k; r=0;
        for (int j=0;j<w;j++) if (k&(1<<j)) r+=p[j];
        f[r]++; cnt[k]++;
    }
    for (int i=1;i<p[w];i++){
        if (i%3==2) g[i]=1; else g[i]=g[i/3]*3;
        if (g[i]) f[i]=f[i-g[i]]+f[i-g[i]*2];
    }
    while (m--){
        scanf("%s",s); ans=0;
        for (int i=0;i<w;i++) {
            if (s[i]=='A') d[i]=0;
            else if (s[i]=='a') d[i]=1;
            else if (s[i]=='O') d[i]=2;
            else if (s[i]=='o') d[i]=3;
            else if (s[i]=='X') d[i]=4;
            else d[i]=5;
        }
        dfs(0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}