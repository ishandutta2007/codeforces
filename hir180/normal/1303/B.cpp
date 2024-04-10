#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int t;
void solve(){
	ll n,a,b; cin >> n >> a >> b;
	ll ans = 1LL*n;
	ll need = (n+1)/2;
	ll rem = need;
	need = (need+a-1)/a;
	rem -= (need-1)*a;
	assert(rem);
	if(ans < (need-1) * (a+b) + rem) ans =  (need-1) * (a+b) + rem;
	cout<<ans<<endl;
}
int main(){
	cin>>t;
	while(t--) solve();
}