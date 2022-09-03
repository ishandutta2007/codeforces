/*#include<utility>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iostream>
#include<string.h>*/
#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
struct node{
    node *l,*r;
    int Min;
    int a,b;
    node(int _a,int _b){
        l=r=NULL;
        Min=0;
        a=_a;
        b=_b;
    }
}*root;
multiset<int> s[500005];
void pull(node *n){
    n->Min=min(n->l->Min,n->r->Min);
}
void build(node *n){
    if(n->a==n->b){
        n->Min=*s[n->a].begin();
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
    pull(n);
}
void rm(node *n,int k,int x){
    if(n->a==n->b){
        assert(s[k].find(x)!=s[k].end());
        s[k].erase(s[k].find(x));
        n->Min=*s[k].begin();
        return ;
    }
    int mid=(n->a+n->b)/2;
    if(k<=mid)rm(n->l,k,x);
    else rm(n->r,k,x);
    pull(n);
}
int query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return n->Min;
    }
    if(n->b<l||n->a>r){
        return 1e9+1;
    }
    return min(query(n->l,l,r),query(n->r,l,r));
}
vector<int> v[500005];
int f[500005];
int Find(int a){
    if(f[a]==a)return a;
    return f[a]=Find(f[a]);
}
int in[500005];
int out[500005];
int p[500005][20];
int dis[500005];
int ti;
vector<int> seq;
vector<pii > rmv[500005];
void dfs(int x,int f,int d=0){
    dis[x]=d;
    in[x]=++ti;
    p[x][0]=f;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x,d+1);
        }
    }
    seq.pb(x);
    out[x]=ti;
}
int lca(int a,int b){
    if(dis[a]>dis[b]){
        swap(a,b);
    }
    //if(a==b)return a'
    for(int i=19;i>=0;i--){
        if(dis[p[b][i]]>=dis[a])
        b=p[b][i];
    }
    //printf("!\n");
  //  printf("%d %d\n",a,b);
    if(a==b)return a;
    for(int i=19;i>=0;i--){
        if(p[a][i]!=p[b][i])
        {
            a=p[a][i];
            b=p[b][i];
        }
    }
    return p[a][0];
}
int main(){
    ti=-1;
    int n,q,m;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=0;i<=n;i++){
        f[i]=i;
    }
    vector<pii> edge;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
        int fa=Find(a),fb=Find(b);
        f[fb]=fa;
        edge.pb(mp(a,b));
    }
    for(int i=1;i<=n;i++){
        s[i].insert(1e9+1);
    }
    vector<pair<int,pii> >vv;
    vector<pair<int,pii> > add;
    for(int i=0;i<q;i++){
        int l,r,x;
        scanf("%d %d %d",&l,&r,&x);
        vv.pb(mp(x,mp(l,r)));
    }
    sort(vv.begin(),vv.end());
    for(auto it:vv){
        int l=it.y.x,r=it.y.y;
        int x=it.x;
        int lf=Find(l),rf=Find(r);
        if(lf==rf){
            add.pb(it);
        }
        else{
            f[lf]=rf;
            v[l].pb(r);
            v[r].pb(l);
        }
    }
    for(int i=1;i<=n;i++){
        if(f[i]==i){
            v[0].pb(i);
        }
    }
    dfs(0,0);
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            p[j][i]=p[p[j][i-1]][i-1];
        }
    }
    for(auto it:add){
        int l=it.y.x,r=it.y.y,x=it.x;
        s[in[l]].insert(x);
        s[in[r]].insert(x);
        rmv[lca(l,r)].pb(mp(in[l],x));
        rmv[lca(l,r)].pb(mp(in[r],x));
    }
    root=new node(1,n);
    build(root);
    int val[500005];
    for(auto it:seq){
        for(auto p:rmv[it]){
            rm(root,p.x,p.y);
        }
        val[it]=query(root,in[it],out[it]);
    }
    LL ans=0;
    for(auto it:edge){
        if(dis[it.x]<dis[it.y])
            swap(it.x,it.y);
        if(val[it.x]==1e9+1){
            printf("-1\n");
            return 0;
        }
        ans+=val[it.x];
    }
    printf("%lld\n",ans);
}