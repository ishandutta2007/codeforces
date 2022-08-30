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
template<class T>
void dmp(vector<T>&a){
    rep(i,a.size()) cout << a[i] << " ";
    cout << endl;
}
void monotone_minima(vector<ll>&ret, vector<ll>&a, vector<ll>&b, int l, int r, int x, int y){
	if(l > r) return;
	if(l == r){
		for(int i=x;i<=y;i++){
			if(0 <= l-i && l-i < a.size()){
				ret[l] = max(ret[l], a[l-i]+b[i]);
			}
		}
		return;
	}
	if(x == y){
		for(int i=l;i<=r;i++){
			if(0 <= i-x && i-x < a.size()){
				ret[i] = max(ret[i], a[i-x]+b[x]);
			}
		}
		return;
	}
	int m = (l+r)/2;
	int pos = -1;
	ll cur_best = -2e18;
	for(int i=x;i<=y;i++){
		if(0 <= m-i && m-i < a.size() && cur_best <= b[i]+a[m-i]){
			cur_best = b[i]+a[m-i];
			pos = i;
		}
	}
	assert(pos != -1);
	ret[m] = max(ret[m],cur_best);
	monotone_minima(ret, a, b, l, m-1, x, pos);
	monotone_minima(ret, a, b, m+1, r, pos, y);
}
vector<ll>merge_one_convex(vector<ll>a,vector<ll>b){
	vector<ll>ret; ret.resize(a.size()+b.size()-1, 0);
	for(int i=2;i<a.size();i++){
	    assert(a[i]-a[i-1] <= a[i-1]-a[i-2]);
	}
	monotone_minima(ret, a, b, 0, ret.size()-1, 0, b.size()-1);
	return ret;
}
int n,m;
vector<ll>dp,val[3];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b); a--;
		val[a].pb(b);
	}
	dp.resize(m+1, 0);
	repn(i,m) dp[i] = -1e18;
	rep(i,3){
		SORT(val[i]);
		val[i].push_back(0);
		reverse(val[i].begin(), val[i].end());
		for(int j=1;j<val[i].size();j++){
			val[i][j] += val[i][j-1];
		}
		vector<ll>nxt;
		nxt.resize(m+1, 0);
		vector<ll>dp_conv;
		rep(md,i+1){
			dp_conv.resize(m/(i+1)+2, 0);
			int beg = 0;
			while(beg*(i+1)+md <= m){
				dp_conv[beg] = dp[beg*(i+1)+md];
				beg++;
			}
			dp_conv.resize(beg);
			dp_conv = merge_one_convex(val[i], dp_conv);
			rep(j,dp_conv.size()){
				if(j*(i+1)+md > m) break;
				nxt[j*(i+1)+md] = max(nxt[j*(i+1)+md], dp_conv[j]);
			}
		}
		dp = nxt;
	}
	ll ans = 0;
	rep(i,m+1) ans = max(ans,dp[i]);
	printf("%lld\n",ans);
	return 0;
}