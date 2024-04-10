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
#define MXN 1500
struct node{
    node *l,*r;
    int a,b;
    int Max;
    int Min;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL){

    }
}*root,*root2;
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
void pull(node *n){
    n->Max=max(n->l->Max,n->r->Max);
    n->Min=min(n->l->Min,n->r->Min);
}
void add(node *n,int x,int w){
    if(n->a==n->b){
        n->Max=w;
        return ;
    }
    int mid=(n->a+n->b);
    if(x<=mid){
        add(n->l,x,w);
    }
    else{
        add(n->r,x,w);
    }
    pull(n);
}
int queryMax(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return n->Max;
    }
    if(n->b<l||n->a>r){
        return 0;
    }
    return max(queryMax(n->l,l,r),queryMax(n->r,l,r));
}
int queryMin(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return n->Min;
    }
    if(n->b<l||n->a>r){
        return 1e9;
    }
    return min(queryMin(n->l,l,r),queryMin(n->r,l,r));
}
vector<int> v[300005];
int l[300005];
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d",&n);
        root = new node(1,n);
        build(root);
        int a[300005];
        set<int> s;
        for(int i = 1;i<=n;i++)
            v[i].clear();
        for(int i = 1;i<=n;i++){
            scanf("%d",&a[i]);
            s.insert(a[i]);
            v[a[i]].pb(i);
        }
        vector<int> tmp(s.begin(),s.end());
        int ans=1e9;
        for(int i = 0;i<tmp.size();i++){
            int r=v[tmp[i]].back();
            int k=i+1;
            while(k!=tmp.size()&&v[tmp[k]][0]>r){
                r=v[tmp[k]].back();
                k++;
            }
            ans=min(ans,(int)tmp.size()-k+i);
            //printf("%d %d\n",i,k);
            i=k-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}