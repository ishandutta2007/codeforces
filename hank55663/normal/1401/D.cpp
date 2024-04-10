#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define LL long long
#define pii pair<int,int>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
vector<int> v[100005];
LL n;
vector<LL> ans;
int Size[100005];
void dfs(int x,int f){
    Size[x]=1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            Size[x]+=Size[it];
            ans.pb(Size[it]*(n-Size[it]));
        }
    }
}
int mod=1e9+7;
void solve(){
    scanf("%lld",&n);
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    ans.clear();
    dfs(1,0);
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    int m;
    scanf("%d",&m);
    vector<int> k;
    for(int i =0;i<m;i++){
        int x;
        scanf("%d",&x);
        k.pb(x);
    }
    while(k.size()<n-1)k.pb(1);
    sort(k.begin(),k.end());
    while(k.size()>n-1){
        LL x=k.back();
        k.pop_back();
        k.back()=k.back()*x%mod;
    }
    reverse(k.begin(),k.end());
    LL res=0;
    for(int i=0;i<n-1;i++){
        res+=k[i]*(ans[i]%mod)%mod;
        res%=mod;
    }
    printf("%lld\n",res);
}
int main()
{
    int t;
    scanf("%d",&t);
    int T=1;
    while(t--){
        solve();
    }
}