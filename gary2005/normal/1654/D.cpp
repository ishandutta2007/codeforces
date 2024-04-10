/**
 *    author:  gary
 *    created: 20.03.2022 19:29:12
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2e5+10;
const int MOD=998244353;
int n;
vector<pair<int,mp> > g[MAXN];
vector<int> fact[MAXN];
bool prime[MAXN];
int cnt[MAXN];
int mx[MAXN];
void dfs(int now,int pre){
    for(auto it:g[now]){
        if(it.first!=pre){
            int x,y;
            x=it.second.first;
            y=it.second.second;
            for(auto it:fact[x]){
                cnt[it]++;
            }
            for(auto it:fact[y]){
                cnt[it]--;
                check_max(mx[it],-cnt[it]);
            }
            dfs(it.first,now);
            for(auto it:fact[y]){
                cnt[it]++;
            }
            for(auto it:fact[x]){
                cnt[it]--;
            }
        }
    }
}
int ans2=0;
int quick(int k1,int k2){
    int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%MOD)if(k2&1)k3=1LL*k3*k1%MOD;return k3;
}
int inv(int A){return quick(A,MOD-2);}
void dfs2(int now,int pre,int val){
    (ans2+=val)%=MOD;
    for(auto it:g[now]) if(it.first!=pre){
        dfs2(it.first,now,1ll*it.second.first*val%MOD*inv(it.second.second)%MOD);
    }
}
void solve(){
    ans2=0;
    cin>>n;
    rb(i,1,n) g[i].clear();
    rb(T,1,n-1){
        int i,j,x,y;
        cin>>i>>j>>x>>y;
        g[j].PB(II(i,II(x,y)));
        g[i].PB(II(j,II(y,x)));
    }
    dfs(1,0);
    int ans=1;
    rb(i,1,n){
        for(auto it:g[i]){
            int y=it.second.second;
            for(auto it:fact[y]){
                while (mx[it])
                {
                    mx[it]--;
                    ans=1ll*ans*it%MOD;
                }
            }
        }
    }
    dfs2(1,0,ans);
    cout<<ans2<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=2;i<=200000;i++){
        if(!prime[i]){
            for(int j=i;j<=200000;j+=i){
                int now=j;
                prime[j]=1;
                while (now%i==0){
                    fact[j].PB(i);
                    now/=i;
                }
            }
        }
    }
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}