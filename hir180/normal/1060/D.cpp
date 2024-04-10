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
ll a[100005],b[100005];
vector<ll>v[2];
int main(){
	scanf("%d",&n);
	repn(i,n){
		scanf("%lld%lld",&a[i],&b[i]);
		v[0].pb(a[i]);
		v[1].pb(b[i]);
	}
	ll ans = 1LL*n;
	rep(q,2) SORT(v[q]);
	for(int i=0;i<n;i++) ans += max(v[0][i],v[1][i]);
	cout << ans << endl;
}