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
int par[1000005],ran[1000005];
void init(){ for(int i=0;i<1000005;i++) par[i] = i; }
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
int n,m,sz[1000005],flag;
vector<int>edge[1000005];
int C = 0;
vector<int>num;
int main(){
	scanf("%d%d",&n,&m);
	init();
	rep(i,m){
		int a,b;scanf("%d%d",&a,&b);
		if(a == b){
		        C++;
		        num.pb(a);
		}
		else{
		
			edge[a].pb(b);
			edge[b].pb(a);
			unite(a,b);
		}
	}
	repn(i,n) rep(j,edge[i].size()) sz[find(i)]|=1;
	rep(i,num.size()) sz[find(num[i])]|=1;
	repn(i,n) flag+=(sz[i]);
	if(flag >= 2){
		cout << 0 << endl;
		return 0;
	}
	ll ans = 0;
	repn(i,n){
		int a = edge[i].size();
		ans += 1LL*a*(a-1)/2;
	}
	ans += 1LL*C*(m-1);
	ans -= 1LL*C*(C-1)/2;
	cout << ans << endl;
}