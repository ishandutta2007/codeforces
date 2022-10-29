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
int n,a[1001],f[1001];
void solve(){
	cin>>n;
	rep(i,0,n) cin>>a[i];
	vi res;
	rep(i,0,2*n){
		rep(j,0,n+1) f[j]=0;
		rep(j,0,n) f[a[j]]++;
		int mex=0;
		rep(j,0,n+1){
			if(f[j]==0){
				mex=j;
				break;
			}
		}
		if(mex==n){
			int pos=-1;
			rep(j,0,n){
				if(a[j]!=j){
					pos=j;
					break;
				}
			}
			if(pos==-1) break;
			res.pb(pos);
			a[pos]=mex;
		}
		else{
			res.pb(mex);
			a[mex]=mex;
		}
	}
	cout<<sz(res)<<endl;
	for(auto i:res) cout<<i+1<<" ";
	cout<<endl;
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