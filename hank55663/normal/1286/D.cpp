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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
struct node{
    node *l,*r;
    int a,b;
    LL val[2][2];
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b){
        MEM(val);
    }
}*root;
int mod=998244353;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int no[100005][2][2];
void pull(node *n){
    MEM(n->val);
    for(int i1 = 0;i1<2;i1++){
        for(int j1=0;j1<2;j1++){
            for(int i2=0;i2<2;i2++){
                for(int j2=0;j2<2;j2++){
                    if(!no[n->l->b][j1][i2]){
                        n->val[i1][j2]+=n->l->val[i1][j1]*n->r->val[i2][j2];
                        n->val[i1][j2]%=mod;
                    }
                }
            }
        }
    }
}
void build(node *n,LL *p,LL *inv){
    if(n->a==n->b){
        n->val[0][0]=p[n->a];
        n->val[1][1]=inv[n->a];
        //printf("%d %d %d\n",n->a,p[n->a],inv[n->a]);
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,p,inv);
    build(n->r,p,inv);
    pull(n);
    /*for(int i = 0;i<2;i++){
        for(int j=0;j<2;j++)
            printf("%d ",n->val[i][j]);
        printf("\n");
    }*/
}
void update(node *n,int x){
    if(n->b==x)return;
    int mid=(n->a+n->b)/2;
    if(x<=mid)update(n->l,x);
    else update(n->r,x);
    pull(n);
}
bool cmp(const tuple<pll,int,pii> &a,const tuple<pll,int,pii> &b){
    pll p1=get<0>(a);
    pll p2=get<0>(b);
    return p1.x*p2.y<p2.x*p1.y;
}
int main(){
    int n;
    scanf("%d",&n);
    LL x[100005],vv[100005],p[100005],inv[100005];
    for(int i = 1;i<=n;i++){
        scanf("%lld %lld %lld",&x[i],&vv[i],&p[i]);
        inv[i]=(100-p[i])*f_pow(100,mod-2)%mod;
        p[i]=p[i]*f_pow(100,mod-2)%mod;
    }
    vector<tuple<pll,int,pii> > v;
    for(int i = 1;i<n;i++){
        v.pb(make_tuple(mp(x[i+1]-x[i],vv[i]+vv[i+1]),i,mp(0,1)));
        if(vv[i]>vv[i+1]){
            v.pb(make_tuple(mp(x[i+1]-x[i],vv[i]-vv[i+1]),i,mp(0,0)));
        }
        if(vv[i]<vv[i+1]){
            v.pb(make_tuple(mp(x[i+1]-x[i],vv[i+1]-vv[i]),i,mp(1,1)));
        }
    }
    sort(v.begin(),v.end(),cmp);
    root=new node(1,n);
    build(root,p,inv);
    LL ans=0;
    for(auto it:v){
        pll p;
        int x;
        pii s;
        tie(p,x,s)=it;
        
        LL ti=p.x*f_pow(p.y,mod-2)%mod;
      //  printf("%lld %d %d %d\n",ti,x,s.x,s.y);
        LL ori=0;
        for(int i = 0;i<2;i++)
            for(int j=0;j<2;j++)
                ori+=root->val[i][j];
      //  printf("%lld\n",ori);
        no[x][s.x][s.y]=1;
        update(root,x);
        LL now=0;
        for(int i = 0;i<2;i++)
            for(int j=0;j<2;j++)
                now+=root->val[i][j];
        ans+=((ori-now)%mod+mod)%mod*ti%mod;
        ans%=mod;
    }
    printf("%lld\n",ans);
}
/*


     0   
     1   1
     2   3
     3 5  1 0 0
    4*/