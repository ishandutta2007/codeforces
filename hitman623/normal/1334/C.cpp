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
#define hell        1000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,a[300005],b[300005];
void solve(){
    cin>>n;
    int mn=hell,s=0;
    rep(i,0,n) cin>>a[i]>>b[i];
    rep(i,0,n){
    	mn=min({mn,a[i],b[(i-1+n)%n]});
    	a[i]=max(0LL,a[i]-b[(i-1+n)%n]);
    	s+=a[i];
    }
    cout<<s+mn<<endl;
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