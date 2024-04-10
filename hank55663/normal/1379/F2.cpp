#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct node{
    node *l,*r;
    int a,b;
    int ok;
    int Max,Min;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),Min(1e9),Max(0),ok(1){

    }
}*root;
void pull(node *n){
    n->ok=n->l->ok&&n->r->ok&&(n->l->Min>n->r->Max);
    n->Max=max(n->l->Max,n->r->Max);
    n->Min=min(n->l->Min,n->r->Min);
}
void build(node *n){
    if(n->a==n->b){
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void reviseMax(node *n,int x,int k){
    if(n->a==n->b){
        n->Max=k;
        if(n->Max<n->Min)n->ok=1;
        else n->ok=0;
        return ;
    }
    int mid=(n->a+n->b)/2;
    if(x<=mid)reviseMax(n->l,x,k);
    else reviseMax(n->r,x,k);
    pull(n);
}
void reviseMin(node *n,int x,int k){
    if(n->a==n->b){
        n->Min=k;
        if(n->Max<n->Min)n->ok=1;
        else n->ok=0;
        return ;
    }
    int mid=(n->a+n->b)/2;
    if(x<=mid)reviseMin(n->l,x,k);
    else reviseMin(n->r,x,k);
    pull(n);
}
set<int> s[400005];
void solve(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=2;i<=2*n+1;i++){
        if(i%2)s[i].insert(0);
        else s[i].insert(1e9);
    }
    root = new node(1,n);
    build(root);
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        x++;
        y++;
        if(s[x].find(y)==s[x].end()){
            s[x].insert(y);
        }
        else{
            s[x].erase(y);
        }
        if(x%2==0){
            y=*s[x].begin();
            x/=2;
            y/=2;
           // printf("add 1 %d %d\n",x,y);
            reviseMin(root,x,y);
        }
        else{
            y=*s[x].rbegin();

          //  printf("add 2 %d %d %d\n",x,y,s[x].size());
            x/=2;
            y/=2;
           // printf("add 2 %d %d\n",x,y);
            reviseMax(root,x,y);
        }
        if(root->ok)printf("YES\n");
        else printf("NO\n");
    }
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/