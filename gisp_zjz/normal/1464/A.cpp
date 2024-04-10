#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
const int maxn=1e5+100;
int _,p[maxn],n,m;
bool vis[maxn];
int ffind(int x){
    if (p[x]==x) return x;
    return p[x]=ffind(p[x]);
}
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) p[i]=i;
        int ans=0;
        for (int i=1;i<=m;i++){
            int x,y;scanf("%d%d",&x,&y);
            if (x==y) continue;
            x=ffind(x); y=ffind(y);
            if (x==y) ans+=2; else ans++,p[y]=x;
        }
        printf("%d\n",ans);
    }
    return 0;
}