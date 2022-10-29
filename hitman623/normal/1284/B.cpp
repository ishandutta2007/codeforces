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
int n,freq[1000006];
vi s[100005],v[2];
void solve(){
    cin>>n;
    rep(i,0,n){
    	int l;
    	cin>>l;
    	rep(j,0,l){
    		int x;
    		cin>>x;
    		s[i].pb(x);
    	}
    	int f=0;
    	rep(j,1,l){
    		if(s[i][j]>s[i][j-1]){
    			f=1;
    		}
    	}
    	if(f) v[0].pb(i);
    	else v[1].pb(i);
    }
    int ans=n*n;
    for(auto i:v[1]){
    	freq[s[i].back()]++;
    }
    for(int i=1000000;i>=0;i--) freq[i]+=freq[i+1];
	for(auto i:v[1]) ans-=freq[s[i][0]];
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