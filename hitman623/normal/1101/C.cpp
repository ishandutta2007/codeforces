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
int n,ans[100005];
vector<pair<pii,int>> v;
void solve(){
    cin>>n;
    v.clear();
    rep(i,0,n){
    	int x,y;
    	cin>>x>>y;
    	v.pb({{x,y},i});
    }
    sort(all(v));
    int mx=v[0].x.x;
    rep(i,0,sz(v)){
    	if(v[i].x.x>mx){
    		rep(j,0,i){
    			ans[v[j].y]=1;
    		}
    		rep(j,i,sz(v)){
    			ans[v[j].y]=2;
    		}
    		rep(j,0,n) cout<<ans[j]<<" ";
    		cout<<endl;
    		return;
    	}
    	mx=max(mx,v[i].x.y);
    }
    cout<<-1<<endl;
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