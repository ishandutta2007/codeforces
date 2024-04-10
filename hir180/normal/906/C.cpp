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

int n,m;
int c[25];
bool ok[1<<22];
int mask[1<<22];
int main(){
	scanf("%d%d",&n,&m);
	if(m == n*(n-1)/2){
	    puts("0"); return 0;
	}
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b);
		a--; b--;
		c[a] |= (1<<b);
		c[b] |= (1<<a);
	}
	rep(i,n) c[i] |= (1<<i);
	ok[0] = 1;
	mask[0] = 0;
	rep(i,n) {
	    ok[(1<<i)] = 1;
	    mask[(1<<i)] = c[i];
	}
	rep(ma,(1<<n)){
		rep(j,n){
			if(((ma>>j)&1)) continue;
			mask[ma | (1<<j)] = mask[ma] | c[j];
			if(ok[ma] &&  (c[j]&ma) > 0 ) ok[ma | (1<<j)] = 1;
		}
	}
	int ans = INF, id = INF;
	rep(ma,(1<<n)){
		if(ok[ma] && mask[ma] == (1<<n)-1 && ans > __builtin_popcount(ma)){
			ans = __builtin_popcount(ma);
			id = ma;
		}
	}
	cout << ans << endl;
	rep(i,n){
		if(((id>>i)&1)){
			cout << i+1 << endl;
		}
	}
}