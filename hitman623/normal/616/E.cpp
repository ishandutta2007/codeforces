#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007LL
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
ll n,m;
ll f(ll x){
    if(x%2){
        return ((x%hell)*(((x+1)/2)%hell))%hell;
    }
    else{
        return (((x/2)%hell)*((x+1)%hell))%hell;
    }
}
ll cal(ll x,ll y){
    y=min(m,y);
    x=min(x,m);
    return (f(y)-f(x)+hell)%hell;
}
void solve(){
    cin>>n>>m;
    ll ans1=((n%hell)*(m%hell))%hell,ans=0;
    for(ll i=1;i*i<=n;++i){
        ll d=i;
        ans=(ans+d*cal(n/(d+1),n/d))%hell;
        if(n/d!=d){
            d=n/d;
            ans=(ans+d*cal(n/(d+1),n/d))%hell;
        }
    }
    cout<<(ans1-ans+hell)%hell;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}