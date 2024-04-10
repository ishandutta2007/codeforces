/**
 *    author:  gary
 *    created: 09.01.2022 20:52:59
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
const int MAXN=2e5+5;
const int MOD=1e9+7;
int a[MAXN],n,siz,sufmax[MAXN],dp[MAXN],dp2[MAXN],dp3[MAXN];
int bit[MAXN];
vector<int> pre[MAXN];
bool bad[MAXN];
void addi(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
void add(int pos,int val){
    while(pos<=siz){
        addi(bit[pos],val);
        pos+=pos&-pos;
    }
}
int query(int pos){
    int s=0;
    while(pos){
        addi(s,bit[pos]);
        pos-=pos&-pos;
    }
    return s;
}
void clear(){
    rb(i,0,siz) bit[i]=0;
}
void solve(){
    cin>>n;
    map<int,int> M;
    rb(i,1,n) cin>>a[i],M[a[i]]=1,dp3[i]=0,pre[i].clear();
    int cnt=0;
    for(auto ite=M.begin();ite!=M.end();ite++) ite->SEC=++cnt;
    rb(i,1,n) a[i]=M[a[i]];
    sufmax[n+1]=-INF;
    rl(i,n,1) sufmax[i]=max(sufmax[i+1],a[i]);
    siz=cnt;
    clear();
    rb(i,1,n){
        dp[i]=1;
        addi(dp[i],query(a[i]-1));
        add(a[i],dp[i]);
    }
    clear();
    rl(i,n,1){
        dp2[i]=1;
        addi(dp2[i],(query(siz)-query(a[i])+MOD)%MOD);
        add(a[i],dp2[i]);
    }
    int answer=0;
    rb(i,1,n){
        if(sufmax[i+1]>a[i]){
            bad[i]=0;
            int l=i+1,r=n+1;
            while(l<r-1){
                int mid=(l+r)>>1;
                if(sufmax[mid]>a[i]) l=mid;
                else r=mid;
            }
            pre[l].PB(i);
        }
        else{
            bad[i]=1;
        }
    }
    rb(i,1,n){
        if(!bad[i]) continue;
        M.clear();
        cnt=0;
        for(auto it:pre[i]) M[a[it]]=1;
        M[a[i]]=1;
        for(auto ite=M.begin();ite!=M.end();ite++) ite->SEC=++cnt;
        for(auto it:pre[i]) a[it]=M[a[it]];
        a[i]=M[a[i]];
        siz=cnt;
        clear();
        vector<int> v;
        for(auto it:pre[i]) v.PB(it);
        v.PB(i);
        sort(ALL(v));
        dp3[i]=1;
        add(a[i],dp3[i]);
        rl(j,(int)(v.size())-2,0){
            int now=v[j];
            dp3[now]=query(siz)-query(a[now])+MOD;
            dp3[now]%=MOD;
            add(a[now],dp3[now]);
        }
    }
    rb(i,1,n) addi(answer,1ll*dp[i]*(dp2[i]-dp3[i]+MOD)%MOD);
    cout<<answer<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}