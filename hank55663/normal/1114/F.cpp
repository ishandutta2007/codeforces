#pragma GCC optimize("Ofast") 
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
struct node{
    node *l,*r;
    LL bits;
    LL tagb;
    LL sum;
    LL tag;
    int a,b;
    node(int _a,int _b){
        a=_a;
        b=_b;
        l=NULL;
        r=NULL;
        bits=0;
        tagb=0;
        sum=1;
        tag=1;
    }
}*root;
const int mod=1e9+7;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL Sum(node *n){
    if(n->tag!=1){
        return n->sum*f_pow(n->tag,n->b-n->a+1)%mod;
    }
    return n->sum;
}
LL bits(node *n){
    return n->bits|n->tagb;
}
void push(node *n){
    n->l->tagb|=n->tagb;
    n->r->tagb|=n->tagb;
    n->tagb=0;
    n->l->tag*=n->tag;
    n->l->tag%=mod;
    n->r->tag*=n->tag;
    n->r->tag%=mod;
    n->tag=1;
}
void pull(node *n){
    n->bits=bits(n->l)|bits(n->r);
    n->sum=Sum(n->l)*Sum(n->r)%mod;
}
int a[400005];
LL b[400005];
void build(node *n){
    if(n->a==n->b){
        n->sum=a[n->a];
        n->bits=b[n->a];
        return;
    }
    int mid=(n->a+n->b)/2;
 //   printf("%d %d %d\n",mid,n->a,n->b);
  //  getchar();
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
    pull(n);
}
void revise(node *n,int l,int r,int k,LL x){
    if(n->a>=l&&n->b<=r){
        n->tagb|=x;
        n->tag=n->tag*k%mod;
        return ;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    revise(n->l,l,r,k,x);
    revise(n->r,l,r,k,x);
    pull(n);
}
pair<LL,LL> query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return mp(Sum(n),bits(n));//->bits);
    }
    if(n->b<l||n->a>r){
        return mp(1,0);
    }
    push(n);
    auto p1=query(n->l,l,r),p2=query(n->r,l,r);
    pull(n);
    return mp(p1.x*p2.x%mod,p1.y|p2.y);
}
vector<int> prime;
vector<int> inv;
void buildp(){
    int isprime[305];
    fill(isprime,isprime+305,1);
    for(int i=2;i<=300;i++){
        if(isprime[i]){
            prime.pb(i);
            inv.pb(f_pow(i,mod-2));
            for(int j=i;j<=300;j+=i)
            isprime[j]=0;
        }
    }
}
int main(){
    buildp();
 //   printf("%d\n",prime.size());
    int n,q;
    scanf("%d %d",&n,&q);
    root=new node(1,n);
  //  printf("%d %d\n",root->a,root->b);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        for(int j=0;j<prime.size();j++){
            if(prime[j]>a[i])
            break;
            if(a[i]%prime[j]==0){
                //printf("%d %d\n",i,prime[j]);
                b[i]|=1ll<<j;
            }
        }
    }
    build(root);
    while(q--){
        char c[10];
        scanf("%s",c);
        if(c[0]=='T'){
            int l,r;
            scanf("%d %d",&l,&r);
            auto ans=query(root,l,r);
            //printf("%d\n",ans.x);
            for(int i=0;i<prime.size();i++){
                if(ans.y&(1ll<<i)){
                //    printf("%d\n",prime[i]);
                    ans.x=ans.x*(prime[i]-1)%mod*inv[i]%mod;
                }
            }
            /*int tot=1;
            for(int i=l;i<=r;i++)tot*=a[i];
            int ans2=0;
            for(int i=1;i<=tot;i++){
                if(__gcd(i,tot)==1)
                ans2++;
            }
            printf("%d\n",ans2);*/
            printf("%lld\n",ans.x);
            //assert(ans2==ans.x);
        }
        else{
            int l,r,x;
            scanf("%d %d %d",&l,&r,&x);
            LL bb=0;
            for(int i=0;i<prime.size();i++){//:prime){
                if(x%prime[i]==0){
         //           printf("%d\n",it);
                    bb|=1ll<<i;
                }
            }
            revise(root,l,r,x,bb);
          //  for(int i=l;i<=r;i++){a[i]*=x;};
        }
    }
}