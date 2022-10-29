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
int n,m[200005],p[200005];
vi v[200005];
void solve(){
	cin>>n;
	rep(i,0,n) v[i].clear();
	rep(i,0,n){
		cin>>m[i]>>p[i];
		v[m[i]].pb(p[i]);
	}
	rep(i,0,n) sort(all(v[i]));
	p[0]=sz(v[0]);
	priority_queue<int,vi,greater<int>> pq;
	rep(i,1,n) p[i]=sz(v[i])+p[i-1];
	int cur=0,ans=0;
	for(int i=n-1;i>=0;i--){
		for(auto j:v[i]) pq.push(j);
		int d=0;
		if(i) d=p[i-1];
		if(d+cur>=i);
		else{
			rep(j,0,i-d-cur){
				ans+=pq.top();
				pq.pop();
			}
			cur+=i-d-cur;
		}
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