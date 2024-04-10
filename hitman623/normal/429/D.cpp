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
int n,a[100005];
ll f(int l,int r){
    if(l>=r) return 1LL*hell*hell;
    if(r-l+1<=4){
        ll ans=1LL*hell*hell;
        rep(i,l,r+1){
            rep(j,i+1,r+1){
                ans=min(ans,1LL*(i-j)*(i-j)+1LL*(a[i]-a[j])*(a[i]-a[j]));
            }
        }
        return ans;
    }
    int mx=(l+r)/2;
    ll d=min(f(l,mx),f(mx+1,r));
    vii strip;
    rep(i,l,r+1){
        if((i-mx)*(i-mx)<d){
            strip.pb({a[i],i});
        }
    }
    sort(all(strip));
    rep(i,0,sz(strip)){
        rep(j,i+1,sz(strip)){
            if((strip[j].x-strip[i].x)*(strip[j].x-strip[i].x)<d){
                d=min(d,1LL*(strip[j].x-strip[i].x)*(strip[j].x-strip[i].x)+1LL*(strip[j].y-strip[i].y)*(strip[j].y-strip[i].y));
            }
            else break;
        }
    }
    return d;
}
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    cout<<f(1,n)<<endl;
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