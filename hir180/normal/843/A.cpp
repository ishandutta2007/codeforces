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
P  a[100005];
struct u{
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
}uf;
vector<int>vec[100005];
int main(){
	cin>>n;
	repn(i,n){
		int x; cin>>x;
		a[i] = mp(x,i);
	}
	uf.init();
	sort(a+1,a+n+1);
	repn(i,n){
		uf.unite(i,a[i].sc);
	}
	repn(i,n){
		vec[uf.find(i)].pb(i);
	}
	int C = 0;
	repn(i,n) if(vec[i].size()) C++;
	cout<<C<<endl;
	repn(i,n) if(vec[i].size()){
		printf("%d ",vec[i].size());
		rep(j,vec[i].size()) printf("%d ",vec[i][j]);
		puts("");
	}
}