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
int n,m;
char str[105][105];
int cnt[105][105];
void solve(){
	scanf("%d%d",&n,&m);
	rep(i,n) scanf("%s",&str[i]);
	bool ex = 0, ex_peri = 0, ex_not = 0, ex_corner = 0;
	int mnx=INF,mxx=-INF;
	int mny=INF,mxy=-INF;
	rep(i,n) rep(j,m){
		if(str[i][j] == 'A'){
			ex = 1;
			if(i == 0 || i == n-1 || j == 0 || j == m-1) ex_peri = 1;
			if( (i == 0 || i == n-1) && (j == 0 || j == m-1) ) ex_corner = 1;
		}
		else{
			ex_not = 1;
			mnx = min(mnx,i); mxx = max(mxx,i);
			mny = min(mny,j); mxy = max(mxy,j);
		}
	}
	if(!ex) puts("MORTAL");
	else if(!ex_not) puts("0");
	else if(!ex_peri) puts("4");
	else{
		//answer is [1,3]
		if(mp(mp(mnx,mxx),mp(mny,mxy)) != mp(mp(0,n-1),mp(0,m-1))){
			puts("1");
		}
		else if(ex_corner){
			puts("2");
		}
		else{
			bool ok = 0;
			rep(i,n){
				rep(j,m) if(str[i][j] == 'P') goto fail;
				ok = 1; fail:;
			}
			rep(j,m){
				rep(i,n) if(str[i][j] == 'P') goto fail2;
				ok = 1; fail2:;
			}
			puts(ok?"2":"3");
		}
	}
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		solve();
	}
}