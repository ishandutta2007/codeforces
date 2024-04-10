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
int n,a[105];
int par[105],ran[105];
void init(){ for(int i=0;i<105;i++) par[i] = i; }
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
int cnt[105];
int main(){
	cin >> n; init();
	for(int i=1;i<=n;i++){
		cin >> a[i]; cnt[a[i]]++; if(cnt[a[i]] >= 2){ puts("-1"); return 0;}
		unite(i,a[i]);
	}
	ll ans = 1;
	for(int i=1;i<=n;i++){
		if(find(i) != i) continue;
		int c = 0;
		for(int j=1;j<=n;j++) if(find(j) == i) c++;
		if(c%2 == 0) c/=2;
		ans = ans/__gcd(ans,1LL*c)*c;
	}
	cout << ans << endl;
}