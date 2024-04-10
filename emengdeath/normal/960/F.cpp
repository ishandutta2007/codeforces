#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
struct node{
    int son[2];
    int mx;
}f[N*30];
int n,m,ans,L;
int g[N];
void ins(int l,int r,int s,int ll,int v){
    f[s].mx=max(f[s].mx,v);
    if (l==r)return;
    if ((l+r)/2>=ll){
        if (!f[s].son[0])f[s].son[0]=++L;
        ins(l,(l+r)/2,f[s].son[0],ll,v);
    }else{
        if (!f[s].son[1])f[s].son[1]=++L;
        ins((l+r)/2+1,r,f[s].son[1],ll,v);
    }
}
int get(int l,int r,int s,int ll){
    if (l>ll||!s)return 0;
    if (r<=ll)return f[s].mx;
    return max(get(l,(l+r)/2,f[s].son[0],ll),get((l+r)/2+1,r,f[s].son[1],ll));
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    L=n;
    for (int i=1;i<=m;i++){
        int x,y,z,u;
        cin>>x>>y>>z;
        u=get(0,100000,x,z-1);
        ans=max(ans,++u);
        ins(0,100000,y,z,u);
    }
    cout<<ans;
    return 0;
}