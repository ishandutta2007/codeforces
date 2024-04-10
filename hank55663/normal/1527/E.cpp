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
    int Min;
    int tag;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),Min(0),tag(0){

    }
}*root;
int Min(node *n){
    return n->Min+n->tag;
}
void pull(node *n){
    n->Min=min(Min(n->l),Min(n->r));
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
void add(node *n,int l,int r,int w){
    if(n->a>=l&&n->b<=r){
        n->tag+=w;
        return;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    add(n->l,l,r,w);
    add(n->r,l,r,w);
    pull(n);
}
int query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r)return Min(n);
    if(n->b<l||n->a>r)return 1e9;
    push(n);
    int res=min(query(n->l,l,r),query(n->r,l,r));
    pull(n);
    return res;
}
void build(node *n,int *a){
    if(n->a==n->b){
        n->Min=a[n->a];
        n->tag=0;
        return;
    }
    if(!n->l){
        int mid=(n->a+n->b)/2;
        n->l=new node(n->a,mid);
        n->r=new node(mid+1,n->b);
    }
    build(n->l,a);
    build(n->r,a);
    n->tag=0;
    pull(n);
}
int dp[105][35005];
int last[35005];
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[35005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[1][i]=dp[1][i-1];
        if(last[a[i]])dp[1][i]+=i-last[a[i]];
        last[a[i]]=i;
     //   printf("%d ",dp[1][i]);
    }
  //  printf("\n");
    MEM(last);
    root=new node(1,n);
    for(int i = 2;i<=k;i++){
        build(root,dp[i-1]);
        MEM(last);
        for(int j = 1;j<=n;j++){
            if(last[a[j]]){
                int aa=query(root,1,last[a[j]]-1),b=query(root,last[a[j]],j-1);
               // printf("a:%d b:%d ",aa,b);
                dp[i][j]=min(aa+j-last[a[j]],b);
                add(root,1,last[a[j]]-1,j-last[a[j]]);
            }
            else{
                dp[i][j]=dp[i][j-1];
            }
            last[a[j]]=j;
         //    printf("%d ",dp[i][j]);
        }
    //    printf("\n");
    }
    printf("%d\n",dp[k][n]);
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--)
        solve();
    /*int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }*/
}
/*

*/