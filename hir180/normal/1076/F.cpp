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
#define POSR(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,k,a[300005],b[300005];
ll X,Y;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		ll XX = 1e18, YY = 1e18;
		//oo
		//n <= b[i] <= n*k  n <= a[i] <= k-X+(n-1)*k+mid
		//(lb,ub]
		if(X < 1e17){
			ll lb = 0,ub = 4000005;
			while(ub-lb > 1){
				int mid = (lb+ub)/2;
				ll mn = (b[i]+k-1)/k;
				ll mx = b[i];
				ll mn2 = (a[i]+X-mid+k-1)/k;
				ll mx2 = a[i];
				mn = max(mn,mn2);
				mx = min(mx,mx2);
				if(mn <= mx) ub = mid;
				else lb = mid;
			}
			if(ub < 4000000) XX = min(XX,ub);
		}
		//ox
		//n <= b[i] <= n*k-k+mid  n-1 <= a[i] <= n*k-X
		//(lb,ub]
		if(X < 1e17){
			ll lb = 0,ub = 4000005;
			while(ub-lb > 1){
				int mid = (lb+ub)/2;
				ll mn = (b[i]-mid+k+k-1)/k;
				ll mx = b[i];
				ll mn2 = (a[i]+X+k-1)/k;
				ll mx2 = a[i]+1;
				mn = max(mn,mn2);
				mx = min(mx,mx2);
				if(mn <= mx) ub = mid;
				else lb = mid;
			}
			if(ub < 4000000) YY = min(YY,ub);
		}
		//xo
		//n-1 <= b[i] <= n*k-Y  n <= a[i] <= n*k-k+mid
		//(lb,ub]
		if(Y < 1e17){
			ll lb = 0,ub = 4000005;
			while(ub-lb > 1){
				int mid = (lb+ub)/2;
				ll mn = (b[i]+Y+k-1)/k;
				ll mx = b[i]+1;
				ll mn2 = (a[i]-mid+k+k-1)/k;
				ll mx2 = a[i];
				mn = max(mn,mn2);
				mx = min(mx,mx2);
				if(mn <= mx) ub = mid;
				else lb = mid;
			}
			if(ub < 4000000) XX = min(XX,ub);
		}
		//xx
		//n <= a[i] <= n*k  n <= b[i] <= k-Y+(n-1)*k+mid
		//(lb,ub]
		if(Y < 1e17){
			ll lb = 0,ub = 4000005;
			while(ub-lb > 1){
				int mid = (lb+ub)/2;
				ll mn = (a[i]+k-1)/k;
				ll mx = a[i];
				ll mn2 = (b[i]+Y-mid+k-1)/k;
				ll mx2 = b[i];
				mn = max(mn,mn2);
				mx = min(mx,mx2);
				if(mn <= mx) ub = mid;
				else lb = mid;
			}
			if(ub < 4000000) YY = min(YY,ub);
		}
		if(XX > k) XX = 1e18;
		if(YY > k) YY = 1e18;
		X = XX;
		Y = YY;
	}
	if(X < 1e17 || Y < 1e17) puts("YES");
	else puts("NO");
}