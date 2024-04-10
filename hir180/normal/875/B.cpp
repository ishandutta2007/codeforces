#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
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
int n,a[300005];
bool used[300005];
int par[300005],ran[300005];
void init(){ for(int i=0;i<300005;i++) par[i] = i;}
void make(int k){ ran[k] = 1; }
int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
void unite(int x,int y){
	x = find(x); y = find(y); if(x==y) return;
	if(ran[x] < ran[y]){
		par[x] = y;
		ran[y] += ran[x];
	}
	else{
		par[y] = x;
		ran[x] += ran[y];
	}
}
bool same(int x,int y){ return find(x)==find(y); }
int main(){
	cin>>n;
	printf("1 ");
	init();
	repn(i,n){
		scanf("%d",&a[i]); make(a[i]); used[a[i]] = 1;
		if(used[a[i]+1]) unite(a[i],a[i]+1);
		if(used[a[i]-1]) unite(a[i],a[i]-1);
		printf("%d ",1+i-ran[find(n)]);
	}puts("");
}