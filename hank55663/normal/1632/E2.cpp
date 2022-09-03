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
const int mod=998244353;
struct node{
    node *l,*r;
    int a,b;
    int sum;
    node(int _a,int _b):a(_a),b(_b),sum(0),l(NULL),r(NULL){

    }
}*root1,*root2;
int Sum(node *n){
    return n?n->sum:0;
}
void pull(node *n){
    n->sum=Sum(n->l)+Sum(n->r);
}
void push(node *n){
    if(!n->l){
        int mid=(n->a+n->b)/2;
        n->l=new node(n->a,mid);
        n->r=new node(mid+1,n->b);
    }
}
void add(node *n,int x,int k){
    if(n->a==n->b){
        n->sum++;
        return;
    }
    push(n);
    int mid=(n->a+n->b)/2;
    if(x<=mid)add(n->l,x,k);
    else add(n->r,x,k);
    pull(n);
}
node *merge(node *l,node *r){
    if(!l||!r)return l?l:r;
    l->l=merge(l->l,r->l);
    l->r=merge(l->r,r->r);
    l->sum+=Sum(r);
    return l;
}
int query(node *l,node *r){
    if(!l)swap(l,r);
    if(l->a==l->b)
    return l->a;
   // printf("%d %d\n",l->a,l->b);
   // printf("?%d %d\n",Sum(l->r),(r?Sum(r->r):0));
    if(Sum(l->r)==(r?Sum(r->r):0))return query(l->l,r?r->l:r);
    return query(l->r,r?r->r:r);
}
int d[300005];
int ans[305005];
int Max;
vector<int> v[300005];
void dfs(int x,int f){
    d[x]=d[f]+1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);

        }
    }
    Max=max(Max,d[x]);
    add(root1,d[x],1);
    //printf("d[%d] %d\n",x,d[x]);
}
int n;
pair<node*,pii> dfs2(int x,int f){
    node *ret=NULL;
    int Maxd=0;
    vector<int> tmp;
    for(auto it:v[x]){
        if(it!=f){
            auto p=dfs2(it,x);
            ret=merge(ret,p.x);
            Maxd=max(Maxd,p.y.y);
            tmp.pb(p.y.x+1);
        }
    }
    sort(tmp.begin(),tmp.end());
    reverse(tmp.begin(),tmp.end());
    if(tmp.size()==0)Maxd=0;
    else if(tmp.size()==1)Maxd=max(Maxd,tmp[0]);
    else Maxd=max(Maxd,tmp[0]+tmp[1]);
    if(!ret)ret=new node(0,n);
    add(ret,d[x],1);
    int Max2=query(root1,ret);
    int a=(Maxd+1)/2;
    //printf("%d %d %d\n",x,a,Max2);
    if(Max2>a){
        ans[Max2-a]=min(ans[Max2-a],Max2);
    }
    else{
        ans[0]=min(ans[0],a);
    }
    tmp.pb(0);
    return mp(ret,mp(tmp[0],Maxd));
}
void solve(){
//    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    Max=0;
    d[0]=-1;
    fill(ans,ans+n+10,1e9);
    root1=new node(0,n);
    root2=new node(0,n);
    dfs(1,0);
    dfs2(1,0);
    for(int i = 1;i<=n;i++){
        ans[i]=min(ans[i-1]+1,ans[i]);
        ans[i]=min(ans[i],Max);
    //    printf("%d ",ans[i]);
    }
    for(int i = n-1;i>=1;i--){
        ans[i]=min(ans[i],ans[i+1]);
    }
    for(int i = 1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
(k_1x+b)k_2+b=y

36
0123
0123 4567
*/