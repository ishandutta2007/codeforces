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
string a,b;
int n;
vi zo,oz;
void solve(){
	cin>>n>>a>>b;
	rep(i,0,n){
		if(a[i]!=b[i]){
			if(a[i]=='a') zo.pb(i);
			else oz.pb(i);
		}
	}
	if((sz(zo)+sz(oz))%2){
		cout<<-1<<endl;
		return;
	}
	vii v;
	while(sz(zo)>1){
		int x=zo.back();
		zo.pop_back();
		int y=zo.back();
		zo.pop_back();
		v.pb({x,y});
	}
	while(sz(oz)>1){
		int x=oz.back();
		oz.pop_back();
		int y=oz.back();
		oz.pop_back();
		v.pb({x,y});
	}
	if(sz(oz) and sz(zo)){
		v.pb({oz[0],oz[0]});
		v.pb({oz[0],zo[0]});
	}
	cout<<sz(v)<<endl;
	for(auto i:v) cout<<i.x+1<<" "<<i.y+1<<endl;
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