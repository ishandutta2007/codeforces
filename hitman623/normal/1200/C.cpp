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
int n,m,q;
void solve(){
    cin>>n>>m>>q;
    int g=__gcd(n,m);
    int a=n/g;
    int b=m/g;
    rep(i,0,q){
    	int sx,sy,ex,ey;
    	cin>>sx>>sy>>ex>>ey;
    	sy--;
    	ey--;
    	int s,e;
    	if(sx==1) s=sy/a;
    	else s=sy/b;
    	if(ex==1) e=ey/a;
    	else e=ey/b;
    	if(s==e) cout<<"YES"<<endl;
    	else cout<<"NO"<<endl;
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