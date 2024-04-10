#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
struct node{
    node *l,*r;
    int a,b;
    LL val[2][2];
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b){

    }
}*root;
void pull(node *n){
  //  printf("a:%d b:%d\n",n->a,n->b);
    for(int i = 0;i<2;i++){
        for(int j = 0;j<2;j++){
            n->val[i][j]=max(n->l->val[i][j],n->r->val[i][j]);
            n->val[i][j]=max(n->val[i][j],n->l->val[i][0]+n->r->val[1][j]);
            n->val[i][j]=max(n->val[i][j],n->l->val[i][1]+n->r->val[0][j]);
          //  printf("%d ",n->val[i][j]);
        }
    }
}
void build(node *n,int *a){
    if(n->a==n->b){
        n->val[0][0]=a[n->a];
        n->val[1][1]=-a[n->a];
        n->val[1][0]=n->val[0][1]=-1e18;
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
    pull(n);
}
void revise(node *n,int x,int w){
    if(n->a==n->b){
        n->val[0][0]=w;
        n->val[1][1]=-w;
        return;
    }
    int mid=(n->a+n->b)/2;
    if(x<=mid){
        revise(n->l,x,w);
    }
    else{
        revise(n->r,x,w);
    }
    pull(n);
}
void solve(){   
    int n,q;
    scanf("%d %d",&n,&q);
    int a[300005];
    for(int i =  0 ;i<n;i++)scanf("%d",&a[i]);
    root=new node(0,n-1);
    build(root,a);
    printf("%lld\n",root->val[0][0]);
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        l--;
        r--;
        revise(root,l,a[r]);
        revise(root,r,a[l]);
        swap(a[l],a[r]);
        printf("%lld\n",root->val[0][0]);
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}


/*


*/