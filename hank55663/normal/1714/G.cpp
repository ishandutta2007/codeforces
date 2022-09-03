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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<pair<int,pii> > v[200005];
LL ans[200005];
LL d[200005];
map<LL,int> s;
void dfs(int x,int f,LL a,LL b){
    s[b]=d[x]=d[f]+1;;
    ans[x]=prev(s.upper_bound(a))->y-1;
    for(auto it:v[x]){
        dfs(it.x,x,a+it.y.x,b+it.y.y);
    }
    s.erase(b);
}
void solve(){
    int n;
    scanf("%d ",&n);
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 2;i<=n;i++){
        int p,a,b;
        scanf("%d %d %d",&p,&a,&b);
        v[p].pb(mp(i,mp(a,b)));
    }
    dfs(1,0,0,0);
    for(int i = 2;i<=n;i++)printf("%lld ",ans[i]);
    printf("\n");
}
int main(){
    int t=1;00000000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    
}
/*
*/