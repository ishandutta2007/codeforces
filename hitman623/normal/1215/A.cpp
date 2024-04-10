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
int a1,a2,k1,k2,n,mn,mx;
void solve(){
    cin>>a1>>a2>>k1>>k2>>n;
    int d=(k1-1)*a1+(k2-1)*a2;
    if(d<n) mn=n-d;
    rep(i,0,a1+1){
    	rep(j,0,a2+1){
    		if(i*k1+j*k2<=n) mx=max(mx,i+j);
    	}
    }
    cout<<mn<<" "<<mx<<endl;
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