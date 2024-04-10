#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
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
int n; ll a[105],mn;
int main(){
	cin>>n>>mn;
	rep(i,n) cin>>a[i];
	ll ans = 0;
	repn(i,400000){
		ll sum = 0;
		rep(j,n){
			ll x = (a[j]+i-1)/i;
			x *= i;
			sum += x-a[j];
		}
		if(sum<=mn) ans = i;
	}//cout<<ans<<endl;
//	assert(ans);
	vector<ll>cand;
	rep(j,n){
		for(int i=2505;i>=1;i--){
			//div i+1 -> i
			ll val = (a[j]+i-1)/i;
			cand.pb(val);
		}
	}
	//[cand[i],cand[i+1])...same
	SORT(cand); ERASE(cand);
	rep(i,cand.size()){
		ll lb = cand[i]-1,ub = (i==cand.size()-1?1e13:cand[i+1]);
		//cout<<lb<<" "<<ub<<endl;
		while(ub-lb>1){
			ll mid = (lb+ub)/2;
			ll sum = 0;
			rep(j,n){
				ll x = (a[j]+mid-1)/mid;
				x *= mid;
				sum += x-a[j];
			}
		//	if(mid>=40)cout<<mid<<" "<<sum<<endl;
			if(sum<=mn) lb=mid;
			else ub=mid;
		}
		if(lb == cand[i]-1) continue;
		ans=max(ans,lb); //cout<<ub<<endl;
	}
	cout<<ans<<endl;
}