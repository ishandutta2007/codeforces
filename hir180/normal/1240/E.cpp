#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
#define int long long
int n;
int cnt[500005];
ll num[500005];
ll aa[500005];
signed main(){
	scanf("%lld",&n);
	rep(i,n){
		int a; scanf("%lld",&a); cnt[a]++;
		aa[i] = a;
	}
	for(int i=3;i<=500000;i++) cnt[i] += cnt[i-1];
	ll ans = 0;
	sort(aa,aa+n,greater<ll>());
	ll lim = aa[0]/2;
	if(n >= 2) lim = max(lim,aa[1]);
	
	for(int y=2;y<=500000;y++){
		ll take = 0;
		for(int i=1;i*y<=500000;i++){
			int lb = i*y, ub = (i+1)*y-1;
			ub = min(ub,500000ll);
			take += 1LL * i * (cnt[ub]-cnt[lb-1]);
		}
		ll lb = 0, ub = lim;
		while(ub - lb > 1){
			int mid = (lb+ub)/2;
			if(take-(mid/y)*2 >= mid) lb = mid;
			else ub = mid;
		}
		for(int x=max(2ll,lb-5ll);x<=min(lim,lb+5ll);x++){
			//solve for (x,y)
			//take x separately
			int m = x%y;
			int C = 0;
			for(int i=0;i*y<=500000;i++){
				int lb = i*y, ub = (i+1)*y-1;
				ub = min(ub,500000ll);
				if(ub < x) continue;
				lb += m;
				lb = max(lb,x);
				if(lb <= ub){
					C += cnt[ub]-cnt[lb-1];
				}
			}
			//take 2x from one piece
			int D = 0;
			if(aa[0] >= 2*x){
				for(int i=0;i*y<=500000;i++){
					int lb = i*y, ub = (i+1)*y-1;
					ub = min(ub,500000ll);
					if(ub < 2*x) continue;
					if(m*2 >= y){
						int k = m*2-y;
						lb += k;
						lb = max(lb,2*x);
						if(lb <= ub){
							D += cnt[ub]-cnt[lb-1];
						}
					}
					else{
						int k = m*2;
						lb += k;
						lb = max(lb,2*x);
						if(lb <= ub){
							D += cnt[ub]-cnt[lb-1];
						}
					}
				}
			}
			int need = INF;
			if(n >= 2 && aa[1] >= x){
				need = min(need,max(0ll,2-C));
			}
			if(aa[0] >= 2*x){
				if(m*2 >= y){
					need = min(need,1+max(0ll,1-D));
				}
				else{
					need = min(need,max(0ll,1-D));
				}
			}
			if(take-(x/y)*2-need >= x){
				ans = max(ans,x*y);
			}
		}
	}
	cout << ans << endl;
}