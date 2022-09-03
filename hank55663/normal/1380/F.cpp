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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
#define ll long long
struct node{
    node *l,*r;
    LL ans[2][2];
    int a,b;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b){
        MEM(ans);
    }
}*root;
int mod=998244353;
int a[500005];
int cal(int x){
    if(x<10||x>18)return 0;
    return 9-(x-10);    
}
void pull(node *n){
    for(int i = 0;i<2;i++)
        for(int j = 0;j<2;j++)
            n->ans[i][j]=(n->l->ans[i][0]*n->r->ans[0][j]+n->l->ans[i][1]*n->r->ans[1][j]%mod*cal(a[n->l->b]*10+a[n->r->a]))%mod;
}
void build(node *n){
    if(n->a==n->b){
         n->ans[0][0]=a[n->a]+1;
        n->ans[1][0]=1;
        n->ans[0][1]=1;
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
    pull(n);
}
void revise(node *n,int x,int d){
    if(n->a==n->b){
        a[n->a]=d;
        n->ans[0][0]=d+1;
        n->ans[1][0]=1;
        n->ans[0][1]=1;
        return ;
    }
    int mid=(n->a+n->b)/2;
    if(x<=mid)revise(n->l,x,d);
    else revise(n->r,x,d);
    pull(n);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    root = new node(1,n);
    for(int i = 1;i<=n;i++){
        char c;
        scanf(" %c",&c);
        a[i]=c-'0';
    }
    build(root);
      //     printf("%lld\n",root->ans[0][0]);
    while(m--){
        int x,d;
        scanf("%d %d",&x,&d);
        revise(root,x,d);
        printf("%lld\n",root->ans[0][0]);
    }
}