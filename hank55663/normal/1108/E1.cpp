#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
//#define sqr(x) ((x)*(x))
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash
#define MAXN 605
struct node{
    node *l,*r;
    int tag;
    int Max;
    int a,b;
    node(int _a,int _b):l(NULL),r(NULL),tag(0),Max(0),a(_a),b(_b){}
}*root;
int a[100005];
int Max(node *n){
    return n->Max+n->tag;
}
void pull(node *n){
    n->Max=max(Max(n->l),Max(n->r));
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
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
void revise(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return ;
    }
    if(n->b<l||n->a>r){
        return ;
    }
    push(n);
    revise(n->l,l,r,k);
    revise(n->r,l,r,k);
    pull(n);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    vector<pair<int,pii> > v;
    pii p[305];
    for(int i=0;i<m;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        p[i]=mp(l,r);
        v.pb(mp(l,mp(l,r)));
        v.pb(mp(r+1,mp(l,r)));
    }
    root = new node(1,n);
    build(root);
    sort(v.begin(),v.end());
    int index=0;
    int cnt=0;
    int ans=-1;
    int ansi;
    for(int i=1;i<=n;i++){
        while(index!=v.size()&&v[index].x==i){
            if(v[index].x==v[index].y.x){
                revise(root,v[index].y.x,v[index].y.y,-1);
                cnt++;
            }
            else{
                revise(root,v[index].y.x,v[index].y.y,1);
                cnt--;
            }
            index++;
        }
        int large=Max(root),Min=a[i]-cnt;
        if(large-Min>ans){
            ans=large-Min;
            ansi=i;
        }
    }
    vector<int> anslist;
    for(int i=0;i<m;i++){
        if(p[i].x<=ansi&&p[i].y>=ansi)
        anslist.pb(i+1);
    }
    printf("%d\n",ans);
    printf("%d\n",anslist.size());
    for(auto it:anslist)
    printf("%d ",it);
}