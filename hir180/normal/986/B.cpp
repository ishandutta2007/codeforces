#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
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
int main(){
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		unite(i,a);
	}
	int cnt = 0;
	for(int i=1;i<=n;i++) if(find(i) == i) cnt++;
	int dif = n-cnt;
	if(n%2 == 1){
		puts(dif%2==1?"Petr":"Um_nik");
	}
	else{
		puts(dif%2==0?"Petr":"Um_nik");
	}
}