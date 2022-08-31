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
int n,aa[105],z,o;
int dp[105][3][105][105];

int main(){
	cin>>n;
	repn(i,n) cin >> aa[i];
	repn(i,n) if(i%2==0) z++; else o++;
	repn(i,n){
		if(aa[i]){
			if(aa[i]%2 == 0) z--; else o--;
		}
	}
	rep(a,105)rep(b,3)rep(c,105)rep(d,105)dp[a][b][c][d] = INF;
	dp[0][2][0][0] = 0;
	
	rep(i,n){
		rep(j,3){
			rep(a,z+1){
				rep(b,o+1){
					if(dp[i][j][a][b] == INF) continue;
					
					if(aa[i+1]){
						int x = aa[i+1]%2;
						int add = 0;
						if(j==0&&x==1) add++;
						if(j==1&&x==0) add++;
						dp[i+1][x][a][b] = min(dp[i+1][x][a][b],dp[i][j][a][b]+add);
					}
					else{
						rep(x,2){
							int add = 0;
							if(j==0&&x==1) add++;
							if(j==1&&x==0) add++;
							dp[i+1][x][a+(x==0)][b+(x==1)] = min(dp[i+1][x][a+(x==0)][b+(x==1)],dp[i][j][a][b]+add);
						}
					}
				}
			}
		}
	}
	int ans = min(dp[n][0][z][o],dp[n][1][z][o]);
	cout << ans << endl;
}