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
ll n;;
vector<ll>ans;
int main(){
	cin>>n;
	for(ll i=1;i*i<=n;i++){
		if(n%i!=0) continue;
		ll x = (2+n-i)*(n/i)/2;
		ans.pb(x);
		if(i*i==n) continue;
		x = (2+n-n/i)*(i)/2;
		ans.pb(x);
	}
	SORT(ans);
	for(int i=0;i<ans.size();i++) printf("%lld ",ans[i]);
	puts("");
}