




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
#define MXN 150
#define KK 500
#define N 100005
int a[400005];
LL val[1<<20][20];
vector<int> v[25];
struct node{
    node *l,*r;
    LL tag;
    LL sum;
    int Min;
    int Size;
    int a,b;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),tag(0),sum(0),Min(0){
    }
}*root;
LL Sum(node *n){
    return n->sum+n->tag*n->Size;
}
int Min(node *n){
    return n->Min+n->tag;
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
void pull(node *n){
    n->Size=n->l->Size+n->r->Size;
    n->sum=Sum(n->l)+Sum(n->r);
    n->Min=min(Min(n->l),Min(n->r));
}
void build(node *n,vector<int> &a){
    if(n->a==n->b){
        n->sum=n->Min=a[n->a]-n->a;
        n->Size=1;
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
    pull(n);
}
void add(node *n,int k){
    if(Min(n)>0){
      //  printf("%d %d\n",n->a,n->b);
        n->tag--;
        return;
    }
    if(n->a==n->b){
        n->Size=0;
        n->sum=0;
        n->tag=0;
        n->Min=0;
        return ;
    }
    if(n->Size==0)return;
    push(n);
    add(n->l,k);
    add(n->r,k);
    pull(n);
}
LL dp[1<<20];
LL DP(int x){
    if(dp[x]!=-1)return dp[x];
    dp[x]=1e18;
    for(int i = 0;i<20;i++){
        if(x&(1<<i)){
            dp[x]=min(dp[x],DP(x-(1<<i))+val[x-(1<<i)][i]);
        }
    }
    //printf("%lld %lld\n",x,dp[x]);
    return dp[x];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        v[a[i]].pb(i);
    }
    for(int i =1;i<=20;i++){
        if(v[i].size()){
            LL cnt[25];
            MEM(cnt);
            int tot=v[i].size();
            for(int j =0;j<n;j++){
                if(a[j]==i)tot--;
                else cnt[a[j]]+=tot;
            }
            for(int j = 0;j<(1<<20);j++){
                LL sum=0;
                for(int k=0;k<20;k++){
                    if(j&(1<<k))sum+=cnt[k+1];
                }
                val[j][i-1]=sum;
            }
        }
    }
    MEMS(dp);
    dp[0]=0;
    printf("%lld\n",DP((1<<20)-1));
    return 0;
}