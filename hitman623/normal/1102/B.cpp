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
int n,k,mx,col[5005];
vi a[5005];
void solve(){
	cin>>n>>k;
	rep(i,1,n+1){
		int x;
		cin>>x;
		a[x].pb(i);
	}
	rep(i,1,5001) mx=max(mx,sz(a[i]));
	if(mx>k){
		cout<<"NO"<<endl;
		return;
	}
	int cnt=1;
	rep(i,1,5001){
		for(auto j:a[i]){
			col[j]=cnt++;
			if(cnt>k) cnt=1;
		}	
	}
	cout<<"YES"<<endl;
	rep(i,1,n+1) cout<<col[i]<<" ";
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