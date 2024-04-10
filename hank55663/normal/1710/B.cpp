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
using namespace std;
#define N 500005
#define rank Rank
pii p[200005];
LL val[1000005];
LL r[1000005];
struct node{
    node *l,*r;
    int a,b;
    LL sum;
    LL Maxpre;
    LL Maxcnt;
    LL tag;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),sum(0),Maxpre(0),tag(0),Maxcnt(0){

    }
}*root;
LL sum(node *n){
    return n->sum+n->tag*(r[n->b+1]-r[n->a]);
}
LL Maxpre(node *n){
    return max(n->Maxpre+n->tag*(n->Maxcnt),0ll);
}
void pull(node *n){
    n->sum=sum(n->l)+sum(n->r);
  //  if()
    n->Maxpre=max(Maxpre(n->l),sum(n->l)+Maxpre(n->r));
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
void build(node *n){
    if(n->a==n->b)return;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
    pull(n);
}
void add(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
LL res[1000005];
void dfs(node *n){
    if(!n)return;
    if(n->a==n->b){
        res[n->a]=sum(n);
       // printf(" %d",sum(n));
        return;
    }
    push(n);
    dfs(n->l);
    dfs(n->r);
    pull(n);
}
vector<pll> v[1000005];
multiset<LL> s1,s2;
LL ans[1000005];
LL ans1[1000005],ans2[1000005];
void solve(){
    int n,s;
    scanf("%d %d",&n,&s);
    map<int,int> m;
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
        m[x+1];
        m[x-y+1];
        m[x+y+1];
    }
    int now=0;
    for(auto &it:m){
        it.y=++now;
        r[now]=it.x;
        val[now-1]=r[now]-r[now-1];
        v[now].clear();
     
    }   s1.clear();
        s2.clear();
    r[now+1]=2e9+1;
    root=new node(1,now);
    build(root);
    for(int i = 0;i<n;i++){
        int x,y;
        tie(x,y)=p[i];
      //  printf("%d %d %d %d\n",x-y+1,x,x+1,x+y+1);
        add(root,m[x-y+1],m[x+1]-1,1);
        add(root,m[x+1],m[x+y+1]-1,-1);
       //   printf("%d ",Maxpre(root));
    }
    dfs(root);
   // printf("\n");
    LL tot=0;
    for(int i = 1;i<=now;i++){
        tot+=res[i];
      //  printf("%d %d\n",r[i+1]-1,tot);
        if(tot>s){
            v[i].pb(mp(tot-s-(r[i+1]-1),1));
            v[i].pb(mp(tot-s+(r[i+1]-1),-1));
            //v[0].pb(now-m+(r[i+1]-1));
         //   printf("%d %d %d\n",tot-s+(r[i+1]-1),r[i+1]-1,tot-s-(r[i+1]-1));
            s2.insert(tot-s+(r[i+1]-1));
        }
    }
    for(int i = 1;i<=now;i++){
        for(auto it:v[i]){
            if(it.y==-1)s2.erase(s2.find(it.x));
            else s1.insert(it.x);
        }
        if(s2.size()){
            ans2[i]=*s2.rbegin();
        }
        else{
            ans2[i]=-1e18-7;
        }
        if(s1.size())ans[i]=*s1.rbegin();
        else ans[i]=-1e18-7;
    }
    for(int i = 0;i<n;i++){
        int x,y;
        tie(x,y)=p[i];
        int aa=m[x+1]-1;
        if(ans[aa]<=y-x&&ans2[aa]<=x+y){
            printf("1");
        }
        else printf("0");
    }
    printf("\n");
}  
int main(){
    int t=1;000;
    scanf("%d",&t);
//    srand(time(NULL));
    while(t--){
        solve();
    }
    
}
/*
*/