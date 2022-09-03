#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=998244353;
#define MXN 2005
LL a[3][500005];
LL pre[500005];
LL val[500005],val2[500005];
struct node{
    node *l,*r;
    LL val1,val2;
    LL ans;
    int a,b;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL){

    }
}*root;
void pull(node *n){
    n->ans=max(n->l->ans,n->r->ans);
    n->ans=max(n->ans,n->l->val1+n->r->val2);
    n->val1=max(n->l->val1,n->r->val1);
    n->val2=max(n->l->val2,n->r->val2);
}
/*
void push(node *n){
    if(n->tag!=-1e18){
        n->l->tag=max(n->tag,n->l->tag);
        n->r->tag=max(n->tag,n->r->tag);
        n->tag=-1e18;
    }
}*/
void build(node *n,LL *a,LL *b){
    if(n->a==n->b){
        n->val1=a[n->a];
        n->val2=b[n->a];
        n->ans=n->val1+n->val2;
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a,b);
    build(n->r,a,b);
    pull(n);
}
node query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return *n;
    }
    int mid=(n->a+n->b)/2;
    if(r<=mid)return query(n->l,l,r);
    if(l>mid)return query(n->r,l,r);
    node ll=query(n->l,l,r);
    node rr=query(n->r,l,r);
    node nn(0,0);
    nn.l=&ll;
    nn.r=&rr;
    pull(&nn);
    return nn;

}
LL Max[500005];
void dc(int l,int r,vector<pair<pii,int> > v){
    if(l==r)return;
    int mid=(l+r)/2;
    vector<pair<pii,int> > ll,rr;
    for(auto it:v){
        if(it.x.y+1<=mid)ll.pb(it);
        else if(it.x.y+1>mid+1){
            if(it.x.x<=mid)it.x.x=mid+1;
            rr.pb(it);
        }
    }
    dc(l,mid,ll);
    Max[mid]=val[mid];
    for(int i = mid-1;i>=l;i--){
        Max[i]=max(Max[i+1],val[i]);
    }
    for(int i = mid+1;i<=r;i++)Max[i]=-1e18;
    for(auto it:v){
        if(it.x.x<=mid&&it.x.y+1>mid){
          //  if(l==3&&r==4){
              //  printf("?%d %d %d\n",it.x.x,it.x.y,it.y);
          //  }
            Max[it.x.y+1]=max(Max[it.x.y+1],Max[it.x.x]-it.y);
        }
    }
    LL vval=-1e18;
    for(int i = r;i>mid;i--){
        vval=max(Max[i],vval);
        val[i]=max(vval,val[i]);
    }
    dc(mid+1,r,rr);
    
}
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i = 0;i<3;i++){
        for(int j = 1;j<=n;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    pre[0]=0;
    for(int i = 1;i<=n;i++){
        pre[i]=pre[i-1]+a[1][i];
    }
    LL sum=0;
    for(int i = 1;i<=n;i++){
        sum+=a[0][i];
        val[i]=sum-pre[i-1];
       // printf("(%lld %lld)",sum,pre[i-1]);
    }
   // printf("\n");
    sum=0;
    for(int i = n;i>=1;i--){
        sum+=a[2][i];
        val2[i]=sum+pre[i];
    }
    vector<pair<pii,int> > v;
    for(int i = 0;i<q;i++){
        int l,r,k;
        scanf("%d %d %d",&l,&r,&k);
        v.pb(mp(mp(l,r),k));
    }
     for(int i = 1;i<=n;i++){
     //   printf("%lld %lld\n",val[i],val2[i]);
        
    }
   // printf("\n");
    dc(1,n,v);
    root=new node(1,n);
    for(int i = 1;i<=n;i++){
     //   printf("%lld %lld\n",val[i],val2[i]);
        
    }
    build(root,val,val2);
    LL ans=-1e18;
    for(auto it:v){
        node n=query(root,it.x.x,it.x.y);
        ans=max(ans,n.ans-it.y);
      //  printf("%d\n",ans);
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;0000;
      //scanf("%d",&t);
   //  while(solve());
     
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}