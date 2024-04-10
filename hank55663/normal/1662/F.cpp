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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct node{
    node *l,*r;
    int Max,Min;
    int a,b;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),Max(-1e9),Min(1e9){};
}*root;
void pull(node *n){
    n->Max=max(n->l->Max,n->r->Max);
    n->Min=min(n->l->Min,n->r->Min);
}
void build(node *n,int *a,int *b){
    if(n->a==n->b){
        n->Max=a[n->a];
        n->Min=b[n->a];
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a,b);
    build(n->r,a,b);
    pull(n);
}
vector<int> ans;
void queryMax(node *n,int l,int r,int a){
    if(n->a>=l&&n->b<=r){
        if(n->Max>=a){
            if(n->a==n->b){
            //      printf("q %d\n",n->a);
                ans.pb(n->a);
                n->Max=-1e9,n->Min=1e9;
            }
            else{
                queryMax(n->l,l,r,a);
                queryMax(n->r,l,r,a);
                pull(n);
            }
        }
        return;
    }
    if(n->b<l||n->a>r)return;
    queryMax(n->l,l,r,a);
    queryMax(n->r,l,r,a);
    pull(n);
}
void queryMin(node *n,int l,int r,int a){
    if(n->a>=l&&n->b<=r){
        if(n->Min<=a){
            if(n->a==n->b){
            //    printf("q %d\n",n->a);
                ans.pb(n->a);
                n->Max=-1e9,n->Min=1e9;
            }
            else{
                queryMin(n->l,l,r,a);
                queryMin(n->r,l,r,a);
                pull(n);
            }
        }
        return;
    }
    if(n->b<l||n->a>r)return;
    queryMin(n->l,l,r,a);
    queryMin(n->r,l,r,a);
    pull(n);
}
int dis[200005];
void solve(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    int x[200005],y[200005],p[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&p[i]);
        x[i]=i+p[i];
        y[i]=i-p[i];
        dis[i]=0;
    }
    root=new node(1,n);
    build(root,x,y);
    queue<int> q;
    q.push(a);
    dis[a]=0;
    queryMin(root,a,a,a);
    ans.clear();
    while(!q.empty()){
        int x=q.front();
        q.pop();
// printf("x:%d %d\n",x,dis[x]);
        queryMin(root,x,x+p[x],x);
        queryMax(root,x-p[x],x,x);
       
        for(auto it:ans){
        //    printf("%d ",it);
            dis[it]=dis[x]+1;
            q.push(it);
        }
      //  printf("\n");
        ans.clear();
    }
    printf("%d\n",dis[b]);
}
int main(){
  //  srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
1101011?0 5 1
001101?00 3 1
101000110 4 0
001011010 4 0
0101?01?? 3 3
00?1000?0 1 2
223413320
  1 1 131
*/