#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define MXN 10005
#define less Less
#define N (1<<20)
typedef complex<double> C;
struct node{
    node *l,*r;
    int a,b;
    int Min;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL){

    }
}*root;
void pull(node *n){
    n->Min=min(n->l->Min,n->r->Min);
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
void revise(node *n,int x,int k){
    if(n->a==n->b){
        n->Min=k;
        return;
    }
    int mid=(n->a+n->b)/2;
    if(x<=mid){
        revise(n->l,x,k);
    }
    else{
        revise(n->r,x,k);
    }
    pull(n);
}
int query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return n->Min;
    }
    if(n->b<l||n->a>r)return 1e9;
    return min(query(n->l,l,r),query(n->r,l,r));
}
vector<int> v[300005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i = 1;i<=n;i++){
            v[i].clear();
        }
        root=new node(1,n);
        int a[300005],b[300005];
        for(int i = 1;i<=n;i++){
            scanf("%d",&a[i]);
            v[a[i]].pb(i);
        }
        build(root,a);
        for(int i = 1;i<=n;i++)
            reverse(v[i].begin(),v[i].end());
        int ok=1;
        for(int i = 1;i<=n;i++){
            scanf("%d",&b[i]);
            if(v[b[i]].empty()){
                ok=0;
            }
            else{
                int x=v[b[i]].back();
                v[b[i]].pop_back();
                int y=query(root,1,x);
               // printf("%d %d\n",x,y);
                if(b[i]!=y){
                    ok=0;
                }
                else{
                    revise(root,x,1e9);
                }
            }
        }
        if(ok){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}
/*
1 
2 6 
3 5 
4
*/