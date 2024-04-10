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
typedef long long LL;/*
int dp[1005][2005];
int dp2[1005][2005];
struct node{
    node *l,*r;
    int a,b;
    double Max;
    double tag;
    node(int _a,int _b):l(NULL),r(NULL){
        a=_a;
        b=_b;
        Max=0;
        tag=0;
    }
}*root;
double Max(node *n){
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
double a[2005];
void build(node *n){
    if(n->a==n->b){
        n->Max=a[n->a];
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
    pull(n);
}
void add(node *n,int l,int r,double k){
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return ;
    }
    if(n->a>r||n->b<l){
        return ;
    }
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
double query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return Max(n);
    }
    if(n->a>r||n->b<l){
        return 0;
    }
    push(n);
    double ret=max(query(n->l,l,r),query(n->r,l,r));
    pull(n);
    return ret;
}
void erase(node *n){
    if(n){
        erase(n->l);
        erase(n->r);
        delete n;
    }
}*/
LL S[100005];
void add(int x,LL add){
  //  printf("add:%d %d\n",x,add);
    for(int i=x;i<100005;i+=i&-i){
        S[i]+=add;
    }
}
LL query(int x){
    LL ret=0;
    for(int i=x;i>0;i-=i&-i){
        ret+=S[i];
    }
    return ret;
}
int main(){
    int n;
    scanf("%d",&n);
    LL c[100005];
    c[0]=0;
    LL t[100005];

    for(int i=1;i<=n;i++){
        scanf("%lld",&c[i]);
        add(i,c[i]-c[i-1]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&t[i]);
    }
    map<LL,set<int> > s;
    for(int i=n;i>=3;i--){
        s[c[i]-c[i-1]].insert(i);
    }
    if(c[1]!=t[1]||c[n]!=t[n]){
        printf("No\n");
    }
    else{
        for(int i=2;i<n;i++){
            LL x=query(i);
            if(x==t[i]){
                s[query(i+1)-query(i)].erase(i+1);
                continue;
            }
            else{
                LL target=t[i]-query(i-1);
                int r;
          /*      while(!s[target].empty()){
                    r=*s[target].begin();
                    if(r>i)
                    break;
                    s[target].erase(r);
                }*/
                if(s[target].empty()){
                    printf("No\n");
                    return 0;
                }
                else{
                    int r=*s[target].begin();
                    LL x=query(i+1)-query(i);
                    LL xx=query(i);
                    add(i,t[i]-xx);
                    add(r,xx-t[i]);
                    c[i]=t[i];
                //    printf("%d %d %d\n",xx,query(i),t[i]);
                    assert(query(i)==t[i]);
                    s[target].erase(r);
                    if(r!=i+1){
                        s[query(r)-query(r-1)].insert(r);
                        s[x].erase(i+1);
                    }
                }
            }
        }
        printf("Yes\n");
    }
}