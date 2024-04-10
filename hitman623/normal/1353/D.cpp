#include <bits/stdc++.h>

#define ll          long long
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
int a[200005];
void solve(){
    int n;
    cin>>n;
    set<pair<int,pii>> st;
    st.insert({-n,{1,n}});
    rep(i,1,n+1){
        auto d=*(st.begin());
        st.erase(st.begin());
        int l=d.y.x;
        int r=d.y.y;
        int m=(r+l)/2;
        a[m]=i;
        if(m+1<=r) st.insert({m-r,{m+1,r}});
        if(l<=m-1) st.insert({l-m,{l,m-1}});
    }
    rep(i,1,n+1) cout<<a[i]<<" ";
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}