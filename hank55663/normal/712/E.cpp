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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 300000
#define N 100005
struct node{
    node *l,*r;
    double val1,val2;
    int a,b;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b){}
}*root;
void pull(node *n){
    double a=n->l->val1;
    double b=n->l->val2;
    double c=n->r->val1;
    double d=n->r->val2;
    n->val1=a*c+a*(1-c)*((1-b)*c/(b+(1-b)*c));
    swap(a,d);
    swap(b,c);
    n->val2=a*c+a*(1-c)*((1-b)*c/(b+(1-b)*c));
    //n->val=n->l->val*n->r->val/(n->l->val*n->r->val+1-n->l->val);
}
void build(node *n,double *val){
    if(n->a==n->b){
        n->val1=val[n->a];
        n->val2=1-val[n->a];
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,val);
    build(n->r,val);
    pull(n);
}
void revise(node *n,int x,double k){
    if(n->a==n->b){
        n->val1=k;
        n->val2=1-k;
        return ;
    }
    int mid=(n->a+n->b)/2;
    if(x<=mid)revise(n->l,x,k);
    else revise(n->r,x,k);
    pull(n);
}
pdd query(node *n,int l,int r){
    
    if(n->a>=l&&n->b<=r)return mp(n->val1,n->val2);
    if(n->b<l||n->a>r)return mp(1,1);
    double a,b,c,d;
    tie(a,b)=query(n->l,l,r);
    tie(c,d)=query(n->r,l,r);
    double res1,res2;
    res1=a*c+a*(1-c)*((1-b)*c/(b+(1-b)*c));
   // printf("%lf %lf %lf %lf\n",a,b,c,d);
    //res1=(a*c+a*(1-c)*(1-b)*c)/(a*c+a*(1-c)*(1-b)*c+(1-a)+a*(1-c)*b);
    swap(a,d);
    swap(b,c);
    res2=a*c+a*(1-c)*((1-b)*c/(b+(1-b)*c));
    //printf("%d %d %lf %lf\n",n->a,n->b,res1,res2);
    return mp(res1,res2);
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    double val[100005];
    for(int i = 1;i<=n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        val[i]=a;
        val[i]/=b;
    }
    root = new node(1,n);
    build(root,val);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x;
            int a,b;
            scanf("%d %d %d",&x,&a,&b);
            double value=a;
            value/=b;
            revise(root,x,value);
            val[x]=value;
        }
        else{
            int l,r;
            scanf("%d %d",&l,&r);
            double res=query(root,l,r).x;
            printf("%.12lf\n",res);
        }
    }
}