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
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n;
map<int,vi> a;
vii ranges;
void solve(){
    cin>>n;
    rep(i,1,n+1){
    	int x;
    	cin>>x;
    	a[x].pb(i);
    }
    for(auto i:a){
    	ranges.pb({i.y[0],i.y.back()});
    }
    sort(all(ranges));
    int last=1,ans=1;
    for(auto i:ranges){
    	if(i.x>last) ans=(ans*2LL)%hell;
    	last=max(i.y,last);
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