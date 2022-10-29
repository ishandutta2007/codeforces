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
int n,m,a[200005],s;
bool check(int mid){
	int cur=0,pos=0,val=0;
	while(pos<n){
		rep(_,0,mid){
			if(a[pos]<=cur) break;
			val+=a[pos++]-cur;
			if(pos==n) break;
		}
		if(pos==n or a[pos]<=cur) break;
		cur++;
	}
	return val>=m;
}
void solve(){
    cin>>n>>m;
    rep(i,0,n) cin>>a[i],s+=a[i];
    if(s<m){
    	cout<<-1<<endl;
    	return;
    }
    sort(a,a+n);
    reverse(a,a+n);
    int lo=0,hi=n+1;
    while(hi-lo>1){
    	int mid=(lo+hi)/2;
    	if(check(mid)) hi=mid;
    	else lo=mid;
    }
    cout<<hi<<endl;
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