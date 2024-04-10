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
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int S[1048576];
void add(int x,int k){
    if(x==0)return;
    for(int i = x;i<1048576;i+=i&-i){
        S[i]+=k;
    }
}
int query(int x){
    int res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
int query2(int x){
    int sum=0;
    int res=0;
    for(int i = 19;i>=0;i--){
        if(sum+S[res+(1<<i)]<x){
            res+=1<<i;
            sum+=S[res];
        }
    }
    return res+1;
}
vector<pair<pii,int> > qquery[1000005];
int ans[1000005];
int m[1000005];
unordered_set<int> s[1000005];
int a[1000005];
vector<int> v[1000005];
void dfs(int x,int f){
    add(m[a[x]],-1);
    if(m[a[x]])
    s[m[a[x]]].erase(a[x]);
    m[a[x]]++;
    s[m[a[x]]].insert(a[x]);
    add(m[a[x]],1);
    for(auto it:qquery[x]){
        int num=it.x.y+query(it.x.x-1);
       // printf("%d %d %d\n",it.y,num,query(1048575));
        if(num>query(1048575))ans[it.y]=-1;
        else ans[it.y]=*s[query2(num)].begin();
    }
    for(auto it:v[x]){
        if(it!=f)dfs(it,x);
    }
    s[m[a[x]]].erase(a[x]);
    add(m[a[x]],-1);
    m[a[x]]--;
    add(m[a[x]],1);
    if(m[a[x]]){
        s[m[a[x]]].insert(a[x]);
    }
}
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i = 1;i<=n;i++)v[i].clear(),qquery[i].clear();
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    for(int i = 2;i<=n;i++){
        int x;
        scanf("%d",&x);
        v[x].pb(i);
    }
    for(int i = 1;i<=q;i++){
        int v,l,k;
        scanf("%d %d %d",&v,&l,&k);
        qquery[v].pb(mp(mp(l,k),i));
    }
    dfs(1,0);
    for(int i = 1;i<=q;i++)printf("%d ",ans[i]);
    printf("\n");
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/