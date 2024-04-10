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
int n,a[1005][1005],x;
int ans[1005];

bool check(int x){
	ans[0] = x;
	for(int i=1;i<n;i++){
		if(a[0][i]%x != 0) return false;
		ans[i] = a[0][i] / x;
	}
	for(int i=1;i<n;i++) for(int j=i+1;j<n;j++){
		if(1LL*ans[i] * ans[j] != 1LL*a[i][j]) return false;
	}
	rep(i,n) printf("%d ",ans[i]);
	puts("");
	return true;
}
int main(){
	cin >> n;
	rep(i,n)rep(j,n){
		scanf("%d",&a[i][j]);
	}
	int v = a[0][1];
	for(int k=1;k*k<=v;k++){
		if(v%k != 0) continue;
		if(check(k)) return 0;
		if(check(v/k)) return 0;
	}
}