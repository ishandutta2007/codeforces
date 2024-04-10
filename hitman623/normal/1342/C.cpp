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

void solve(){
    vi v;
    int a,b,q;
    cin>>a>>b>>q;
    int g=a*b/__gcd(a,b);
    if(a>b) swap(a,b);
    while(q--){
        int l,r,ans=0;
        cin>>l>>r;
        l=max(l,b);
        if(r<l){
            cout<<0<<" ";
            continue;
        }
        rep(i,0,b){
            int R=(r-i+g)/g;
            int L=(l-i-1+g)/g;
            ans+=max(0LL,R-L);
        }
        cout<<r-l+1-ans<<" ";
    }
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