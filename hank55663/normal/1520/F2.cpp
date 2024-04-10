#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
struct node{
    node *l,*r;
    int a,b;
    int ans;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),ans(-1){
    
    }
}*root;
int qu(node *n){
    if(n->ans==-1){
        printf("? %d %d\n",n->a,n->b);
        fflush(stdout);
        int x;
        scanf("%d",&n->ans);
    }
    return n->b-n->a+1-n->ans;
}
void build(node *n){
    if(n->a==n->b)return;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
int query(node *n,int k){
    if(n->a==n->b){
        n->ans=1;
        return n->a;
    }
    n->ans++;
    if(qu(n->l)<=k){
        return query(n->r,k-qu(n->l));
    }
    else{
        return query(n->l,k);
    }
}
void solve(){
    int n,t;
    scanf("%d %d",&n,&t);
    root=new node(1,n);
    build(root);
    while(t--){
        int k;
        scanf("%d",&k);
        k--;
        printf("! %d\n",query(root,k));
        fflush(stdout);
    }
}
int main(){
  //  for(int i = 1;i*i<=1e9;i++)s.insert(i*i);
    int t=1;00000;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
36
6x+s=ty
x x<<13  x>>7  x<<13>>7
x<<17  x<<30 x>>7<<17 x<<23

*/