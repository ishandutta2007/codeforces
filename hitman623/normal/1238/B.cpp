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
int n,r;
void solve(){
	vi x;
    cin>>n>>r;
    x.resize(n);
    rep(i,0,n) cin>>x[i];
 	sort(all(x));
 	x.resize(unique(all(x))-x.begin());
    reverse(all(x));
    int cnt=0;
    rep(i,0,sz(x)){
    	if(x[i]-r*i>0) cnt++;
    }
    cout<<cnt<<endl;
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