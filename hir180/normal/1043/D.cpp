#include <bits/stdc++.h>
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
#define POSR(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m;
int p[100005][11];
int nxt[100005];
int par[100005],ran[100005];
void init(){ for(int i=0;i<100005;i++) par[i] = i; }
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
int cnt[100005];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,m){
		repn(j,n) scanf("%d",&p[j][i]);
		repn(j,n-1){
			int x = p[j][i];
			int y = p[j+1][i];
			if(i == 0){
				nxt[x] = y;
			}
			else if(nxt[x] != y){
				nxt[x] = -1;
			}
		}
		nxt[p[n][i]] = -1;
	}
	init();
	for(int i=1;i<=n;i++){
		if(nxt[i] != -1){
			unite(i,nxt[i]);
		}
	}
	for(int i=1;i<=n;i++){
		cnt[find(i)]++;
	}
	ll ans = 0;
	for(int i=1;i<=n;i++){
		ans += 1LL*cnt[i]*(cnt[i]+1)/2;
	}
	cout << ans << endl;
}