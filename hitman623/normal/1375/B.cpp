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
int n,m,a[303][303];
void solve(){
	cin>>n>>m;
    rep(i,1,n+1){
    	rep(j,1,m+1){
    		cin>>a[i][j];
    	}
    }
    rep(i,1,n+1){
    	rep(j,1,m+1){
    		int cnt=0;
    		if(i-1>=1) cnt++;
    		if(i+1<=n) cnt++;
    		if(j-1>=1) cnt++;
    		if(j+1<=m) cnt++;
    		if(a[i][j]>cnt){
    			cout<<"NO"<<endl;
    			return;
    		}
    		a[i][j]=cnt;
    	}
    }
    cout<<"YES"<<endl;
    rep(i,1,n+1){
    	rep(j,1,m+1){
    		cout<<a[i][j]<<" ";
    	}
    	cout<<endl;
    }
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