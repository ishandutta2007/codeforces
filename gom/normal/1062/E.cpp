#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,q,p[N][25],sp[N][25],h[N],tree[4*N];
vector<int> c[N];
void dfs(int x)
{
    for(auto &it : c[x]){
        h[it]=h[x]+1;
        dfs(it);
    }
}
void update(int nd,int l,int r,int x)
{
    if(l==r){
        tree[nd]=x;
        return;
    }
    int m=(l+r)/2;
    if(x<=m) update(nd*2,l,m,x);
    else update(nd*2+1,m+1,r,x);
    if(!tree[nd*2]) tree[nd]=tree[nd*2+1];
    else if(!tree[nd*2+1]) tree[nd]=tree[nd*2];
    else{
        if(h[tree[nd*2]]<h[tree[nd*2+1]]) tree[nd]=tree[nd*2];
        else tree[nd]=tree[nd*2+1];
    }
}
int query(int nd,int l,int r,int s,int e)
{
    if(r<s||e<l||e<s) return 0;
    if(s<=l&&r<=e) return tree[nd];
    int m=(l+r)/2;
    int v1=query(nd*2,l,m,s,e);
    int v2=query(nd*2+1,m+1,r,s,e);
    if(!v1) return v2;
    else if(!v2) return v1;
    else{
        if(h[v1]>h[v2]) return v2;
        else return v1;
    }
}
int lca1(int u,int v)
{
    if(!u) return v;
    if(!v) return u;
    int d=h[u]-h[v];
    if(d<0){ swap(u,v); d=-d; }
    for(int bit=0;bit<=18;bit++)
        if(d&(1<<bit)) u=p[u][bit];
    if(u==v) return u;
    for(int bit=18;bit>=0;bit--){
        if(p[u][bit]&&p[v][bit]&&p[u][bit]!=p[v][bit]){
            u=p[u][bit];
            v=p[v][bit];
        }
    }
    return p[u][0];
}
int lca2(int l,int r)
{
    if(l>r) return 0;
    int d=r-l+1,x=0;
    while(1<<(x+1)<=d) x++;
    return lca1(sp[l][x],sp[r-(1<<x)+1][x]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        cin>>p[i][0];
        c[p[i][0]].push_back(i);
    }
    h[1]=1;
    dfs(1);
    for(int i=1;i<=n;i++) update(1,1,n,i);
    for(int bit=1;bit<=18;bit++){
        for(int i=1;i<=n;i++){
            p[i][bit]=p[p[i][bit-1]][bit-1];
        }
    }
    for(int i=1;i<=n;i++) sp[i][0]=i;
    for(int bit=1;bit<=18;bit++){
        for(int i=1;i<=n;i++){
            sp[i][bit]=lca1(sp[i][bit-1],sp[i+(1<<(bit-1))][bit-1]);
        }
    }
    for(int tc=1;tc<=q;tc++){
        int l,r;
        cin>>l>>r;
        int L=l,R=r,x=R,y=L,v=lca2(l,r);
        while(L<=R){
            int M=(L+R)/2;
            if(lca2(l,M)==v){
                R=M-1;
                x=min(x,M);
            }
            else{
                L=M+1;
            }
        }
        L=l;R=r;
        while(L<=R){
            int M=(L+R)/2;
            if(lca2(M,r)==v){
                L=M+1;
                y=max(y,M);
            }
            else{
                R=M-1;
            }
        }
        y=x-1;
        if(y<l) y=l;
        int r1=lca1(lca2(l,x-1),lca2(x+1,r)),r2=lca1(lca2(l,y-1),lca2(y+1,r)),res;
        if(h[r1]<=h[r2]) cout<<y<<" "<<h[r2]-1<<"\n";
        else cout<<x<<" "<<h[r1]-1<<"\n";
    }
    return 0;
}