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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n,p[300005],pos[300005];

int main(){
	scanf("%d",&n);
	repn(i,n){
		scanf("%d",&p[i]);
		pos[p[i]] = i;
	}
	vector<P>vec;
	for(int x=n/2;x>=1;x--){
		int val = x;
		if(pos[val] <= n/2){
			vec.pb(mp(pos[val],n));
			swap(p[pos[val]],p[n]);
			swap(pos[p[pos[val]]],pos[p[n]]);
			
			vec.pb(mp(pos[val],val));
			swap(p[pos[val]],p[val]);
			swap(pos[p[pos[val]]],pos[p[val]]);
		}
		else{
			vec.pb(mp(pos[val],1));
			swap(p[pos[val]],p[1]);
			swap(pos[p[pos[val]]],pos[p[1]]);
			
			vec.pb(mp(pos[val],n));
			swap(p[pos[val]],p[n]);
			swap(pos[p[pos[val]]],pos[p[n]]);
			
			vec.pb(mp(pos[val],val));
			swap(p[pos[val]],p[val]);
			swap(pos[p[pos[val]]],pos[p[val]]);
		}
		if(x == 1) break;
		
		val = n+1-x;
		if(pos[val] > n/2){
			vec.pb(mp(pos[val],1));
			swap(p[pos[val]],p[1]);
			swap(pos[p[pos[val]]],pos[p[1]]);
			
			vec.pb(mp(pos[val],val));
			swap(p[pos[val]],p[val]);
			swap(pos[p[pos[val]]],pos[p[val]]);
		}
		else{
			vec.pb(mp(pos[val],n));
			swap(p[pos[val]],p[n]);
			swap(pos[p[pos[val]]],pos[p[n]]);
			
			vec.pb(mp(pos[val],1));
			swap(p[pos[val]],p[1]);
			swap(pos[p[pos[val]]],pos[p[1]]);
			
			vec.pb(mp(pos[val],val));
			swap(p[pos[val]],p[val]);
			swap(pos[p[pos[val]]],pos[p[val]]);
		}
	}
	
	
	repn(i,n) assert(p[i] == i);
	printf("%d\n",vec.size());
	rep(i,vec.size()) printf("%d %d\n",vec[i].fi,vec[i].sc);
}