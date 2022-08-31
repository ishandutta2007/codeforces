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
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}


struct uf{
	int par[200005],ran[200005];
	void init(){
		rep(i,200005){
			par[i] = i;
			ran[i] = 0;
		}
	}
	int find(int x){
		if(x == par[x]) return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x,int y){
		x = find(x); y = find(y);
		if(x == y) return;
		if(ran[x] < ran[y]) par[x] = y;
		else{
			par[y] = x;
			if(ran[x] == ran[y]) ran[x]++;
		}
	}
	bool same(int x,int y){
		return find(x) == find(y);
	}
}kaede;
int n;
int cnt[(1<<18)], num[(1<<18)];
int mx[200005],a[200005];
ll ans = 0;
int main(){
	scanf("%d",&n);
	repn(i,n){
		scanf("%d",&a[i]);
		num[a[i]] = i;
		cnt[a[i]]++;
	}
	a[n+1] = 0;
	num[0] = n+1;
	cnt[0]++;
	kaede.init();
	for(int i=(1<<18)-1;i>=0;i--){
		int cur = i;
		while(1){
			int a = cur, b = i-cur;
			if(cnt[a] && cnt[b]){
				if(kaede.same(num[a], num[b]) == false){
				    ans += 1LL * i * (cnt[a]+cnt[b]-1);
				    kaede.unite(num[a], num[b]);
				}
				cnt[a] = cnt[b] = 1;
			}
			if(cur == 0) break;
			cur = (cur-1) & i;
		}
	}
	repn(i,n) {
		ans -= a[i];
	}
	cout << ans << endl;
	return 0;
}