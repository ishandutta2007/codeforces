#pragma GCC optimize("Ofast") 
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
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
LL S[500005];
void add(int x,int a){
    for(int i=x;i<500005;i+=i&-i){
        S[i]+=a;
    }
}
LL query(int x){
    LL res=0;
    for(int i=x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
struct node{
    node *l,*r;
    int a,b;
    LL Min;
    LL tag;
    node(int _a,int _b):l(NULL),r(NULL){
        a=_a;
        b=_b;
        Min=1e18;
        tag=0;
    }
}*root;
void build(node *n){
    if(n->a==n->b)return;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
LL Min(node *n){
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
void Set(node *n,int x,LL k){
    if(n->a==n->b){
        n->Min=k;
        n->tag=0;
        return;
    }
    push(n);
    int mid=(n->a+n->b)/2;
    if(x<=mid)
    Set(n->l,x,k);
    else
    Set(n->r,x,k);
    pull(n);
}
void add(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return ;
    }
    if(n->b<l||n->a>r)
    return ;
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
int loc[500005];
map<int,vector<int> > qu; 
int dfs(node *n){
 //   printf("a:%d b:%d %d\n",n->a,n->b,Min(n));
    if(Min(n)>=0){
        return 0;
    }
    if(n->a==n->b)return 1;
    push(n);
    int ret=dfs(n->l)+dfs(n->r);
    pull(n);
    return ret;
}
int main(){
    int q;
    scanf("%d",&q);
    vector<pair<char,int> > v;
    v.pb(mp('+',0));
    vector<pii> num;
    num.pb(mp(0,0));
    for(int i=1;i<=q;i++){
        char c;
        int x;
        scanf( " %c %d",&c,&x);
        v.pb(mp(c,x));
        if(c=='+')
        num.pb(mp(x,i));
        //printf("%c %d\n",c,x);
    }
    sort(num.begin(),num.end());
    for(int i=1;i<num.size();i++){
        loc[num[i].y]=i;
        qu[num[i].x].pb(i);
    }
    for(auto &it:qu){
        reverse(it.y.begin(),it.y.end());
    }
    root = new node(1,num.size()-1);
    int R=num.size()-1;
    build(root);
    int sum=0;
    for(int i=1;i<=q;i++){
     //   printf("%d\n",i);
        char c;
        c=v[i].x;
        if(c=='+'){
            sum++;
            int x;
            x=v[i].y;
            int index=loc[i];
            LL val=query(index-1)*2-x;
           // printf("%d %d %d\n",x,query(index-1),val);
            add(root,index+1,R,x*2);
            Set(root,index,val);
            add(index,x);
        }
        else{
            sum--;
            int x;
            x=v[i].y;
            int index=qu[x].back();
            qu[x].pop_back();
            add(root,index+1,R,-x*2);
            Set(root,index,1e18);
            add(index,-x);
        }
        //printf("%d\n",root);
        printf("%d\n",sum-dfs(root));
    }
}