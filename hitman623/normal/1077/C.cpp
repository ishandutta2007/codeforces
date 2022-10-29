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
int n,a[200005],s;
multiset<int> st;
vi ans;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        s+=a[i];
        st.insert(a[i]);
    }
    rep(i,0,n){
        int d=s-a[i];
        if(d%2) continue;
        d/=2;
        st.erase(st.find(a[i]));
        if(st.count(d)) ans.pb(i);
        st.insert(a[i]);
    }
    cout<<sz(ans)<<endl;
    for(auto i:ans) cout<<i+1<<" ";
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