#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 500005
struct node{
    node *l,*r;
    int a,b;
   // LL sumr,vall;
    LL sum,val;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),sum(0),val(0){

    }
}*root,*root2;
const int mod=1e9+7;
//pll query(node *n,int l,int r,int val);
void pull(node *n){
    n->sum=(n->l->sum+n->r->sum)%mod;
}
void build(node *n){
    if(n->a==n->b)return;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void update(node *n,int k,int w,int v){
    if(n->a==n->b){
        n->sum=w;
       // n->val=v;
        return;
    }
    int mid=(n->a+n->b)/2;
    if(k<=mid)update(n->l,k,w,v);
    else update(n->r,k,w,v);
    pull(n);
}
LL query(node *n,int l,int r,int val){
    if(n->a>=l&&n->b<=r)return n->sum;
    if(n->b<l||n->a>r)return 0;
    return (query(n->l,l,r,val)+query(n->r,l,r,val))%mod;
    
}
void solve(){
    int n;
    scanf("%d",&n);
    root=new node(1,2*n);
    build(root);
    root2=new node(1,2*n);
    build(root2);
    pair<pii,int> p[200005];
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(mp(y,x),0);
    }
    int qq;
    scanf("%d",&qq);
    for(int i = 1;i<=qq;i++){
        int x;
        scanf("%d",&x);
        p[x-1].y=1;
    }
    sort(p,p+n);
    LL val[200005];
    for(int i = 0;i<n;i++){
        LL res=query(root,p[i].x.y,p[i].x.x,0);
        LL v=res+1;
        val[i]=v;
    //    printf("%lld\n",v);
        update(root,p[i].x.y,v,p[i].x.x);
        update(root2,p[i].x.x,v,p[i].x.x);
    }
  //  printf("!\n");
  //  pll res=query(root,1,2*n,0);
  //  printf("%lld\n",res.x);
    LL res=0;
    for(int i = n-1;i>=0;i--){
        if(p[i].y==1){
            for(int j = 0;j<i;j++)res+=val[j];
            res++;
           // printf("%d\n",res);
            res%=mod;
            int val=p[i].x.y;
            for(int j = n-1;j>=i;j--)update(root,p[j].x.y,0,0);
            for(int j = i-1;j>=0;j--){
                update(root,p[j].x.y,0,0);
                if(p[j].x.y>val&&p[j].y){
                    res+=query(root,val,p[j].x.x-1,0);
                    
                 //     printf("%lld\n",res);
                    res++;
                    res%=mod;
                    val=p[j].x.y;
                }
            }
            printf("%lld\n",res);
            return;
        }
    }
}
int main(){
    int t=1;0000;
 //   scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
[[([(([([([
1 8
3 4
1 8
2 7
5 6
*/