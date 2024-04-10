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
vector<int>za[500005];
int main(){
	cin>>n;
	rep(i,n){
		int x,y; cin>>x>>y;
		za[x+y+250000].pb(x-y);
	}
	rep(i,500005) SORT(za[i]);
	multiset<int>S[2],T[2];
	rep(i,500005){
		rep(j,za[i].size()){
		    int rem = (za[i][j]%2+2)%2;
			T[rem].insert(za[i][j]);
		}
	}
	ll ans = 0;
	rep(i,500003){int rem = 1-i%2;
		if(!S[rem].empty() && !T[rem].empty()){
			multiset<int>::iterator it = S[rem].begin(); int smn = *it;
			it = S[rem].end(); it--; int smx = *it;
			it = T[rem].begin(); int tmn = *it;
			it = T[rem].end(); it--; int tmx = *it;
			smn = max(smn,tmn);
			smx = min(smx,tmx);
			//(smn,smx)
			int lb,ub;
			if((smn+1+10000000)%2 == i%2) lb = smn+1;
			else lb = smn+2;
			if((smx-1+10000000)%2 == i%2) ub = smx-1;
			else ub = smx-2;
			ans += max(0,(ub-lb)/2+1);
			//cout<<i<<" "<<lb<<" "<<ub<<endl;
		}
		rep(j,za[i].size()){
			S[1-rem].insert(za[i][j]);
		}
		rep(j,za[i+1].size()){
			T[rem].erase(T[rem].find(za[i+1][j]));
		}
	}
	cout<<ans<<endl;
}