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
int n,a[10001];
void solve(){
	memset(a,0,sizeof a);
    cin>>n;
    n*=4;
    rep(i,0,n){
    	int x;
    	cin>>x;
    	a[x]++;
    }
    vii v;
    rep(i,1,10001){
    	if(!a[i]) continue;
    	if(a[i]%2){
    		cout<<"NO"<<endl;
    		return;
    	}
    	a[i]/=2;
    	v.pb({i,a[i]});
    }
    int area=v[0].x*v.back().x;
    if(sz(v)%2 and (v[sz(v)/2].y%2 or v[sz(v)/2].x*v[sz(v)/2].x!=area)){
    	cout<<"NO"<<endl;
    	return;
    }
    rep(i,0,sz(v)/2){
    	if(v[i].y!=v[sz(v)-1-i].y){
    		cout<<"NO"<<endl;
    		return;
    	}
    	if(v[i].x*v[sz(v)-1-i].x!=area){
    		cout<<"NO"<<endl;
    		return;
    	}
    }
    cout<<"YES"<<endl;
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