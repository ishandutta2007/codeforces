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
#define index Index
#define MXN 1000000
vector<int> v[200005];
int l[200005],r[200005];
long long ans;
long long val[200005];
void dfs(int x){
    val[x]=0;
    for(auto it:v[x]){
        dfs(it);
        val[x]+=val[it];
    }
    if(val[x]<l[x]){
        ans++;
        val[x]=r[x];
    }
    if(val[x]>r[x])val[x]=r[x];
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 2;i<=n;i++){
        int p;
        scanf("%d",&p);
        v[p].pb(i);
    }
    for(int i = 1;i<=n;i++){
        scanf("%d %d",&l[i],&r[i]);
    }
    ans=0;
    dfs(1);
    printf("%lld\n",ans);
}
int main(){
 //   srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);
    //int res=0;
   
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}