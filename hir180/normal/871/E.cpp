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
#define rep(i,x) for(int i=0;i<x;i++)
int a[30005][205],n,b[205],m;
vector<int>edge[30005];
struct union_find{
	int par[30005],ran[30005];
	void init(){ for(int i=0;i<30005;i++) par[i] = i; }
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
}uf;
int num[30005];
bool used[30005];
ll pr = 17,pr2 = 33;
ll hashh[30005][2],hashh_one[30005][2];
map<pair<ll,ll>,int>M;
bool dfs(int v,int u,int d,int num){
	if(a[v][num] != d) return 1;
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == u) continue;
		if(dfs(edge[v][i],v,d+1,num)) return 1;
	}
	return 0;
}
int main(){
	cin>>n>>m;  uf.init();
	repn(j,m) repn(i,n){
		scanf("%d",&a[i][j]);
		if(a[i][j] == 0){
			if(b[j] != 0){
				puts("-1");
				return 0;
			}
			b[j] = i;
		}
	}
	repn(i,n){
		ll cur = pr,cur2 = pr2;
		repn(j,m){
			hashh[i][0] += a[i][j] * cur % mod;
			hashh_one[i][0] += (a[i][j]-1) * cur % mod;
			hashh[i][1] += a[i][j] * cur2 % mod;
			hashh_one[i][1] += (a[i][j]-1) * cur2 % mod;
			cur = cur*pr%mod; cur2 = cur2*pr2%mod;
		}
		rep(k,2){
			hashh[i][k] = (hashh[i][k]%mod+mod)%mod;
			hashh_one[i][k] = (hashh_one[i][k]%mod+mod)%mod;
		}
		M[mp(hashh[i][0],hashh[i][1])] = i;
	}
	repn(j,m) if(b[j] == 0){
		puts("-1");
		return 0;
	}
	for(int j=2;j<=m;j++){
		int D = INF;
		repn(i,n){
			D = min(D,a[i][1]+a[i][j]);
		}
		for(int i=0;i<=D;i++) num[i] = 0;
		repn(i,n){
			if(a[i][1]+a[i][j] == D){
				if(num[a[i][1]] != 0){
					puts("-1");
					return 0;
				}
				num[a[i][1]] = i;
			}
		}
		for(int i=0;i<=D;i++) if(num[i] == 0){
			puts("-1");
			return 0;
		}
		for(int i=0;i<D;i++){
			if(!uf.same(num[i],num[i+1])){
				edge[num[i]].pb(num[i+1]);
				edge[num[i+1]].pb(num[i]);
				uf.unite(num[i],num[i+1]);
			}
			used[num[i]] = 1;
			used[num[i+1]] = 1;
		}
	}
	for(int i=1;i<=m;i++) used[b[i]] = 1;
	for(int i=1;i<=m;i++){
		if(uf.find(b[1]) != uf.find(b[i])){
			puts("-1");
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(used[i]) continue;
		if(M.find(mp(hashh_one[i][0],hashh_one[i][1])) == M.end()){
			puts("-1");
			return 0;
		}
		int x = M[mp(hashh_one[i][0],hashh_one[i][1])];
		if(uf.same(i,x)){
			puts("-1");
			return 0;
		}
		edge[i].pb(x);
		edge[x].pb(i);
		uf.unite(i,x);
	}
	for(int i=1;i<=n;i++) if(!uf.same(1,i)){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=m;i++){
		bool flag = dfs(b[i],-1,0,i);
		if(flag){
			puts("-1");
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<edge[i].size();j++){
			if(i < edge[i][j]){
				printf("%d %d\n",i,edge[i][j]);
			}
		}
	}
	return 0;
}