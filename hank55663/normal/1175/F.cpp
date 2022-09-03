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
#define MXN 3005
#define next Next
int a[300005];
struct node{
    node *l,*r;
    int a,b;
    int Max;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),Max(0){
    }
}*root;
void pull(node *n){
    n->Max=max(n->l->Max,n->r->Max);
}
void build(node *n){
    if(n->a==n->b){
        n->Max=a[n->a];
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
    pull(n);
}
int query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r)return n->Max;
    if(n->b<l||n->a>r)return 0;
    return max(query(n->l,l,r),query(n->r,l,r));
}
vector<int> v[300005];
int l[300005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        v[a[i]].pb(i);
    }
    root = new node(1,n);
    build(root);
    int last=0;
    for(int i = 1;i<=n;i++){
        last=0;
        for(auto it:v[i]){
            l[it]=last;
            last=it;
        }
    }
    int Max=0;
    for(int i=1;i<=n;i++){
        Max=max(Max,l[i]);
        l[i]=Max;
    }
    int ans=0;
    for(int i =1;i<=n;i++){
        int x=i;
        while(x>l[i]){
            int y=query(root,x,i);
            if(i-x+1==y){
                ans++;
                x--;
            }
            else{
                x=i-y+1;
            }
        }
    }
    printf("%d\n",ans);
} 
/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/