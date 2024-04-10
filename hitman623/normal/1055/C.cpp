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
int la,ra,ta,lb,rb,tb,ans;
void solve(){
    cin>>la>>ra>>ta>>lb>>rb>>tb;
    int g=__gcd(ta,tb);
    int d=(la-lb)%g;
    if(d<0) d+=g;
    int l=d;
    int r=min(l+ra-la,rb-lb);
    ans=max(ans,r-l+1);
    l=g-d;
    r=min(l+rb-lb,ra-la);
    ans=max(ans,r-l+1);
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