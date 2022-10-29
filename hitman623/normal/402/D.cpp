#include <bits/stdc++.h>

#define ll          long long
#define pb          emplace_back
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
int n,m,a[5005],ans;
unordered_map<int,int> bad;
int f(int d){
    int ans=0;
    for(int j=2;j*j<=d;++j){
        if(d%j==0){
            while(d%j==0){
                if(bad.count(j)) ans--;
                else ans++;
                d/=j;
            }
        }
    }
    if(d>1){
        if(bad.count(d)) ans--;
        else ans++;
    }
    return ans;
}
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,m){
        int x;
        cin>>x;
        bad[x]=1;
    }
    for(int i=n-1;i>=0;i--){
        int g=0;
        rep(j,0,i+1){
            g=__gcd(g,a[j]);
        }
        if(f(g)<0){
            rep(j,0,i+1){
                a[j]/=g;
            }
        }
    }
    rep(i,0,n){
        ans+=f(a[i]);
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