/**
 *    author:  gary
 *    created: 18.09.2021 22:13:13
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
int n,dp[MAXN],cnt[MAXN];
vector<int> g[MAXN];
vector<int> rg[MAXN];
void solve(){
    scanf("%d",&n);
    rb(i,1,n) g[i].clear(),rg[i].clear();
    rb(i,1,n){
        int k;
        scanf("%d",&k);
        rep(j,k){
            int u;
            scanf("%d",&u);
            g[i].PB(u);
            rg[u].PB(i);
        }
        cnt[i]=k;
    }
    vector<int> tp;
    rb(i,1,n){
        if(cnt[i]==0){
            tp.push_back(i);
        }
    }
    int now=0;
    while(now<tp.size()){
        int Now=tp[now++];
        for(auto it:rg[Now]){
            cnt[it]--;
            if(cnt[it]==0){
                tp.PB(it);
            }
        }
    }
    if(tp.size()!=n) puts("-1");
    else{
        rep(i,tp.size()){
            dp[tp[i]]=1;
            for(auto it:g[tp[i]]){
                check_max(dp[tp[i]],dp[it]+(bool)(it>tp[i]));
            }
        }
        printf("%d\n",*max_element(dp+1,dp+1+n));
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();    
    return 0;
}