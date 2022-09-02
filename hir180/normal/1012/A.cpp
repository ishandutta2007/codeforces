#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
vector<int>vec;
int main(){
	cin>>n;
	rep(i,2*n){
		int a; cin>>a; vec.pb(a);
	}
	sort(vec.begin(),vec.end());
	ll ans = 8e18;
	ll x = vec[n-1]-vec[0];
	ll y = vec[2*n-1]-vec[n];
	ans = min(ans,x*y);
	x = vec[2*n-1]-vec[0];
	for(int i=1;i<n;i++){
		ll z = vec[i+n-1]-vec[i];
		ans = min(ans,x*z);
	}
	cout<<ans<<endl;
}