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
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
struct kf{
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
}kaede;
ll ans[100005];
int main(){
	cin>>n;
	kaede.init();
	for(int i=2;i<=n;i++){
		for(int j=2;i*j<=n;j++){
			kaede.unite(i*j,i);
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=2;i*j<=n;j++){
			ans[kaede.find(i)] += 4LL*j;
		}
	}
	ll A = 0;
	for(int i=0;i<100005;i++) A = max(A,ans[i]);
	cout<<A<<endl;
}