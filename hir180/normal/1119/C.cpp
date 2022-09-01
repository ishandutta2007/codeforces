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
int n,m,a[505][505],b[505][505],f[505][505];
int x[505];
int main(){
	cin>>n>>m;
	rep(i,n)rep(j,m)cin>>a[i][j];
	rep(i,n)rep(j,m)cin>>b[i][j];
	rep(i,n)rep(j,m)f[i][j]=a[i][j]!=b[i][j];
	memset(x,0,sizeof(x));
	bool bad = 0;
	rep(i,n){
		int A = 0;
		rep(j,m) A ^= f[i][j];
		if(A == 1) bad = 1;
		rep(j,m) x[j] ^= f[i][j];
	}
	rep(j,m) if(x[j]) bad = 1;
	memset(x,0,sizeof(x));
	rep(j,m){
		int A = 0;
		rep(i,n) A ^= f[i][j];
		if(A == 1) bad = 1;
		rep(i,n) x[i] ^= f[i][j];
	}
	rep(i,n) if(x[i]) bad = 1;
	puts(bad?"No":"Yes");
}