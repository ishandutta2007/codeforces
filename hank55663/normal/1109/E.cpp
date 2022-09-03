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
//#define sqr(x) ((x)*(x))
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash;
#define MXN 100005
//#define assert(x) while(!(x))
struct node{
    node *l,*r;
    int a,b;
    LL tag;
    int addtag;
    LL sum;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),tag(1),sum(0),addtag(0){
    }
}*root,*factor[15],*remain;
int mod;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
pll gcd(LL a,LL b){
    if(b==0) return mp(1,0);
    else{
        LL p=a/b;
        pll q=gcd(b,a%b);
        return mp(q.y,q.x-q.y*p);
    }
}
LL inv(LL x){
    pll p =gcd(mod,x);
    return (p.y%mod+mod)%mod;
}
LL Sum(node *n){
    return n->sum*n->tag%mod;
}
void push(node *n){
    n->l->tag*=n->tag;
    n->l->tag%=mod;
    n->r->tag*=n->tag;
    n->r->tag%=mod;
    n->tag=1;
    n->l->addtag+=n->addtag;
    n->r->addtag+=n->addtag;
    n->addtag=0;
}
void pull(node *n){
    n->sum=(Sum(n->l)+Sum(n->r))%mod;
}
void build(node *n,int *a){
    if(n->a==n->b){
        n->sum=n->addtag=a[n->a];
      //  printf("%d %d %lld\n",n->a,a[n->a],Sum(n));
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
    pull(n);
   // printf("%d %d %lld\n",n->a,n->b,Sum(n));
}
void revise(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->tag=n->tag*k%mod;
        n->addtag+=k;
        return ;
    }
    if(n->b<l||n->a>r)return ;
    push(n);
    revise(n->l,l,r,k);
    revise(n->r,l,r,k);
    pull(n);
}
void revise2(node *n,int x,int k){
    if(n->a==n->b){
        n->sum=k;
        n->tag=1;
        n->addtag=k;
        return ;
    }
    push(n);
    int mid=(n->a+n->b)/2;
    if(mid>=x){
        revise2(n->l,x,k);
    }
    else{
        revise2(n->r,x,k);
    }
    pull(n);
}
LL query(node *n,int l,int r){
    //printf("%d %d\n",l,r);
    if(n->a>=l&&n->b<=r){
      //  printf("%lld %lld %lld %lld\n",l,r,Sum(n),Sum(n->r));
        return Sum(n);
    }
    if(n->b<l||n->a>r)return 0;
    push(n);
    LL ret=(query(n->l,l,r)+query(n->r,l,r))%mod;
    pull(n);
    return ret;
}
LL query2(node *n,int x,int type){
    if(n->a==n->b){
        if(type==1)
        return n->addtag;
        else
        return Sum(n);
    }
    push(n);
    int mid=(n->a+n->b)/2;
    int ret;
    if(mid>=x)ret=query2(n->l,x,type);
    else ret=query2(n->r,x,type);
    pull(n);
    return ret;
}
int main(){
    int n;
    scanf("%d %d",&n,&mod);
    vector<int> fac;
    int temp=mod;
    for(int i=2;i<=1e5;i++){
        if(temp%i==0){
            fac.pb(i);
            while(temp%i==0)temp/=i;
        }
    }
    int a[100005];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    root = new node(1,n);
    build(root,a);
   // scanf("%d",&a[0]);
    int cnt[100005];
    for(int i=0;i<fac.size();i++){
        factor[i]=new node(1,n);
        for(int j=1;j<=n;j++){
            cnt[j]=0;
            while(a[j]%fac[i]==0){
                cnt[j]++;
                a[j]/=fac[i];
            }
           // printf("%d ",cnt[j]);
        }
      //  printf("\n");
        build(factor[i],cnt);
    }
    remain = new node(1,n);
    build(remain,a);
    int q;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int l,r,x;
            scanf("%d %d %d",&l,&r,&x);
            revise(root,l,r,x);
            for(int i=0;i<fac.size();i++){
                int cnt=0;
                while(x%fac[i]==0){
                    x/=fac[i];
                    cnt++;
                }
                if(cnt)
                revise(factor[i],l,r,cnt);
            }
            revise(remain,l,r,x);
        }
        else if(op==2){
            int x,div;
            scanf("%d %d",&x,&div);
            int temp[30];
            LL ans=1;
            for(int i=0;i<fac.size();i++){
                temp[i]=query2(factor[i],x,1);
                while(div%fac[i]==0){
                    temp[i]--;
                    div/=fac[i];
                }
             //   printf("%d %d\n",fac[i],temp[i]);
                revise2(factor[i],x,temp[i]);
                ans=ans*f_pow(fac[i],temp[i])%mod;
            }
            LL remainder=query2(remain,x,2)*inv(div)%mod;
           // printf("%d)
            revise2(remain,x,remainder);
            ans=ans*remainder%mod;
            revise2(root,x,ans);
        }
        else{
            int l,r;
            scanf("%d %d",&l,&r);
            printf("%lld\n",query(root,l,r));
        }
    }
}