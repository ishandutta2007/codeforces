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
#define MXN 300000
#define N 100005
struct node{
    node *l,*r;
    int a,b;
    int Min;
    int tag;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),Min(0),tag(0){}
}*root;
int Min(node *n){
    return n->Min+n->tag;
}
void pull(node *n){
    n->Min=min(Min(n->l),Min(n->r));
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
void build(node *n,int *a){
    if(n->a==n->b){
        n->Min=a[n->a];
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
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
int query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return Min(n);
    }
    if(n->b<l||n->a>r){
        return 1e9;
    }
    push(n);
    int res=min(query(n->l,l,r),query(n->r,l,r));
    pull(n);
    return res;
}
int belong[200005];
int main(){
    int a[3];
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    int n=a[0]+a[1]+a[2];
    vector<int> v[3];
    for(int i = 0;i<3;i++){
        for(int j=0;j<a[i];j++){
            int x;
            scanf("%d",&x);
            v[i].pb(x);
            belong[x]=i;
        }
        sort(v[i].begin(),v[i].end());
    }
    int num[200005];
    num[n+1]=v[2].size();
    for(int j =n;j>=1;j--){
        if(!v[2].empty()&&v[2].back()==j){
            v[2].pop_back();
            num[j]=num[j+1]-1;
        }
        else{
            num[j]=num[j+1]+1;
        }
    }
    root = new node(1,n+1);
    build(root,num);
    int x=n-v[0].size();
    for(int i = 1;i<=n;i++){
        if(belong[i]==2)x--;
    }
    int ans=n;
    for(int i = n;i>=0;i--){
        ans=min(ans,x+query(root,i+1,n+1));
     //   printf("%d %d\n",x,query(root,i+1,n+1));
        if(!v[0].empty()&&v[0].back()==i){
            add(root,1,i,-1);
            x++,v[0].pop_back();
        }
        else{
            if(belong[i]==1)
            x--;
        }
    }
    printf("%d\n",ans);
}
/*
5 4
8 1 0 3 0
0 0 1 3 8
1
*/