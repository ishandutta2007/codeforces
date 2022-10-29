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
vii v;
int n;
void solve(){
	v.clear();
	int f=1;
    cin>>n;
    rep(i,0,n){
    	int x,y;
    	cin>>x>>y;
    	v.pb({x,y});
    	if(x<y) f=0;
    }
    rep(i,1,n){
    	if(v[i].x<v[i-1].x) f=0;
    	else if(v[i].y<v[i-1].y) f=0;
    	else if(v[i].x==v[i-1].x and v[i].y!=v[i-1].y) f=0;
    	else if(v[i].x-v[i-1].x<v[i].y-v[i-1].y) f=0;
    }
    if(f) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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