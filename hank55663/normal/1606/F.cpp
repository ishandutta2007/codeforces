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
vector<int> v[200005];
vector<pii> query[200005];
struct node{
    node *l,*r;
    int val;
    int cnt;
    int Maxval;
    int Minval;
    int a,b;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),val(0),cnt(0){
        Maxval=0;
        Minval=0;
    }
};
LL Maxval(node *n){
    return n?n->Maxval+n->val-n->cnt*n->a:0;
}
LL Minval(node *n){
    return n?n->Minval+n->val-n->cnt*n->b:0;
}
void pull(node *n){
    n->Maxval=Maxval(n->l);
    n->Minval=Minval(n->r);
}
void push(node *n){
    if(!n->l){
        int mid=(n->a+n->b)/2;
        n->l=new node(n->a,mid);
        n->r=new node(mid+1,n->b);
    }
    n->l->cnt+=n->cnt;
    n->l->val+=n->val;
    n->r->cnt+=n->cnt;
    n->r->val+=n->val;
    n->val=0;
    n->cnt=0;
}
node *merge(node *a,node *b){
    if(!a||!b)return a?a:b;

    a->val+=b->val;
    a->cnt+=b->cnt;
    a->l=merge(a->l,b->l);
    a->r=merge(a->r,b->r);
    pull(a);
    delete b;
    return a;
}
int print;
void go(node *n){
 //   if(print)
//    printf("%d %d %d %d\n",n->a,n->b,Maxval(n),Minval(n));
    if(Maxval(n)<=0){
        n->val=1;
        n->cnt=0;
        n->l=n->r=NULL;
    }
    else if(Minval(n)>=1){
        return;
    }
    push(n);
    go(n->l);
    go(n->r);
    pull(n);
}
int qquery(node *n,int k){
    if(!n)return 0;
  //  if(print)
  //  printf("%d %d %d %d\n",n->val,n->cnt,n->a,n->b);
    int mid=(n->a+n->b)/2;
    
    if(k<=mid){
        return qquery(n->l,k)+n->val-n->cnt*k;   
    }
    else{
         return qquery(n->r,k)+n->val-n->cnt*k;   
    }
}
LL ans[200005];
node* dfs(int x,int f){
    node* res=new node(0,200000);
    for(auto it:v[x]){
        if(it!=f){
            res=merge(res,dfs(it,x));
        }
    }
    for(auto it:query[x]){
        ans[it.y]=qquery(res,it.x+1);
    }
    //    printf("%d %d\n",x,qquery(res,3));
    res->val++;
    // printf("%d %d\n",x,qquery(res,3));
    res->cnt++;
    // printf("%d %d\n",x,qquery(res,3));
    // if(x==3)print=1;
    // else print=0;
    go(res);
    // if(x==3)print=1;
   //  else print=0;
  //printf("%d %d\n",x,qquery(res,3));
  //print=0;
    return res;
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    int q;
    scanf("%d",&q);
    for(int i = 1;i<=q;i++){
        int u,k;
        scanf("%d %d",&u,&k);
        query[u].pb(mp(k,i));
    }
    dfs(1,0);
    for(int i  = 1;i<=q;i++){
        printf("%lld\n",ans[i]);
    }
}
int main(){
    int t=1;//00;//00;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/