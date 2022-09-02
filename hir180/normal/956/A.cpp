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
struct kaede{
	int par[55],ran[55];
	void init(){ for(int i=0;i<55;i++) par[i] = i; }
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
}t,y;
int n,m;
string f[55];
int main(){
	t.init(); y.init();
	cin>>n>>m; rep(i,n)cin>>f[i];
	rep(i,n){
		for(int j=0;j<m;j++) for(int k=j+1;k<m;k++){
			if(f[i][j] == '#' && f[i][k] == '#'){
				y.unite(j,k);
			}
		}
	}
	rep(i,m){
		for(int j=0;j<n;j++) for(int k=j+1;k<n;k++){
			if(f[j][i] == '#' && f[k][i] == '#'){
				t.unite(j,k);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(t.find(i) != i) continue;
		for(int j=0;j<m;j++){
			if(y.find(j) != j) continue;
			vector<int>A,B;
			for(int k=0;k<n;k++) if(t.find(k) == i) A.pb(k);
			for(int k=0;k<m;k++) if(y.find(k) == j) B.pb(k);
			int ff = 0;
			rep(k,A.size()) rep(l,B.size()){
				if(f[A[k]][B[l]] == '.'){
					ff|=1;
				}
				else ff|=2;
			}
			if(ff == 3){
			    puts("No");return 0;
			}
		}
	}
	puts("Yes");
}