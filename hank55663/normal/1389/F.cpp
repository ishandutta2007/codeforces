#include<bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
vector<pii> v[400005];
int dp[400005][2];
struct node{
    node *l,*r;
    int a,b;
    int tag;
    int Max;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),tag(0),Max(0){

    }
}*root[2];
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
int Max(node *n){
    return n->Max+n->tag;
}
void pull(node *n){
    n->Max=max(Max(n->l),Max(n->r));
}
void build(node *n){
    if(n->a==n->b)return ;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void add(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
int query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return Max(n);
    }
    if(n->b<l||n->a>r)return 0;
    push(n);
    int res=max(query(n->l,l,r),query(n->r,l,r));
    pull(n);
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    map<int,int> m;
    pair<pii,int> p[200005];
    for(int i = 0;i<n;i++){
        int l,r,t;
        scanf("%d %d %d",&l,&r,&t);
       t--;
        p[i]=mp(mp(l,r),t);
        m[l];
        m[r];
    }
    int index=0;
    for(auto &it:m){
        it.y=++index;
    }
    for(int i =0;i<n;i++){
        p[i].x.x=m[p[i].x.x];p[i].x.y=m[p[i].x.y];v[p[i].x.y].pb(mp(p[i].x.x,p[i].y));
    }
    root[0]=new node(0,index);
    root[1]=new node(0,index);
    build(root[0]);
    build(root[1]);
    for(int i = 1;i<=index;i++){
        for(auto it:v[i]){
            add(root[it.y],0,it.x-1,1);
        }
        dp[i][0]=max(query(root[0],0,i-1),dp[i-1][0]);
        dp[i][1]=max(query(root[1],0,i-1),dp[i-1][1]);
        add(root[0],i,i,dp[i][1]);
        add(root[1],i,i,dp[i][0]);
    }
    printf("%d\n",max(dp[index][0],dp[index][1]));
}//?