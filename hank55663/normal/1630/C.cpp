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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> v[200005];
vector<int> l[200005];
struct node{
    node *l,*r;
    int Min;
    int a,b;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),Min(1e9){

    }
}*root;
void pull(node *n){
    n->Min=min(n->l->Min,n->r->Min);
}
void build(node *n){
    if(n->a==n->b)return;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
int query(node *n,int l,int r){

    if(n->a>=l&&n->b<=r){
         //  printf("%d %d %d %d %d??\n",l,r,n->Min,n->a,n->b);
        return n->Min;
        
    }
    if(n->b<l||n->a>r)return 1e9;
    return min(query(n->l,l,r),query(n->r,l,r));
}
void add(node *n,int x,int k){
    if(n->a==n->b){
        n->Min=k;
        return;
    }
    int mid=(n->a+n->b)/2;
    if(x<=mid)add(n->l,x,k);
    else add(n->r,x,k);
    pull(n);
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        v[x].pb(i);
    }
    for(int i = 1;i<=n;i++){
        if(v[i].size()>1){
            l[v[i].back()].pb(v[i][0]+1);
        }
    }
    int dp[200005];
    dp[1]=0;
    root=new node(1,n);
    build(root);
    add(root,1,0);
  //  printf("0\n");
    for(int i = 2;i<=n;i++){
        dp[i]=dp[i-1]+1;
        for(auto it:l[i]){
            //printf("%d ",it);
            dp[i]=min(dp[i],query(root,it-1,i-1)+1);
        }
        add(root,i,dp[i]);
       // printf("%d\n",dp[i]);
    }
    printf("%d\n",n-1-dp[n]);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
(k_1x+b)k_2+b=y

36
0123
0123 4567
*/