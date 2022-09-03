#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 1000005
struct node{
    node *l,*r;
    int a,b;
    int Min;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),Min(0){

    }
}*root[100005];
void pull(node *n){
    n->Min=min(n->l->Min,n->r->Min);
}
node* Clone(node *n){
    node *res=new node(n->a,n->b);
    res->l=n->l;
    res->r=n->r;
    res->Min=n->Min;
    return res;
}
void build(node *n){
    if(n->a==n->b)return;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void revise(node *n,int x,int w){
    if(n->a==n->b){
        n->Min=w;
        return;
    }
    int mid=(n->a+n->b)/2;
    if(x<=mid){
        n->l=Clone(n->l);
        revise(n->l,x,w);
    }
    else{
        n->r=Clone(n->r);
        revise(n->r,x,w);
    }
    pull(n);
}
int query(node *n,int l){
    if(n->a==n->b)return n->a;
   // printf("%d %d %d\n",n->l->a,n->l->b,n->l->Min);
    if(n->l->Min>=l){
        return query(n->r,l);
    }
    return query(n->l,l);
}
vector<int> v[100005];
void solve(){
    int n;
    scanf("%d",&n);
    root[0]=new node(1,n+1);
    build(root[0]);
    for(int i = 1;i<=n+1;i++){
        v[i].pb(0);
    }
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        root[i]=Clone(root[i-1]);
        revise(root[i],x,i);
        v[x].pb(i);
    }
    for(int i = 1;i<=n+1;i++)v[i].pb(n+1);
    for(int i = 1;i<=n+1;i++){
        int ok=0;
        for(int j = 1;j<v[i].size();j++){
            if(v[i][j-1]+1==v[i][j])continue;
            if(query(root[v[i][j]-1],v[i][j-1]+1)==i)ok=1;
            //printf("%d %d %d %d %d\n",i,v[i][j]-1,v[i][j-1]+1,query(root[v[i][j]-1],v[i][j-1]+1),ok);
        }  
       // printf("%d\n",ok);
        if(!ok){
            printf("%d\n",i);
            return;
        }
    }
    printf("%d\n",n+2);

}
int main(){
    int t=1;
  //  scanf("%d",&t);
    int n;
    while(t--){
        solve();
    }
}
/*
32 16 15 20 13 2 1
16 8 25 30 10 0 0
5 6 30 24 16 1 1
18 21 39 12 30 1 1
10 8 29 13 36 1 1
24 25 30 31 3 0 0
21 22 10 27 33 0 0
*/