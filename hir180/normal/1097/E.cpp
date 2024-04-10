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
int n;
int a[100005],b[100005];
int mn[100005];
int len[100005];
vector<vector<int>>vec;
int pre[100005];
void solve(){
	if(n == 0) return;
	int ans = 0;
	repn(i,10000){
		if(i*(i+1)/2 > n){
			ans = i-1;
			break;
		}
	}
	repn(i,n) mn[i] = INF;
	int mx = 0;
	repn(i,n){
		int x = lower_bound(mn+1,mn+n+1,a[i])-mn;
		pre[a[i]] = mn[x-1];
		mn[x] = a[i];
		len[i] = x;
		mx = max(mx,x);
	}
	if(mx <= ans){
		repn(i,mx){
			vector<int>vi;
			repn(j,n) if(len[j] == i) vi.pb(a[j]);
			vec.pb(vi);
		}
		return;
	}
	int beg;
	repn(i,n) if(len[i] == mx) beg = a[i];
	vector<int>vi;
	while(beg){
		vi.pb(beg);
		beg = pre[beg];
	}
	reverse(vi.begin(),vi.end());
	vec.pb(vi);
	int pt = 0,nxt = 1;
	repn(i,n){
		if(pt < vi.size() && vi[pt] == a[i]){
			pt++;
		}
		else b[nxt++] = a[i];
	}
	n = nxt-1;
	repn(i,n) a[i] = b[i];
	solve();
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
	    vec.clear();
		scanf("%d",&n);
		repn(i,n){
			scanf("%d",&a[i]);
		}
		solve();
		printf("%d\n",vec.size());
		rep(i,vec.size()) {
		    printf("%d",vec[i].size());
		    rep(j,vec[i].size()) printf(" %d",vec[i][j]);
		    puts("");
		}
	}
}