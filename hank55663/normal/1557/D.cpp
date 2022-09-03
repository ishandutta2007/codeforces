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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<pii> v[300005];
struct node{
    node *l,*r;
    int a,b;
    int Max,Maxi;
    int tag,tagi;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),Max(0),Maxi(0),tag(0),tagi(0){

    }
}*root;
int Max(node *n){
    return max(n->tag,n->Max);
}
int Maxi(node *n){
    return n->tag>n->Max?n->tagi:n->Maxi;
}
void build(node *n){
    if(n->a==n->b)return;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void pull(node *n){
    if(Max(n->l)>Max(n->r)){
        n->Max=Max(n->l);
        n->Maxi=Maxi(n->l);
    }
    else{
        n->Max=Max(n->r);
        n->Maxi=Maxi(n->r);
    }
}
void push(node *n){
    if(n->tag){
        n->l->tag=n->tag;
        n->l->tagi=n->tagi;
    }
    if(n->tag){
        n->r->tag=n->tag;
        n->r->tagi=n->tagi;
    }
    n->tag=n->tagi=0;
}
void add(node *n,int l,int r,int k,int ki){
    if(n->a>=l&&n->b<=r){
       //  printf("??%d %d %d\n",n->a,n->b,k);
        n->tag=k;
        n->tagi=ki;
        return ;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    add(n->l,l,r,k,ki);
    add(n->r,l,r,k,ki);
    pull(n);
}
pii query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
      //  printf("!!%d %d %d\n",n->a,n->b,Max(n));
        return mp(Max(n),Maxi(n));
    }
    if(n->b<l||n->a>r)return mp(0,0);
    push(n);
    pii p=max(query(n->l,l,r),query(n->r,l,r));
    pull(n);
    return p;
}
int dp[300005];
int from[300005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    map<int,int> ma;
    for(int i=  0;i<m;i++){
        int x,l,r;
        scanf("%d %d %d",&x,&l,&r);
        v[x].pb(mp(l,r));
        ma[l];
        ma[r];
    }
    int index=0;
    for(auto &it:ma)it.y=++index;
    root=new node(1,index);
    build(root);
    for(int i = 1;i<=n;i++){
        pii Max=mp(0,0);//Maxi=0;
        for(auto &it:v[i]){
            it.x=ma[it.x];
            it.y=ma[it.y];
         //   printf("%d %d\n",it.x,it.y);
            Max=max(Max,query(root,it.x,it.y));
        }
        from[i]=Max.y;
        dp[i]=Max.x+1;
       // printf("%d\n",dp[i]);
        for(auto &it:v[i]){
            add(root,it.x,it.y,dp[i],i);
        }
    }
    int Max=0,Maxi=0;
    for(int i = 1;i<=n;i++){
        if(dp[i]>Max)Max=dp[i],Maxi=i;
    }
    int vis[300005];
    fill(vis,vis+n+1,0);
    while(Maxi){
        vis[Maxi]=1;
        Maxi=from[Maxi];
    }
    printf("%d\n",n-Max);
    for(int i = 1;i<=n;i++){
        if(!vis[i])printf("%d ",i),Max++;
    }
    assert(n==Max);
    printf("\n");
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*

10 10 40000
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 1
*/