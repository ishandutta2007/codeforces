#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
int n,m;
string f[2005];
int ans;
vector<P>vec;
vector<P>pos;
vector<int>val[2005],rui[2005],rui2[2005];
bool reduction(int vabl){
	rep(i,n){
		val[i].resize(m,0);
		rui[i].resize(m,0);
		rui2[i].resize(m,0);
	}
	rep(i,n) rep(j,m) val[i][j] = rui[i][j] = rui2[i][j] = 0;
	rep(i,pos.size()){
		val[pos[i].fi][pos[i].sc] ++;
	}
	rep(i,n) rep(j,m){
		rui[i][j] = val[i][j];
		if(i) rui[i][j] += rui[i-1][j];
		if(j) rui[i][j] += rui[i][j-1];
		if(i && j) rui[i][j] -= rui[i-1][j-1];
	}
	vec.clear();
	rep(i,n) rep(j,m){
		{
			if(0<=i && i+2*vabl < n && 0<= j && j+2*vabl < m){
				int x = rui[i+2*vabl][j+2*vabl];
				if(i) x -= rui[i-1][j+2*vabl];
				if(j) x -= rui[i+2*vabl][j-1];
				if(i && j) x += rui[i-1][j-1];
				if(x == (2*vabl+1)*(2*vabl+1)){
					vec.pb(mp(i+vabl,j+vabl));
					rui2[i][j]++;
					if(i+2*vabl+1 < n) rui2[i+2*vabl+1][j]--;
					if(j+2*vabl+1 < m) rui2[i][j+2*vabl+1]--;
					if(i+2*vabl+1 < n && j+2*vabl+1 < m){
						rui2[i+2*vabl+1][j+2*vabl+1]++;
					}
				}
			}
		}
	}
	rep(i,n)rep(j,m){
		if(i) rui2[i][j] += rui2[i-1][j];
		if(j) rui2[i][j] += rui2[i][j-1];
		if(i && j) rui2[i][j] -= rui2[i-1][j-1];
	}
	rep(i,n)rep(j,m){
		if(val[i][j] == 1 && rui2[i][j] == 0) return false;
	}
	return true;
}
void solve(){
	//n <= 1000
	rep(i,n) rep(j,m) if(f[i][j] == 'X') pos.pb(P(i,j));
	int lb = 0, ub = 505;
	while(ub-lb > 1){
		int mid = (lb+ub)/2;
		vec.clear();
		bool flag = reduction(mid);
	//	cout<< mid << flag << endl;
		if(!flag) ub = mid;
		else lb = mid;
	}
	ans = lb;
	vec.clear();
	reduction(ans);
	return ;
}

int main(){
	scanf("%d%d",&n,&m);
	if(n < m){
		for(int i=0;i<n;i++){
			cin >> f[i];
		}
		solve();
		SORT(vec);
		int nxt = 0;
		vector<string>ret;
		ret.resize(n);
		for(int i=0;i<n;i++){
			string add; add.resize(m);
			for(int j=0;j<m;j++){
				add[j] = '.';
			}
			ret[i] = add;
		}
		rep(i,vec.size()) ret[vec[i].fi][vec[i].sc] = 'X';
		printf("%d\n",ans);
		rep(i,n){
			rep(j,m) printf("%c",ret[i][j]);
			puts("");
		}
	}
	else{
		rep(j,m) f[j].resize(n);
		for(int i=0;i<n;i++){
			string s; cin >> s;
			rep(j,m){
				f[j][i] = s[j];
			}
		}
		swap(n,m);
		solve();
		swap(n,m);
		vector<string>ret;
		ret.resize(n);
		for(int i=0;i<n;i++){
			string add; add.resize(m);
			for(int j=0;j<m;j++){
				add[j] = '.';
			}
			ret[i] = add;
		}
		rep(i,vec.size()) ret[vec[i].sc][vec[i].fi] = 'X';
		printf("%d\n",ans);
		rep(i,n){
			rep(j,m) printf("%c",ret[i][j]);
			puts("");
		}
	}
}