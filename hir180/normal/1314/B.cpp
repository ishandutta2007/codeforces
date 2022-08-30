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
int n,k;
int ret;
int dp[18][(1<<17)][2][2];
bool ex[(1<<17)];
int main(){
	scanf("%d%d",&n,&k);
	if(k == 0){
	    puts("0"); return 0;
	}
	n = (1<<n);
	rep(i,k){
		int a; scanf("%d",&a);
		--a; ex[a] = 1;
	}
	rep(a,18)rep(b,(1<<17))rep(c,2)rep(d,2)dp[a][b][c][d]=-INF;
	rep(i,n){
		dp[0][i][ex[i]][0] = 0;
	}
	rep(j,17){
		rep(i,n){
			if(i+(1<<j) >= (1<<17)){
				continue;
			}
			else{
				rep(a,2)rep(b,2)rep(c,2)rep(d,2){
					int e,f,add;
					e = (a||c), f = (b||d);
					add = 0;
					if((2<<j) <= n && (a||c)) add += 1;
					if(j && (2<<j) <= n && f) add ++;
					if(j && (2<<j) <= n && (b||d)) add++;
					dp[j+1][i][e][f] = max(dp[j+1][i][e][f], dp[j][i][a][b]+dp[j][i+(1<<j)][c][d]+add);
					e = a; f = (b||c||d);
					add = 0;
					if((2<<j) <= n && (a||c)) add += 1;
					if(j && (2<<j) <= n && f) add ++;
					if(j && (2<<j) <= n && (b||d)) add++;
					dp[j+1][i][e][f] = max(dp[j+1][i][e][f], dp[j][i][a][b]+dp[j][i+(1<<j)][c][d]+add);
					e = c; f = (a||b||d);
					add = 0;
					if((2<<j) <= n && (a||c)) add += 1;
					if(j && (2<<j) <= n && f) add ++;
					if(j && (2<<j) <= n && (b||d)) add++;
					dp[j+1][i][e][f] = max(dp[j+1][i][e][f], dp[j][i][a][b]+dp[j][i+(1<<j)][c][d]+add);
				}
			}
		}
	}
	rep(j,18)rep(i,n)rep(c,2)rep(d,2) ret = max(ret,dp[j][i][c][d]);
	cout << ++ret << endl;
	return 0;
}