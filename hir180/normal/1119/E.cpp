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
ll x[300005];

int main(){
	scanf("%d",&n);
	ll sum = 0;
	rep(i,n){
		scanf("%lld",&x[i]);
		sum += x[i];
	}
	reverse(x,x+n);
	ll lb = 0,ub = 2e14;
	while(ub-lb > 1){
		ll mid = (lb+ub)/2;
		if(mid*3LL > sum){
			ub = mid; continue;
		}
		vector<pair<ll,ll> >up;
		vector<pair<ll,ll> >dw_;
		ll M = mid;
		for(int i=0;i<n;i++){
			if(mid >= x[i]/2){
				if(x[i]/2 > 0) up.pb(mp(i,x[i]/2));
				mid -= x[i]/2;
				if(x[i]%2 > 0) dw_.pb(mp(i,x[i]%2));
			}
			else{
				if(mid > 0) up.pb(mp(i,mid));
				
				if(x[i]-2LL*mid > 0) dw_.pb(mp(i,x[i]-2LL*mid));
				mid = 0;
			}
		}
		if(mid > 0){
		    ub = M; continue;
		}
		mid = M;
		reverse(dw_.begin(),dw_.end());
		ll zan = mid;
		vector<pair<ll,ll> >dw;
		for(int i=0;i<dw_.size()&&zan;i++){
			if(zan > dw_[i].sc){
				zan -= dw_[i].sc;
				dw.pb(dw_[i]);
			}
			else{
				dw.pb(mp(dw_[i].fi,zan));
				zan = 0;
				break;
			}
		}
		if(zan > 0){
		    ub = M; continue;
		}
		reverse(dw.begin(),dw.end());
		int cur = 0;
		bool bad = 0;
		for(int i=0;i<up.size();i++){
			while(1){
				if(up[i].sc > dw[cur].sc){
					if(up[i].fi > dw[cur].fi) bad = 1;
					up[i].sc -= dw[cur].sc;
					cur++;
				}
				else{
					if(up[i].fi > dw[cur].fi) bad = 1;
					dw[cur].sc -= up[i].sc;
					if(dw[cur].sc == 0) cur++;
					up[i].sc = 0;
					break;
				}
			}
		}
		if(!bad) lb = mid;
		else ub = mid;
	}
	cout << lb << endl;
	return 0;
}