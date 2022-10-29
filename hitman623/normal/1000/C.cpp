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
int n,ans[200005];
mi o,c;
set<int> s;
void solve(){
    cin>>n;
    rep(i,0,n){
        int l,r;
        cin>>l>>r;
        o[l]++;
        c[r]++;
        s.insert(l);
        s.insert(r);
    }
    vi v(all(s));
    int cur=0;
    rep(i,0,sz(v)){
        cur+=o[v[i]];
        ans[cur]++;
        cur-=c[v[i]];
        if(i<sz(v)-1){
            ans[cur]+=(v[i+1]-v[i]-1);
        }
    }
    rep(i,1,n+1){
        cout<<ans[i]<<" ";
    }
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