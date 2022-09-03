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
vector<int> v[505];
int c[1000005];
int mod=998244353;
set<int> okcut;
struct node{
    node *l,*r;
    int a,b;
    int Min;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b){

    }
}*root;
void pull(node *n){
    n->Min=min(n->l->Min,n->r->Min);
}
void build(node *n,int *c){
    if(n->a==n->b){
        n->Min=c[n->a];
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,c);
    build(n->r,c);
    pull(n);
}
int query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return n->Min;
    }
    if(n->b<l||n->a>r)return 1e9;
    return min(query(n->l,l,r),query(n->r,l,r));
}
unordered_map<LL,LL> dp;
LL DP(int l,int r){
   // printf("%d %d\n",l,r);
   // getchar();
    if(l>=r)return 1;
    if(dp.find(l*1000005ll+r)!=dp.end())return dp[l*1000005ll+r];
    LL suml=0,sumr=0;
    int Min=query(root,l,r);
    int it=l-1;
    while(it<v[Min].front()){
        suml+=DP(l,it)*DP(it+1,v[Min].front()-1);
        suml%=mod;
        it=v[c[it+1]].back();
    }
    it=v[Min].back();
    while(it<=r){
        sumr+=DP(v[Min].back()+1,it)*DP(it+1,r);
        sumr%=mod;
        if(it==r)break;
        it=v[c[it+1]].back();
    }
  //  printf("?\n");
    LL res=suml*sumr%mod;
    for(int i =1;i<v[Min].size();i++){
    //    printf("!! %d %d\n",v[Min][i-1]+1,v[Min][i]-1);
        res*=DP(v[Min][i-1]+1,v[Min][i]-1);
        res%=mod;
    }
    dp[l*1000005ll+r]=res;
   // printf("%d %d %d %lld %lld\n",l,r,res,suml,sumr);
    return dp[l*1000005ll+r];
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=m;i++){
        scanf("%d",&c[i]);
        v[c[i]].pb(i);
    }
    root = new node(1,m);
   // printf("!\n");
    build(root,c);
    //printf("?\n");
    for(int i = 1;i<=n;i++){
        int x=query(root,v[i].front(),v[i].back());
        if(x!=i){
            printf("0\n");
            return 0;
        }
    }

    printf("%lld\n",DP(1,m));
}
/*
1 
2 6 
3 5 
4
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

if(c[n-(r-l+1)]==)
dp[l][r]
dp[]
1 3 4 2
*/