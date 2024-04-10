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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m,w;
int a[1005],b[1005];
ll dp[2][1005];
int par[1005],ran[1005];
void init(){ for(int i=0;i<1005;i++) par[i] = i; }
int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
void unite(int x,int y){
	x = find(x); y = find(y); if(x==y) return;
	if(ran[x] < ran[y]) par[x] = y;
	else{
		par[y] = x;
		if(ran[x] == ran[y]) ran[x]++;
	}
}
bool same(int x,int y){ return find(x)==find(y); }
int main(){
	cin >> n >> m >> w; init();
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	for(int i=0;i<m;i++){
		int a,b; scanf("%d%d",&a,&b);
		unite(a,b);
	}
	dp[0][0] = dp[1][0] = 0;
	for(int i=1;i<1005;i++) dp[0][i] = dp[1][i] = 0;
	int cur = 0,nxt = 1;
	for(int i=1;i<=n;i++){
		if(find(i) != i) continue;
		dp[nxt][0] = 0;
		for(int i=1;i<1005;i++) dp[nxt][i] = 0;
		vector<int>vi;
		int sumw = 0; ll sumb = 0;
		for(int j=1;j<=n;j++) if(find(j) == i){
			vi.pb(j);
			sumw += a[j];
			sumb += b[j];
		}
		//all
		for(int i=1004;i>=sumw;i--){
			if(dp[cur][i-sumw] < 0LL) continue;
			dp[nxt][i] = max(dp[nxt][i],dp[cur][i-sumw]+sumb);
		}
		//one
		for(int i=0;i<vi.size();i++){
			for(int j=1004;j>=a[vi[i]];j--){
				if(dp[cur][j-a[vi[i]]] < 0LL) continue;
				dp[nxt][j] = max(dp[nxt][j],dp[cur][j-a[vi[i]]] + b[vi[i]]);
			}
		}
		//zero
		for(int i=1004;i>=0;i--){
			if(dp[cur][i] < 0LL) continue;
			dp[nxt][i] = max(dp[nxt][i],dp[cur][i]);
		}
		swap(cur,nxt);
	}
	ll res = 0;
	for(int i=0;i<=w;i++) res = max(res,dp[cur][i]);
	cout << res << endl;
}