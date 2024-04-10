#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
LL a[100005];
LL k[100005];
LL sum1[100005];
LL sum2[100005];
struct node{
    node *l,*r;
    LL tag;
    int a,b;
    LL sum;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),tag(0),sum(0){
        tag=-1e18;
    }
}*root;
LL Sum(node *n){
    if(n->tag!=-1e18){
        return (n->b-n->a+1)*n->tag;
    }
    else{
        return n->sum;
    }
}
void pull(node *n){
    n->sum=Sum(n->l)+Sum(n->r);
}
void push(node *n){
    if(n->tag!=-1e18){
        n->l->tag=n->tag;
        n->r->tag=n->tag;
        n->tag=-1e18;
    }
}
void build(node *n){
    if(n->a==n->b){
        n->sum=a[n->a];
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
    pull(n);
}
void revise(node *n,int l,int r,LL k){
    if(n->a>=l&&n->b<=r){
        n->tag=k;
        return ;
    }
    if(n->b<l||n->a>r){
        return ;
    }
    push(n);
    revise(n->l,l,r,k);
    revise(n->r,l,r,k);
    pull(n);
}
LL query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return Sum(n);
    }
    if(n->b<l||n->a>r){
        return 0;
    }
    push(n);
    LL res= query(n->l,l,r)+query(n->r,l,r);
    pull(n);
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    scanf("%lld",&a[i]);
    for(int j=1;j<n;j++){
        scanf("%lld",&k[j]);
    }
    sum1[1]=k[1];
    for(int j=2;j<n;j++){
        sum1[j]=k[j]+sum1[j-1];
    }
    sum2[1]=sum1[1];
    for(int j=2;j<n;j++){
        sum2[j]=sum1[j]+sum2[j-1];
    }
    for(int j=1;j<n;j++){
        a[j+1]-=sum1[j];
    }
    /*for(int j=1;j<=n;j++)
    printf("%d ",a[j]);
    printf("\n");*/
    root = new node(1,n);
    build(root);

    int q;
    scanf("%d",&q);
    while(q--){
        char c;
        scanf(" %c",&c);
        if(c=='s'){
            int l,r;
            scanf("%d %d",&l,&r);
            LL res=query(root,l,r);
           // printf("%lld\n",res);
            if(l==1)
            res+=sum2[r-1]-sum2[l-1];
            else
            res+=sum2[r-1]-sum2[l-2];
            //printf("%lld %lld\n",sum2[r-1],sum2[l-1]);
            printf("%lld\n",res);
        }
        else{
            int i,x;
            scanf("%d %d",&i,&x);
            LL now=query(root,i,i);
            int Max=n+1,Min=i;
            while(Max>Min+1){
                int mid=(Max+Min)/2;
                if(query(root,mid,mid)>=now+x){
                    Max=mid;
                }
                else{
                    Min=mid;
                }
            }
            revise(root,i,Min,now+x);
        }
    }
}