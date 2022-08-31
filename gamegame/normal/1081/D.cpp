#include<iostream>
#include<algorithm>
using namespace std;
#define fi first
#define se second
int n,m,k;
int sz[100001];
int par[100001];
bool sp[100001];
pair<int,pair<int,int> >a[100001];
int spc[100001];
int find(int x){
	if(par[x]!=x) par[x]=find(par[x]);
	return par[x];
}
bool join(int x,int y){
	x=find(x);y=find(y);
	if(x==y) return true;
	if(sp[x]) swap(x,y);
	if(sz[x]+sz[y]==k) return false;
	par[x]=y;
	sz[y]+=sz[x];
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i=1; i<=k ;i++){
		cin >> spc[i];
		sp[spc[i]]=true;
		sz[spc[i]]=1;
	}
	for(int i=1; i<=n ;i++) par[i]=i;
	for(int i=1; i<=m ;i++){
		cin >> a[i].se.fi >> a[i].se.se >> a[i].fi;
	}
	sort(a+1,a+m+1);
	int good;
	for(int i=1; i<=m ;i++){
		if(!join(a[i].se.fi,a[i].se.se)){
			for(int j=1; j<=k ;j++) cout << a[i].fi << ' ';
			return 0;
		}
	}
}