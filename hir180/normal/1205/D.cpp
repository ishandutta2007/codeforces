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
vector<int>edge[1005];
int n;
bool rem[200005]={};
int sub[200005]={},len;
int ind;
int make(int v,int u)
{
	int cnt=1;
	for(int i=0;i<edge[v].size();i++)
	{
		int v2=edge[v][i];
		if(rem[v2] || v2==u) continue;
		cnt+=make(v2,v);
	}
	return sub[v]=cnt;
}
P search(int v,int u,int siz)
{
	//size and index
	P res=mp(INF,-1);
	int s=1,m=0;
	for(int i=0;i<edge[v].size();i++)
	{
		int v2=edge[v][i];
		if(rem[v2] || v2==u) continue;
		res=min(res,search(v2,v,siz));
		m=max(m,sub[v2]);
		s+=sub[v2];
	}
	m=max(m,siz-s);
	res=min(res,mp(m,v));
	return res;
}
int nxt;
map<P,int>M;
void dfss(int v,int u,int up,int coef){
	assert(nxt > up);
	M[mp(v,u)] = coef*(nxt-up);
	nxt++; int rt = nxt-1;
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		dfss(edge[v][i],v,rt,coef);
	}
}
void sol(int v)
{
	make(v,-1);
	int cent=search(v,-1,sub[v]).sc;
	make(cent,-1);
	vector<P>vec;
	rep(i,edge[cent].size()){
		vec.pb(mp(sub[edge[cent][i]],edge[cent][i]));
	}
	int m = 0;
	int need = (2*n*n)/9;
	SORT(vec); reverse(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++){
		m += vec[i].fi;
		if( (m+1)*(n-m-1)+m >= need ){
			nxt = 1;
			for(int j=0;j<=i;j++){
				dfss(vec[j].sc,cent,0,1);
			}
			assert(nxt == m+1);
			nxt = 1;
			for(int j=i+1;j<vec.size();j++){
				dfss(vec[j].sc,cent,0,m+1);
			}
			assert(nxt == n-m);
			for(auto A:M){
				cout << A.fi.fi << " " << A.fi.sc << " " << A.sc << endl;
			}
			return;
		}
	}
	reverse(vec.begin(),vec.end());
	m = 0;
	for(int i=0;i<vec.size();i++){
		m += vec[i].fi;
		if( (m+1)*(n-m-1)+m >= need ){
			nxt = 1;
			for(int j=0;j<=i;j++){
				dfss(vec[j].sc,cent,0,1);
			}
			assert(nxt == m+1);
			nxt = 1;
			for(int j=i+1;j<vec.size();j++){
				dfss(vec[j].sc,cent,0,m+1);
			}
			assert(nxt == n-m);
			for(auto A:M){
				cout << A.fi.fi << " " << A.fi.sc << " " << A.sc << endl;
			}
			return;
		}
	}
}
int main(){
	cin >> n;
	rep(i,n-1){
		int a,b; cin >> a >> b;
		edge[a].pb(b); edge[b].pb(a);
	}
	sol(1);
}