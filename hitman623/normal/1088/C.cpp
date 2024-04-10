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
int n,a[2005];
vii v;
void solve(){
	cin>>n;
	rep(i,1,n+1) cin>>a[i];
	for(int i=n;i>=1;i--){
    	// a[i]+x=i+alpha*(n+1)
		int alpha=0,x;
		while(1){
			if(i+alpha*(n+1)-a[i]<0) alpha++;
			else{
				x=i+alpha*(n+1)-a[i];
				break;
			}
		}
		if(x==0) continue;
		v.pb({i,x});
		rep(j,1,i+1){
			a[j]+=x;
			a[j]%=(n+1);
		}
	}
	cout<<sz(v)+1<<endl;
	for(auto i:v){
		cout<<1<<" "<<i.x<<" "<<i.y<<endl;
	}
	cout<<2<<" "<<n<<" "<<n+1<<endl;
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