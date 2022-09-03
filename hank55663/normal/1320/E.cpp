#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 1005
#define N 2000005
vector<int> v[200005];
int in[200005],out[200005],number[200005];
int t;
int p[20][200005];
int dis[200005];
void dfs(int x,int f){
    in[x]=++t;
    number[t]=x;
    p[0][x]=f;
    dis[x]=dis[f]+1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
        }
    }
    out[x]=t;
}
void build(int n){
    for(int i = 1;i<20;i++){
        for(int j=1;j<=n;j++){
            p[i][j]=p[i-1][p[i-1][j]];
        }
    }
}
int lca(int x,int y){
    if(dis[x]>dis[y])swap(x,y);
    int d=dis[y]-dis[x];
    for(int i = 0 ; i < 20 ; i++){
        if(d & (1<<i)){
            y = p[i][y];
        }
    }
  //  printf("lca%d %d\n",x,y);
    if(x == y) return x;
    for(int i = 19 ; i >= 0 ; i--){
        if(p[i][y] != p[i][x]){
            x = p[i][x];
            y = p[i][y];
        }
    }
    return p[0][x];
}
int getdis(int x,int y){
    int lcaa=lca(x,y);
    return dis[x]+dis[y]-dis[lcaa]*2;
}
bool cmp(const int &a,const int &b){
    return in[a]<in[b];
}
vector<int> tmpv[200005];
int vis[200005];
int bln[200005];
int num[200005];
vector<int> buildtree(vector<int> &vertex){
    vector<int> tmp;
    for(auto it:vertex){
        tmp.pb(it);
    }
    sort(tmp.begin(),tmp.end(),cmp);
    for(int i = 0;i<vertex.size()-1;i++){
        tmp.pb(lca(tmp[i],tmp[i+1]));
       // printf("%d %d %d\n",tmp[i],tmp[i+1],lca(tmp[i],tmp[i+1]));
    }
    sort(tmp.begin(),tmp.end(),cmp);
    tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin());
    for(auto it:tmp)tmpv[it].clear(),vis[it] = 0;
    vector<int> stk;
    stk.pb(tmp[0]);
    for(int i = 1;i<tmp.size();i++){
        while(in[tmp[i]]>out[stk.back()])stk.pop_back();
        tmpv[stk.back()].pb(tmp[i]);
        tmpv[tmp[i]].pb(stk.back());
        stk.pb(tmp[i]);
    }
    return tmp;
}
int s[200005];
int heigh[200005];
void solve(vector<int> vertex){
    auto vertex2 = buildtree(vertex);
    for(auto it:vertex){
        vis[it]=1;
        bln[it]=it;
        heigh[it]=1e6;
    }
    priority_queue<pair<int,pii>,vector<pair<int,pii> >,greater<pair<int,pii> > > pq;
    for(auto it:vertex){
        for(auto it2:tmpv[it]){
            if(!vis[it2]){
                pq.push(mp((abs(dis[it]-dis[it2])+s[it]-1)/s[it],mp(num[it],it2)));
            }
        }
    }
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        p.y.x=vertex[p.y.x-1];
        if(!vis[p.y.y]){
            vis[p.y.y]=1;
            bln[p.y.y]=p.y.x;
        }
        else{
            continue;
        }
        for(auto it:tmpv[p.y.y]){
            if(!vis[it]){
                pq.push(mp((getdis(it,p.y.x)+s[p.y.x]-1)/s[p.y.x],mp(num[p.y.x],it)));
            }
        }
    }
    for(auto it:vertex2){
        for(auto it2:tmpv[it]){
            if(bln[it]!=bln[it2]&&dis[it]>dis[it2]){
                int d=getdis(bln[it],bln[it2])-1;
                int a=bln[it],b=bln[it2];
                heigh[a]=d/(s[a]+s[b])*s[a];
                if(num[a]>num[b]){
                    heigh[a]+=max(0,d%(s[a]+s[b])-s[b]);
                }
                else{
                    heigh[a]+=min(d%(s[a]+s[b]),s[a]);
                }
            }
        }
    }
}
int go(int x,int h){
    for(int i = 0;i<20;i++){
        if(h&(1<<i)){
            x = p[i][x];
        }
    }
    if(x==0)return 1;
    return x;
}
struct node{
    node *l,*r;
    int a,b;
    int tag;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),tag(0){

    }
}*root;
void build(node *n){
    if(n->a==n->b)return;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void push(node *n){
    if(n->tag){
        n->l->tag=n->tag;
        n->r->tag=n->tag;
        n->tag=0;
    }
}
void add(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
    //    printf("%d %d %d\n",n->a,n->b,k);
        n->tag=k;
        return ;
    }
    if(n->b<l||n->a>r){
        return ;
    }
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
}
int query(node *n,int x){
    if(n->a==n->b){
        return n->tag;
    }
    int mid=(n->a+n->b)/2;
    push(n);
    if(x<=mid){
        return query(n->l,x);
    }
    else{
        return query(n->r,x);
    }
}
int ans[200005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i < n ; i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    build(n);
    root=  new node(1,n);
    build(root);
  //  printf("!\n");
    int q;
    scanf("%d",&q);
    while(q--){
        int k,m;
        scanf("%d %d",&k,&m);
        vector<int> vertex;
        for(int i = 0;i<k;i++){
            int x;
            scanf("%d",&x);
            scanf("%d",&s[x]);
            num[x]=i+1;
            vertex.pb(x);
        }
        solve(vertex);
        vector<pair<pii,int> > vertex2;
        int now=1;
        for(auto it:vertex){
            int x=go(it,heigh[it]);
            vertex2.pb(mp(mp(in[x],out[x]),now));
            now++;
        }
        sort(vertex2.begin(),vertex2.end());
        for(auto it:vertex2){
            add(root,it.x.x,it.x.y,it.y);
        }
        while(m--){
            int x;
            scanf("%d",&x);
            printf("%d ",query(root,in[x]));
        }
        printf("\n");
    }
}
/*
10
2 4
7 8
6 3
9 2
6 8
7 1
9 8
9 10
5 4
10
8 5
7 1
9 2
5 1
2 5
10 3
4 4
6 1
1 1
2 8 6 4 10
*/