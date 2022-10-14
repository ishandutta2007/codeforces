/**
 *    author:  gary
 *    created: 03.06.2022 22:30:50
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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<LL> a(n+1,0);
    rb(i,1,n) cin>>a[i];
    rb(i,1,n) {
        int bi;
        cin>>bi;
        a[i]-=bi;
        a[i]+=a[i-1];
    }
    set<int> notzero;
    rb(i,1,n) if(a[i]!=0) notzero.insert(i);
    queue<int> q;
    vector<vector<int> > g(n+1);
    rb(i,1,m){
        int l,r;
        cin>>l>>r;
        g[r].PB(l-1);
        g[l-1].PB(r);
    }
    if(a[n]!=0){
        cout<<"NO\n";
        return;
    }
    rb(i,0,n) if(a[i]==0) q.push(i);
    while (!q.empty()){
        int now=q.front();
        q.pop();
        for(auto it:g[now]) if(notzero.find(it)==notzero.end()){
            auto ite=notzero.lower_bound(min(it,now));
            while (ite!=notzero.end()&&*ite<=max(it,now)){
                q.push(*ite);
                ite=notzero.erase(ite);
            }
        }
    }
    if(notzero.size()) cout<<"NO\n";
    else cout<<"YES\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}