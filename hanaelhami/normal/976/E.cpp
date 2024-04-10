#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>  

using namespace :: std;

const ll maxn=2e5+500;
const ll mod=1e9+7;
const ll inf=1e9+500;

pair<ll,pii> q[maxn];
ll par[maxn];


int main(){
	ll n,a,b,s=0;
	cin>>n>>a>>b;
	a=(1<<a);

	for(ll i=0;i<n;i++){
		ll h,d;
		cin>>h>>d;
		s+=d;
		q[i]=mp(max((ll)0,h-d),mp(h,d));
	}
	sort(q,q+n);
	reverse(q,q+n);
	b=min(b,n);

	par[0]=q[0].F;
	for(ll i=1;i<n;i++){
		par[i]=par[i-1]+q[i].F;
	}

	ll ans=0;
	if(b==1){
		for(ll i=0;i<n;i++){
			ans=max(ans,q[i].S.F*a-q[i].S.S);
		}
		cout<<ans+s;
		return 0;
	}
	if(b>0){
		for(ll i=0;i<n;i++){
			ll res=0;
			if(i<=b-1){
				res=par[b-1]-q[i].F+(q[i].S.F*a-q[i].S.S);				
			}else{
				res=par[b-2]+       (q[i].S.F*a-q[i].S.S);
			}
			ans=max(ans,res);
		}
	}
	cout<<ans+s;


}



/*    
	  .      _______    __    ___     ________      ________       _________     _________   ________
	  .     /       \  |  |  /  /    /        \    |        \     /         \   |        |  |   __   \
	  .    /   _____/  |  | /  /    /    ___   \   |   ___   \   |   _______/   |  ______|  |  |  \   \
	  .   /   /        |  |/  /    /    /   \   \  |  |   \   \  |  (______     |  |_____   |  |__/   /
	  .   |  |         |     /     |   /     \  |  |  |    |  |   \        \    |        |  |      __/
	  .   |  |         |     \     |   \     /  |  |  |    |  |    \______  \   |  ______|  |      \
	  .   \   \_____   |  |\  \    \    \___/   /  |  |___/   /    _______) |   |  |_____   |   |\  \
	  .    \        \  |  | \  \    \          /   |         /    /         /   |        |  |   | \  \
	  .     \_______/  |__|  \__\    \________/    |________/     \________/    |________|  |___|  \__\
 */