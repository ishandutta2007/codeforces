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
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct node{
    node *l,*r;
    LL sum;
    int a,b;
    LL tag;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b){
        tag=0;
        sum=0;
    }
}*root;
LL sum(node *n){
    return n->sum+(n->b-n->a+1)*n->tag;
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
void pull(node *n){
    n->sum=sum(n->l)+sum(n->r);
}
void build(node *n){
    if(n->a==n->b){
        n->sum=0;
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
LL query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return sum(n);
    }
    if(n->b<l||n->a>r)return 0;
    push(n);
    LL res=query(n->l,l,r)+query(n->r,l,r);
    pull(n);
    return res;
}
void ass(node *n,int x,int k){
    if(n->a==n->b){
        n->tag=0;
        n->sum=k;
        return;
    }
    push(n);
    int mid=(n->a+n->b)/2;
    if(x<=mid){
        ass(n->l,x,k);
    }
    else{
        ass(n->r,x,k);
    }
    pull(n);
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
void solve(){
    LL n;
    scanf("%lld",&n);
    root=new node(1,n);
    build(root);
    LL ans=n*(n+1)*n/2;
    char c[500005];
    scanf("%s",c+1);
    vector<LL> v;
    //v.pb(0);
    int cnt=0;
    for(int i = 1;c[i]!=0;i++){
        if(c[i]=='1'){
            //if(v.empty()){
               // x1-=i;
            cnt++; 
        }
        else{
            cnt=0;
        }
        add(root,cnt+1,n,1);
        if(cnt!=0)
        ass(root,cnt,cnt-1);
        ans-=sum(root);
    //    printf("%lld %lld\n",ans,sum(root));
    }
  //  x2+=2*(n-v.back())*x1+(n-v.back())*(n-v.back())*x0;
  //  x1+=(n-v.back())*x0;
   // ans-=x2+x1;
    //printf("%d %d %d\n",x2,x1,x0);
    printf("%lld\n",ans);
}



int main(){
    int t=1;
  //  scanf("%d",&t);
   
    while(t--){
        solve();
    }
}
/*
5 0 5
10 0
-10 0
-20 10
0 30
20 10
*/