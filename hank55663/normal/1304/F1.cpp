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
#define MXN 100005
int dp[55][20005];
int val[55][20005];
int pre[55][20005];
struct node{
    node *l,*r;
    int a,b;
    int Max;
    int tag;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),Max(0),tag(0){

    }
}*root;
int Max(node *n){
    return n->Max+n->tag;
}
void pull(node *n){
    n->Max=max(Max(n->l),Max(n->r));
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
void build(node *n,int *a){
    if(n->a==n->b){
        n->Max=a[n->a];
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
    pull(n);
}
void add(node *n,int l,int r,int x){
    if(n->a>=l&&n->b<=r){
        n->tag+=x;
        return ;
    }
    if(n->b<l||n->a>r)return ;
    push(n);
    add(n->l,l,r,x);
    add(n->r,l,r,x);
    pull(n);
}
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            scanf("%d",&val[i][j]);
            pre[i][j]=pre[i][j-1]+val[i][j];
        }
    }
    for(int i = 1;i<=m;i++){
        dp[1][i]=pre[1][min(i+k-1,m)]-pre[1][i-1]+
                 pre[2][min(i+k-1,m)]-pre[2][i-1];
      //  printf("%d ",dp[1][i]);
    }
   // printf("\n");
    for(int i = 2;i<=n;i++){
        root = new node(1,m);
        build(root,dp[i-1]);
        for(int j = 1;j<=k;j++){
            add(root,j-k+1,j,-val[i][j]);
        }
        for(int j = 1;j<=m;j++){
            dp[i][j]=pre[i][min(j+k-1,m)]-pre[i][j-1]+
                     pre[i+1][min(j+k-1,m)]-pre[i+1][j-1]+
                     Max(root);
         //  printf("%d ",Max(root));
            add(root,j-k+1,j,val[i][j]);
            if(j+k<=m)
                add(root,j+1,j+k,-val[i][j+k]);
          //  printf("%d ",dp[i][j]);
        }
     //   printf("\n");
    }
    int ans=0;
    for(int j=1;j<=m;j++)
        ans=max(ans,dp[n][j]);
    printf("%d\n",ans);
}
/*
6 10
1 1 0 0 0 0 0 0 0 0 
1 1 1 1 0 0 0 0 0 0 
0 0 1 1 0 0 0 0 0 0 
2 2 3 3 0 0 0 0 0 0 
0 0 3 3 4 4 0 0 0 0 

{1}
{1}
{1000000000}
{1000000000}
1

1000000000 
1000
{1000}
{1000000000}
*/