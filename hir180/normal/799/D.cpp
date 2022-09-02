#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
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
int a,b,n,m,q,v[100005];
bool ok[2][100005];
int rec(){
	if(a<=n && b<=m){
		return 0;
	}
	int A = (a+n-1)/n,B = (b+m-1)/m;
	sort(v,v+q,greater<int>());
	int lb = -1,ub = q+1;
	while(ub-lb > 1){
		int mid = (lb+ub)/2;
		if(mid >= 36){
			ub = mid;
			continue;
		}
		ll mul = 1;
		bool ok = 0;
		for(int i=0;i<mid;i++){
			if(1e16/mul <= v[i]){
				ok = 1; break;
			}
			mul *= v[i];
		}
		if(ok){
			ub = mid;
			continue;
		}
		int L = mid/2;
		vector<ll>x,y;
		for(int i=0;i<(1<<L);i++){
			ll M = 1;
			rep(j,L){
				if(((i>>j)&1)) M *= v[j];
			}
			x.pb(M);
		}
		int R = mid-L;
		for(int i=0;i<(1<<R);i++){
			ll M = 1;
			rep(j,R){
				if(((i>>j)&1)) M *= v[L+j];
			}
			y.pb(M);
		}
		SORT(x); ERASE(x);
		SORT(y); ERASE(y);
		for(int i=0;i<x.size();i++){
			ll zan = (1LL*A+x[i]-1LL)/x[i];
			int g = POSL(y,zan);
			if(g == y.size()) continue;
			ll act = x[i] * y[g];
			assert(mul%act == 0);
			if((mul/act) >= B){
				ok = 1; break;
			}
		}
		if(ok) ub=mid;
		else lb=mid;
	}
	if(ub == q+1) ub = INF;
	return ub;
}
int main(){
	scanf("%d%d%d%d%d",&a,&b,&n,&m,&q);
	rep(i,q) scanf("%d",&v[i]);
	int ans = rec();
	swap(n,m);
	ans = min(ans,rec());
	if(ans == INF) ans = -1;
	cout << ans << endl;
}