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
int n,L,R;
vi res;
void go(int pos,int cnt){
	if(cnt>R) return;
	if(pos==n){
		assert(cnt==n*(n-1));
		if(R==n*(n-1)+1) res.pb(1);
		return;
	}
	if(2*(n-pos)+cnt<L) go(pos+1,cnt+2*(n-pos));
	else{
		for(int i=pos+1;i<=n;i++){
			cnt++;
			if(cnt>=L and cnt<=R) res.pb(pos);
			cnt++;
			if(cnt>=L and cnt<=R) res.pb(i);
		}
		go(pos+1,cnt);
	}
}
void solve(){
	res.clear();
	cin>>n>>L>>R;
	go(1,0);
	for(auto i:res) cout<<i<<" ";
	cout<<endl;
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