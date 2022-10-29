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
int n,x,a[100005];
mi f;
void solve(){
	cin>>n>>x;
	rep(i,0,n){
		cin>>a[i];
		f[a[i]]++;
	}
	if(sz(f)!=n){
		cout<<0<<endl;
		return;
	}
	rep(i,0,n){
		if((a[i]&x)!=a[i] and f.count(a[i]&x)){
			cout<<1<<endl;
			return;
		}
	}
	f.clear();
	rep(i,0,n){
		f[a[i]&x]++;
	}
	if(sz(f)!=n) cout<<2<<endl;
	else cout<<-1<<endl;
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