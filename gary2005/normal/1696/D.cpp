/**
 *    author:  gary
 *    created: 25.06.2022 22:17:47
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
const int MAXN=250000+20;
int premin[MAXN],premax[MAXN],nexmin[MAXN],nexmax[MAXN],a[MAXN],dp[MAXN];
mp seg[MAXN][2];
int maxnex[MAXN][2];
const int N=1<<19;
struct sgt{
    int tree[N+N];
    sgt(){
        memset(tree,63,sizeof(tree));
    }
    void mo(int pos,int val){
        pos+=N-1;
        tree[pos]=val;
        pos>>=1;
        while (pos)
        {
            tree[pos]=min(tree[pos<<1],tree[pos<<1|1]);
            pos>>=1;
        }
    }
    int query(int a,int b,int now=1,int l=1,int r=N+1){
        if(r<=a||l>=b) return INF;
        if(r<=b&&l>=a) return tree[now];
        int mid=(l+r)>>1;
        return min(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
    }
}t[2];
vector<int> era[MAXN][2];
void Upd(int i){
    t[1].mo(i,dp[i]);
    t[0].mo(i,dp[i]);
    era[seg[i][0].second+1][1].PB(i);
    era[seg[i][1].second+1][0].PB(i);
}
void solve(){
    int n;
    cin>>n;
    rb(i,1,n) cin>>a[i],t[0].mo(i,INF),t[1].mo(i,INF),era[i][0].clear(),era[i][1].clear();
    if(n==1){
        cout<<0<<endl;
        return ;
    }
    stack<int> mx,mn;
    rb(i,1,n){
        while (!mx.empty()&&a[mx.top()]<a[i]){
            mx.pop();
        }
        while (!mn.empty()&&a[mn.top()]>a[i]){
            mn.pop();
        }
        premax[i]=mx.empty()? 0:mx.top();
        premin[i]=mn.empty()? 0:mn.top();
        mn.push(i);
        mx.push(i);
    }
    while (!mx.empty())
    {
        mx.pop();
    }
    while (!mn.empty()) {
        mn.pop();
    }
    rl(i,n,1){
        while (!mx.empty()&&a[mx.top()]<a[i]){
            mx.pop();
        }
        while (!mn.empty()&&a[mn.top()]>a[i]){
            mn.pop();
        }
        nexmax[i]=mx.empty()? n+1:mx.top();
        nexmin[i]=mn.empty()? n+1:mn.top();
        mn.push(i);
        mx.push(i);
    }
    rb(i,1,n) seg[i][0]=II(premin[i]+1,nexmin[i]-1),seg[i][1]=II(premax[i]+1,nexmax[i]-1);
    dp[1]=0;
    Upd(1);
    rb(i,2,n){
        rep(j,2) for(auto it:era[i][j]) t[j].mo(it,INF);
        dp[i]=min(t[0].query(seg[i][0].first,i+1),t[1].query(seg[i][1].first,i+1))+1;
        Upd(i);
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