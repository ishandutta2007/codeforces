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

int n,k,a[100005];
int ans;
set<int> s;
void go(){
    cout<<k<<endl;
    rep(i,0,k){
        cout<<i<<" ";
    }
    exit(0);
}
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        cin>>a[i];
        a[i]%=k;
        int g=__gcd(a[i],k);
        s.insert(g);
    }
    vi v(all(s));
    rep(i,0,sz(v)){
        ans=__gcd(ans,v[i]);
    }
    if(ans==1) go();
    else{
        cout<<k/ans<<endl;
        rep(i,0,k){
            if(i%ans==0) cout<<i<<" ";
        }
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