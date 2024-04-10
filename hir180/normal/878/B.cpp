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

vector<P>bin[32];
int n,k,m,a[100005];
void merge(vector<P>&a,vector<P>b){
	rep(x,b.size()){
		if(a.empty()) a.pb(b[x]);
		else if(a.back().sc != b[x].sc) a.pb(b[x]);
		else{
			a.back().fi += b[x].fi;
			a.back().fi %= k;
			if(a.back().fi == 0) a.pop_back();
		}
	}
	//return a;
}
vector<P> mergee(vector<P>a,vector<P>b){
	rep(x,b.size()){
		if(a.empty()) a.pb(b[x]);
		else if(a.back().sc != b[x].sc) a.pb(b[x]);
		else{
			a.back().fi += b[x].fi;
			a.back().fi %= k;
			if(a.back().fi == 0) a.pop_back();
		}
	}
	return a;
}
void not_contract(){
	ll num[6] = {};
	rep(x,2){//6){
		rep(y,bin[x].size()) num[x] += bin[x][y].fi;
	}
	//for(int i=1;i<4;i++) assert(num[i+1]-num[i] == (num[1]-num[0])*(1LL<<i));
	//ll w=0;
	cout << num[0] + (num[1]-num[0]) * 1LL * (m-1) << endl;
}
int main(){
	scanf("%d%d%d",&n,&k,&m);
	int pre = -1;
	int cnt = 0;
	repn(i,n){
	    scanf("%d",&a[i]);
		if(pre != a[i]){
			if(cnt%k > 0) {
			    vector<P>V; V.pb(mp(cnt%k,pre));
			    merge(bin[0],V);
			}
			pre = a[i]; cnt = 1;
		}
		else cnt++;
	}
	if(cnt%k > 0) {
	    vector<P>V; V.pb(mp(cnt%k,pre));
	    merge(bin[0],V);
	}
	for(int j=0;j<31;j++){
		bin[j+1] = mergee(bin[j],bin[j]);
		if(bin[j+1].size() > 500000){
			not_contract();
			return 0;
		}
	}
	vector<P>ret;
	rep(j,31){
		if(((m>>j)&1)) merge(ret,bin[j]);
	}
	ll ans = 0;
	rep(i,ret.size()) ans += ret[i].fi%k;
	cout << ans << endl;
}