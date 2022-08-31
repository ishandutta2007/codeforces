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

int n;
char f[55][55];
short dp[55][55][55][55];
short maxx(short a,short b){ return (a<b?b:a); }
short minn(short a,short b){ return (a>b?b:a); }
int main(){
	scanf("%d",&n); //n = 50; srand((unsigned)time(NULL));
	//rep(i,n) rep(j,n) if(rand()&1) f[i][j] = '#'; else f[i][j] = '.';
	rep(i,n) scanf("%s",&f[i]);

	rep(a,n) for(int b=a;b<n;b++){
		bool ex[55]={};
		rep(c,n){
			for(int i=a;i<=b;i++) if(f[i][c] == '#') ex[c] = 1;
		}
		
		rep(c,n){
			short mn = 1000, mx = -1000;
			for(int d=c;d<n;d++){
				//dp[a][b][c][d]
				if(ex[d]) {
					if(mn > d) mn = d;//mn = min(mn,d);
					if(mx < d) mx = d;//mx = max(mx,d);
				}
				dp[a][b][c][d] = maxx(dp[a][b][c][d],mx-mn+1);
			}
		}
	}
	rep(c,n) for(int d=c;d<n;d++){
		bool ex[55]={};
		rep(a,n){
			for(int i=c;i<=d;i++) if(f[a][i] == '#') ex[a] = 1;
		}
		
		rep(a,n){
			short mn = 1000, mx = -1000;
			for(int b=a;b<n;b++){
				//dp[a][b][c][d]
				if(ex[b]) {
					if(mn > b) mn = b;//mn = min(mn,d);
					if(mx < b) mx = b;//mx = max(mx,d);
				}
				dp[a][b][c][d] = maxx(dp[a][b][c][d],mx-mn+1);
			}
		}
	}
	for(int a=n-1;a>=0;a--) for(int b=a;b<n;b++){
		
		for(int c=n-1;c>=0;c--){
			for(int d=c;d<n;d++){
				//dp[a][b][c][d]
				for(int dd=a+1;dd<b;dd++) dp[a][b][c][d] = minn(dp[a][b][c][d],dp[a][dd][c][d]+dp[dd+1][b][c][d]);
				for(int ee=c+1;ee<d;ee++) dp[a][b][c][d] = minn(dp[a][b][c][d],dp[a][b][c][ee]+dp[a][b][ee+1][d]);
			}
		}
	}
	cout << dp[0][n-1][0][n-1] << endl;
	return 0;
}