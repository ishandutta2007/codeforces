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
int n,m,f[100005],cnt=0;
void solve(){
	cin>>n>>m;
	rep(_,0,m){
		int x;
		cin>>x;
		f[x]++;
		if(f[x]==1) cnt++;
		if(cnt==n){
			rep(i,1,n+1){
				f[i]--;
				if(f[i]==0) cnt--;
			}
			cout<<1; 
		}
		else cout<<0;
	}
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