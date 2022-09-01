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
vector<ll>s;
vector<ll>tmm;
int q;
vector<ll>rui;
ll calc(ll wh){
	int x = POSU(tmm,wh);
	ll ret = (ll)s.size();
	ret += 1LL * (tmm.size()-x) * wh;
	if(x) ret += rui[x-1];
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		ll a; scanf("%lld",&a); s.pb(a);
	}
	SORT(s); ERASE(s);
	for(int i=0;i<s.size();i++){
		if(i+1 == s.size()){
			tmm.pb(5e18);
		}
		else{
			tmm.pb(s[i+1]-s[i]-1);
		}
	}
	SORT(tmm);
	for(int i=0;i<tmm.size();i++){
		if(i == 0) rui.pb(tmm[i]);
		else rui.pb(rui[i-1]+tmm[i]);
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		ll L,R; scanf("%lld%lld",&L,&R);
		printf("%lld\n",calc(R-L));
	}
	return 0;
}