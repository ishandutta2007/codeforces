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
#define index Index
vector<int> v[100005];
struct node{
    node *l,*r;
    int Minsuf;
    int sum;
    int a,b;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),Minsuf(0),sum(0){

    }
}*root;
void pull(node *n){
    n->sum=n->l->sum+n->r->sum;
    n->Minsuf=min(n->r->Minsuf,n->l->Minsuf+n->r->sum);
}
void build(node *n){
    if(n->a==n->b)return;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void add(node *n,int x,int w){
    if(n->a==n->b){
        n->sum+=w;
        n->Minsuf=min(0,n->sum);
        return;
    }
    int mid=(n->a+n->b)/2;
    if(x<=mid)add(n->l,x,w);
    else add(n->r,x,w);
    pull(n);
}
LL sum[100005];
int k[100005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[100005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        add(root,a[i],1);
    }
    for(int i = 0;i<m;i++){
        sum[i]=0;
        v[i].clear();
    }
    sort(a,a+n);
    for(int i = 0;i<m;i++){
        scanf("%d",&k[i]);
        for(int j =0;j<k[i];j++){
            int x;
            scanf("%d",&x);
            v[i].pb(x);
            sum[i]+=x;
        }
        add(root,(sum[i]-1)/k[i]+1,-1);
    }
    for(int i = 0;i<m;i++){
        add(root,(sum[i]-1)/k[i]+1,1);
        for(auto it:v[i]){
            add(root,(sum[i]-1-it)/(k[i]-1)+1,-1);
            if(root->Minsuf<0)printf("0");
            else printf("1");
      add(root,(sum[i]-1-it)/(k[i]-1)+1,1);
        }
        add(root,(sum[i]-1)/k[i]+1,-1);
    }
    printf("\n");
    for(int i = 0;i<n;i++)add(root,a[i],-1);
    for(int i = 0;i<m;i++){
        add(root,(sum[i]-1)/k[i]+1,1);
    }
}
int main(){
    root=new node(1,100000);
    build(root);
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
8876666554222188 
*/