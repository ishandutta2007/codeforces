#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
const ll mod = 1000000007;
typedef pair<ll,int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
int t;
ll n,k;
ll mn(ll n,ll k){
	ll lb = max(0LL,n/k-k-5), ub = n/k+5;
	while(ub-lb > 1){
		ll mid = (lb+ub)/2;
		if( (mid+mid+k-1)*k/2 > n) ub = mid;
		else lb = mid;
	}
	return ub;
}
pair<ll,ll> calc(ll n,ll k){
	if(n < k*(k+1)/2) return mp(0,-1e18);
	if(n == k*(k+1)/2) return mp(1,n);
	ll beg = mn(n,k);
	pair<ll,ll>res = calc(beg+k-1,k);
	{
		ll num = beg+k-1-res.fi;
		ll en = beg+k-1-(num%k);
		ll be = en-k+1;
		if(en+1 <= res.sc && res.sc <= beg+k-1){
			be--; en--;
		}
		ll sum = (be+en)*(en-be+1)/2;
		if(be <= res.sc && res.sc <= en){
			sum -= res.sc-be+1;
		}
		if(sum <= n){
			return pair<ll,ll>(num/k,sum);
		}
		else{
			assert(en == beg+k-1);
			if(sum == (be+en)*(en-be+1)/2){
				ll en = be-1;
				ll be = en-k+1;
				sum = (be+en)*(en-be+1)/2;
				if(be <= res.sc && res.sc <= en){
					sum -= res.sc-be+1;
				}
			}
			else{
				ll en = be-2;
				ll be = en-k+1;
				sum = (be+en)*(en-be+1)/2;
				if(be <= res.sc && res.sc <= en){
					sum -= res.sc-be+1;
				}
			}
			return pair<ll,ll>(num/k-1,sum);
		}
	}
}
int main(){
	cin >> t;
	while(t--){
		scanf("%lld%lld",&n,&k);
		pair<ll,ll> num = calc(n,k);
		if(num.sc == n){
			printf("%lld\n",(k+1)*num.fi);
		}
		else{
			ll val = n-num.fi;
			if(val%k == 0){
				ll dv = val/k;
				printf("%lld\n",dv*(k+1)-1);
			}
			else{
				ll dv = val/k;
				printf("%lld\n",dv*(k+1)+val%k);
			}
		}
	}
}