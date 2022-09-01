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
#define ld long double
const int mod = 998244353;
int num[200005];
vector<int>edge[200005];
int a[200005],n;
int main(){
	scanf("%d",&n);
	rep(i,n-1) { int a,b; scanf("%d%d",&a,&b); edge[a].pb(b); edge[b].pb(a); }
	vector<int>ord;
	repn(i,n){
		scanf("%d",&a[i]);
		if(a[1] != 1){ puts("No"); return 0; }
		ord.pb(num[a[i]]);
		rep(j,edge[a[i]].size()){
			if(num[edge[a[i]][j]] == 0){
				num[edge[a[i]][j]] = i;
			}
		}
	}
	rep(i,n-1) if(ord[i] > ord[i+1]){
		puts("No"); return 0;
	}
	puts("Yes");
}