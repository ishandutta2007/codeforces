/**
 *    author:  gary
 *    created: 21.04.2022 10:00:52
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
const int MAXN=5e5+10;
int dp[MAXN],n,a[MAXN],ord[MAXN];
LL p[MAXN];
struct BIT
{
    int tree[MAXN];
    void clear(){fill(tree,tree+n+2,-INF);}
    int query(int pos){
        int s=-INF;
        while (pos)
        {
            check_max(s,tree[pos]);
            pos-=pos&-pos;
        }
        return s;
    }
    void add(int pos,int s){
        while (pos<=n+1){
            check_max(tree[pos],s);
            pos+=pos&-pos;
        }
    }
}t0,t1;
map<LL,int> best;
void add(int i){
    if(best.find(p[i])==best.end()) best[p[i]]=dp[i];
    else check_max(best[p[i]],dp[i]);
    t0.add(ord[i],dp[i]-i);
    t1.add(n+1-ord[i]+1,dp[i]+i);
}
void ask(int i){
    dp[i]=-INF;
    if(best.find(p[i])!=best.end()) check_max(dp[i],best[p[i]]);
    check_max(dp[i],t0.query(ord[i]-1)+i);
    check_max(dp[i],t1.query(n+1-ord[i])-i);
}
void solve(){
    best.clear();
    cin>>n;
    t0.clear(),t1.clear();
    vector<pair<LL,int> > v;
    LL presum=0;
    v.PB(II(0,0));
    rb(i,1,n) cin>>a[i],presum+=a[i],v.PB(II(presum,i)),p[i]=presum;
    int cnt=0;
    sort(ALL(v));
    presum=-1e18;
    for(auto it:v){
        cnt+=presum!=it.first;
        presum=it.first;
        ord[it.second]=cnt;
    }
    // rb(i,0,n) cout<<ord[i]<<endl;
    dp[0]=0;
    add(0);
    rb(i,1,n){
        ask(i);
        add(i);
    }
    cout<<dp[n]<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}