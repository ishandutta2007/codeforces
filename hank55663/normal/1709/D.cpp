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
#define double long double
using namespace std;
struct node{
    node *l,*r;
    int a,b;
    int Max;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),Max(0){

    }
}*root;
void pull(node *n){
    n->Max=max(n->l->Max,n->r->Max);
}
void build(node *n,int *a){
    if(n->a==n->b){
        n->Max=a[n->a];
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
    pull(n);
}
int query(node *n, int l,int r){
    if(n->a>=l&&n->b<=r){
        return n->Max;
    }
    if(n->b<l||n->a>r)return 0;
    return max(query(n->l,l,r),query(n->r,l,r));
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[200005];
    for(int i = 1;i<=m;i++)scanf("%d",&a[i]);
    int q;
    scanf("%d",&q);
    root=new node(1,m);
    build(root,a);
    while(q--){
        int xs,ys,xf,yf,k;
        scanf("%d %d %d %d %d",&xs,&ys,&xf,&yf,&k);
        if((xf-xs)%k||(ys-yf)%k){
            printf("NO\n");
        }
        else{
            xs=xs+(n-xs)/k*k;
            xf=xf+(n-xf)/k*k;
            if(query(root,min(ys,yf),max(ys,yf))<xs){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
}
int main(){
    int t=1;000;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
    
}
/*
*/