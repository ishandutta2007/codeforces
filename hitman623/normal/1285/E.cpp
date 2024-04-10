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
int n;
vii v;
vi vv;
mi mp;
void solve(){
	int ans=0;
	v.clear();
	vv.clear();
	mp.clear();
	cin>>n;
	rep(i,0,n){
		int l,r;
		cin>>l>>r;
		l*=2;
		r*=2;
		mp[l-1]+=0;
		mp[l]++;
		mp[l+1]+=0;
		mp[r-1]+=0;
		mp[r]+=0;
		mp[r+1]--;
		v.pb({l,r});
	}
	int cur=0,last=-1,cnt=-1;
	for(auto &i:mp){
		cur+=i.y;
		i.y=cur;
		if(cur==1 and last!=1) vv.pb(i.x);
		if(cur==0 and last!=0) cnt++;
		last=cur;
	}
	for(auto i:v){
		int l=i.x;
		int r=i.y;
		int w=upper_bound(all(vv),r)-lower_bound(all(vv),l);
		ans=max(ans,cnt+w-(mp[l]==1)-(mp[r]==1));
	}
	cout<<ans<<endl;
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