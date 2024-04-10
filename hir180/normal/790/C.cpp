#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
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
int dp[80][80][80][2],n;
string s;
vector<int>pos[3];
int main(){
	cin>>n>>s;
	rep(a,80)rep(b,80)rep(c,80)rep(d,2)dp[a][b][c][d]=INF;
	rep(i,n){
		if(s[i]=='V') pos[0].pb(i);
		else if(s[i]=='K') pos[1].pb(i);
		else pos[2].pb(i);
	}
	dp[0][0][0][0] = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;j+k<=i;k++){
				int l = i-j-k;
				rep(p,2){
					if(dp[j][k][l][p] == INF) continue;
					//V
					if(j+1 <= pos[0].size()){
						int f = POSU(pos[1],pos[0][j]); f = k-f; f=max(f,0);
						int g = POSU(pos[2],pos[0][j]); g = l-g; g=max(g,0);
						dp[j+1][k][l][1] = min(dp[j+1][k][l][1],dp[j][k][l][p]+f+g);
					}
					//K
					if(k+1 <= pos[1].size() && !p){
						int f = POSU(pos[0],pos[1][k]); f = j-f; f=max(f,0);
						int g = POSU(pos[2],pos[1][k]); g = l-g; g=max(g,0);
						dp[j][k+1][l][0] = min(dp[j][k+1][l][0],dp[j][k][l][p]+f+g);
					}
					//other
					if(l+1 <= pos[2].size() ){
						int f = POSU(pos[0],pos[2][l]); f = j-f; f=max(f,0);
						int g = POSU(pos[1],pos[2][l]); g = k-g; g=max(g,0);
						dp[j][k][l+1][0] = min(dp[j][k][l+1][0],dp[j][k][l][p]+f+g);
					}
				}
			}
		}
	}
	int ans=INF;
	for(int i=0;i<=n;i++) for(int j=0;i+j<=n;j++) rep(p,2) ans=min(ans,dp[n-i-j][i][j][p]);
	cout<<ans<<endl;
}