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
int n,k,ans;
string s;
int freq[200005][26];
void solve(){
	cin>>n>>k;
	cin>>s;
	rep(i,0,n){
		if(i){
			rep(j,0,26){
				freq[i][j]=freq[i-1][j];
			}			
		}
		freq[i][s[i]-'a']++;
	}
	rep(i,0,26){
		int cur=0,cnt=0;
		while(cur<n){
			if(cur+k-1<n and freq[cur+k-1][i]-(cur?freq[cur-1][i]:0)==k) cur=cur+k,cnt++;
			else cur++;
		}
		ans=max(ans,cnt);
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