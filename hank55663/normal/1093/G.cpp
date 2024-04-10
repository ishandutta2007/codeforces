/*#include<utility>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iostream>
#include<string.h>*/
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL ;
int k;
struct node{
    vector<int> Max;
    node *l,*r;
    int a,b;
    node(int _a,int _b):l(NULL),r(NULL){
        Max.resize(1<<k);
        a=_a;
        b=_b;
    }
}*root;
int p[200005][6];
void pull(node *n){
    for(int i=0;i<(1<<k);i++){
        n->Max[i]=max(n->l->Max[i],n->r->Max[i]);
    }
}
void Set(int x,vector<int> &v){
    for(int i=0;i<(1<<k);i++){
        int ans=0;
        for(int j=0;j<k;j++){
            if(i&(1<<j))
                ans-=p[x][j];
            else
                ans+=p[x][j];
        }
        v[i]=ans;
    }
}
void build(node *n=root){
    if(n->a==n->b){
        Set(n->a,n->Max);
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
    pull(n);
}
void revise(node *n,int i){
    if(n->a==n->b){
        Set(n->a,n->Max);
        return ;
    }
    int mid=(n->a+n->b)/2;
    if(i<=mid){
        revise(n->l,i);
    }
    else{
        revise(n->r,i);
    }
    pull(n);
}
vector<int> Maxv(const vector<int> &v1,const vector<int> &v2){
    vector<int> ret;
    for(int i=0;i<v1.size();i++)
    ret.pb(max(v1[i],v2[i]));
    return ret;
}
vector<int> query(node *n,int l,int r){
   // printf("%d %d %d %d\n",n->a,n->b,l,r);
    if(l<=n->a&&n->b<=r){
        return n->Max;
    }
    if(n->b<l||n->a>r){
        return vector<int>(1<<k,-1e9);
    }
    return Maxv(query(n->l,l,r),query(n->r,l,r));
}
int main(){
    int n;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        for(int j=0;j<k;j++)
            scanf("%d",&p[i][j]);
    root=new node(1,n);
    build();
    int q;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x;
            scanf("%d",&x);
            for(int i=0;i<k;i++)
                scanf("%d",&p[x][i]);
            revise(root,x);
        }
        else{
            int l,r;
            scanf("%d %d",&l,&r);
            vector<int> res=query(root,l,r);
            int ans=0;
            for(int i=0;i<(1<<k);i++){
                int inv=((1<<k)-1)^i;
                ans=max(ans,res[i]+res[inv]);
            }
            printf("%d\n",ans);
        }
    }
}
/*
0 1 0
0 0 1
1 0 1
*/