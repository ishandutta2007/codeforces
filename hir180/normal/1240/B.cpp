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
int q,n;
int ok[300005],a[300005];
int mn[300005],mx[300005];
vector<int>vec;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		repn(i,n){ mn[i] = INF, mx[i] = -INF; }
		vec.clear();
		vec.pb(-1);
		repn(i,n){
			scanf("%d",&a[i]);
			vec.pb(a[i]);
		}
		SORT(vec); ERASE(vec);
		repn(i,n){
			int A = POSL(vec,a[i]);
			mn[A] = min(mn[A],i);
			mx[A] = max(mx[A],i);
		}
		int sz = vec.size()-1;
		
		ok[sz] = sz;
		for(int i=sz-1;i>=1;i--){
			if(mx[i] < mn[i+1]) ok[i] = ok[i+1];
			else ok[i] = i;
		}
		int ans = 0;
		for(int i=1;i<=sz;i++){
			ans = max(ans,ok[i]-i+1);
		}
		printf("%d\n",sz-ans);
	}
}