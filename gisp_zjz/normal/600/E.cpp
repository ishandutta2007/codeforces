#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int maxn=1e5+10;
vi G[maxn];
struct node{
    int l,r,mx;
    ll sum;
}t[maxn*50];
int n,color[maxn],tot;
void pushup(int x){
    int ls=t[x].l,rs=t[x].r;
    if (t[ls].mx>t[rs].mx){
        t[x].mx=t[ls].mx;
        t[x].sum=t[ls].sum;
    } else if (t[ls].mx<t[rs].mx){
        t[x].mx=t[rs].mx;
        t[x].sum=t[rs].sum;
    } else {
        t[x].mx=t[ls].mx;
        t[x].sum=t[ls].sum+t[rs].sum;
    }
}
void modify(int &x,int l,int r,int p){
    if (!x) x=++tot;
    if (l==r){
        t[x].mx++; t[x].sum=l;
        return;
    }
    int mid=(l+r)>>1;
    if (p<=mid) modify(t[x].l,l,mid,p);
    else modify(t[x].r,mid+1,r,p);
    pushup(x);
}
int merge(int a,int b,int l,int r){
    if (!a) return b;
    if (!b) return a;
    if (l==r){
        t[a].mx+=t[b].mx;
        t[a].sum=l;
        return a;
    }
    int mid=(l+r)>>1;
    t[a].l=merge(t[a].l,t[b].l,l,mid);
    t[a].r=merge(t[a].r,t[b].r,mid+1,r);
    pushup(a);
    return a;
}
void dfs(int u,int fa){
    for (auto v:G[u]){
        if (v==fa) continue;
        dfs(v,u);
        merge(u,v,1,n);
    }
    modify(u,1,n,color[u]);
}
int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> color[i];
    for (int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        G[u].pb(v); G[v].pb(u);
    }
    tot=n;
    dfs(1,0);
    for (int i=1;i<=n;i++) cout << t[i].sum << ' '; cout << endl;
    return 0;
}