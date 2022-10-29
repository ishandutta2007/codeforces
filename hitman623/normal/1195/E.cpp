#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,a,b,mat[3003][3003],g0,x,y,z,ans;
vector<vi> vv;
vi get(vi v, int n, int k) {
    vi res;
    deque<int> dq(k); 
    rep(i,0,k){
        while ((!dq.empty()) && v[i] >= v[dq.back()]) 
            dq.pop_back();
        dq.push_back(i); 
    }
    rep(i,k,n){
        res.pb(v[dq.front()]);
        while ((!dq.empty()) && dq.front() <= i - k)
            dq.pop_front();
        while ((!dq.empty()) && v[i] >= v[dq.back()]) 
            dq.pop_back(); 
        dq.push_back(i); 
    }
    res.pb(v[dq.front()]); 
    return res;
} 
void solve(){
    cin>>n>>m>>a>>b;
    cin>>g0>>x>>y>>z;
    rep(i,0,n){
        rep(j,0,m){
            mat[i][j]=-g0;
            g0=(g0*x+y)%z;
        }
    }
    rep(i,0,n){
        vi v;
        rep(j,0,m){
            v.pb(mat[i][j]);
        }
        vv.pb(get(v,m,b));
    }
    rep(i,0,m-b+1){
        vi v;
        rep(j,0,n){
            v.pb(vv[j][i]);
        }
        vi res=get(v,n,a);
        for(auto j:res) ans-=j;
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}