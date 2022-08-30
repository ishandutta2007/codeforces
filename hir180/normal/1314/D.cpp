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
P good[81][81][4];
int a[81][81];
int used[81];
int val[4];
int dp[16][4];
int ans = INF;

void dfs(int cur,int las){
	if(cur < k/2-1){
		for(int x=las;x<n;x++){
			val[cur] = x;
			used[x]++;
			dfs(cur+1,x);
			used[x]--;
		}
	}
	else{
		rep(i,16)rep(j,4) dp[i][j] = INF;
		int sz = k/2-1;
		rep(i,sz){
			int best = INF;
			rep(j,4){
				if(used[good[0][val[i]][j].sc] == 0){
					best = good[0][val[i]][j].fi;
					break;
				}
			}
			if(best > 5e8) continue;
			dp[(1<<i)][i] = best;
		}
		rep(i,(1<<sz)){
			if(i == 0) continue;
			rep(j,sz){
				if(!((i>>j)&1)) continue;
				//dp[i][j]
				rep(k,sz){
					if(((i>>k)&1)) continue;
					int best = INF;
					rep(x,4){
						if(used[good[val[j]][val[k]][x].sc] == 0){
							best = good[val[j]][val[k]][x].fi; break;
						}
					}
					if(best > 5e8) continue;
					dp[i+(1<<k)][k] = min(dp[i+(1<<k)][k],dp[i][j]+best);
				}
			}
		}
		rep(i,sz){
			//dp[(1<<sz)-1][i]
			int best = INF;
			rep(x,4){
				if(used[good[val[i]][0][x].sc] == 0){
					best = good[val[i]][0][x].fi; break;
				}
			}
			if(best > 5e8) continue;
			ans = min(ans,dp[(1<<sz)-1][i]+best);
		}
	}
}
int main(){
	scanf("%d%d",&n,&k); //n = 80; k = 10;
	//srand((unsigned)time(NULL));
	rep(i,n){
		rep(j,n){
			scanf("%d",&a[i][j]); //a[i][j] = rand(); //scanf("%d",&a[i][j]);
		}
	}
	rep(i,n)rep(j,n)rep(k,4) good[i][j][k] = mp(INF,80);
	rep(i,n){
		rep(j,n){
			vector<P>vec;
			rep(k,n){
				if(i == k || j == k) continue;
				vec.pb(mp(a[i][k]+a[k][j],k));
			}
			sort(vec.begin(),vec.end());
			rep(x,4){
				if(x == vec.size()) break;
				good[i][j][x] = vec[x];
			}
		}
	}
	if(k == 2){
	    cout << good[0][0][0].fi << endl;
	    return 0;
	}
	used[0] = 1;
	dfs(0,0);
	cout << ans << endl;
	return 0;
}