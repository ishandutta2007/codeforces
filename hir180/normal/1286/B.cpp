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
const ll mod = 1000000007;

int n,r;
vector<int>edge[2005];
int num[2005];
int sz[2005];
void dfs(int v,int u){
	sz[v] = 1;
	rep(i,edge[v].size()){
		dfs(edge[v][i],v);
		sz[v] += sz[edge[v][i]];
	}
}
int ans[2005];
vector<int>calc(int v){
	vector<int>ret;
	ret.resize(sz[v]-1,0);
	int pt = 0;
	rep(i,edge[v].size()){
		auto a = calc(edge[v][i]);
		rep(j,a.size()) ret[pt++] = a[j];
	}
	vector<int>res;
	res.resize(sz[v],0);
	pt = 0;
	int ps = 0;
	rep(i,num[v]) res[pt++] = ret[ps++];
	res[pt++] = v;
	rep(i,sz[v]-1-num[v]) res[pt++] = ret[ps++];
	assert(pt == sz[v] && ps == sz[v]-1);
	return res;
}
int main(){
	cin >> n;
	repn(i,n){
		int p; scanf("%d%d",&p,&num[i]);
		if(p == 0) r = i;
		else edge[p].pb(i);
	}
	dfs(r,-1);
	repn(i,n){
		if(0 <= num[i] && num[i] < sz[i]);
		else{
			puts("NO");
			return 0;
		}
	}
	vector<int>ret = calc(r);
	puts("YES");
	rep(i,ret.size()){
		ans[ret[i]] = i+1;
	}
	repn(i,n) printf("%d ",ans[i]);
	puts("");
}