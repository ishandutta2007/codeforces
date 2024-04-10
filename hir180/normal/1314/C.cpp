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


int NN,k;
int ran[100005];
int tmp[100005];
int sa[100005];

bool compare_sa(int i,int j)
{
	if(ran[i] != ran[j]) return ran[i] < ran[j];
	else
	{
		int ri = i+k<=NN ? ran[i+k]: -1;
		int rj = j+k<=NN ? ran[j+k]: -1;
		
		return ri < rj;
	}
}

void construct_sa(string S)
{
	NN = S.size();
	for(int i=0;i<=NN;i++)
	{
		sa[i] = i;
		ran[i] = i<NN?S[i]:-1;
	}
	
	for(k=1;k<=NN;k*=2)
	{
		sort(sa,sa+NN+1,compare_sa);
		
		tmp[sa[0]] = 0;
		for(int i=1;i<=NN;i++)
		{
			tmp[sa[i]] = tmp[sa[i-1]] + compare_sa(sa[i-1],sa[i]);
		}
		for(int i=0;i<=NN;i++)
		{
			ran[i] = tmp[i];
		}
	}
}
int lcp[100005];
void construct_lcp(string S)
{
	int n = S.size();
	for(int i=0;i<=n;i++) ran[sa[i]] = i;
	
	int h = 0;
	lcp[0] = 0;
	
	for(int i=0;i<n;i++)
	{
		int j = sa[ran[i]-1];
		
		if(h) h--;
		for(;j+h<n && i+h<n;h++)
		{
			if(S[j+h] != S[i+h]) break;
		}
		lcp[ran[i]-1] = h;
	}
}
struct seg{
	#define BIT 20
	#define sz 100005
	vector<int>mn[BIT],bb;
	seg(){
		rep(j,BIT) mn[j].resize(sz,INF);
		bb.resize(sz,0);
		repn(i,sz-1){
			rep(j,BIT){
				if((1<<j) <= i && i <= (2<<j)){
					bb[i] = j;
					break;
				}
			}
		}
	}
	void update(int a,int v){
		mn[0][a] = v;
	}
	void make(){
		rep(j,BIT-1){
			rep(i,sz){
				if(i+(1<<j) >= sz) mn[j+1][i] = mn[j][i];
				else mn[j+1][i] = min(mn[j][i],mn[j][i+(1<<j)]);
			}
		}
	}
	int query(int a,int b){
		if(a > b) return INF;
		int ss = bb[b-a+1];
		return min(mn[ss][a], mn[ss][b-(1<<ss)+1]);
	}
}kaede;

int n,m;;
ll kk;
vector<P>vec;
string s;
int get_lcp(int a,int b){
	int ra = ran[a];
	int rb = ran[b];
	if(ra > rb) swap(ra,rb);
	return kaede.query(ra,rb-1);
}
bool cmp(const P&a, const P&b){
	if(a.fi == b.fi) return a.sc < b.sc;
	
	int lcplen = get_lcp(a.fi,b.fi);
	if(min(a.sc-a.fi+1, b.sc-b.fi+1) <= lcplen){
		return a.sc-a.fi+1 < b.sc-b.fi+1;
	}
	else{
		char na = s[a.fi+lcplen];
		char nb = s[b.fi+lcplen];
		return na < nb;
	}
}
bool cmpeq(const P&a, const P&b){
	if(a.fi == b.fi) return a.sc <= b.sc;
	
	int lcplen = get_lcp(a.fi,b.fi);
	if(min(a.sc-a.fi+1, b.sc-b.fi+1) <= lcplen){
		return a.sc-a.fi+1 <= b.sc-b.fi+1;
	}
	else{
		char na = s[a.fi+lcplen];
		char nb = s[b.fi+lcplen];
		return na <= nb;
	}
}
ll dp[1005][1005];
ll rui[1005][1005];
int ok[1005];
ll calc(int a,int b){
	//[a,b]subsegment
	rep(i,n){
		if(i == a){
			ok[i] = b;
			continue;
		}
		int lb = i-1, ub = n;
		while(ub-lb > 1){
			int mid = (lb+ub)/2;
			if(cmpeq(P(a,b),P(i,mid))) ub = mid;
			else lb = mid;
		}
		ok[i] = ub;
	}
	memset(rui,0,sizeof(rui));
	memset(dp,0,sizeof(dp));
	dp[n][0] = 1;
	rui[n][0] = 1;
	for(int i=n-1;i>=0;i--){
		int x = ok[i];
		rui[i][0] = 1;
		for(int j=1;j<=m;j++){
			dp[i][j] = rui[x+1][j-1];
			rui[i][j] += dp[i][j];
			rui[i][j] += rui[i+1][j];
			rui[i][j] = min(rui[i][j],2LL*kk);
		}
	}
	return dp[0][m];
}
int main(){
	cin >> n >> m >> kk >> s;
	construct_sa(s);
	construct_lcp(s);
	for(int i=1;i<n;i++){
		kaede.update(i,lcp[i]);
	}
	kaede.make();
	rep(i,n){
		for(int j=i;j<n;j++){
			vec.pb(P(i,j));
		}
	}
	sort(vec.begin(),vec.end(),cmp);
	int lb = 0, ub = vec.size();
	while(ub-lb > 1){
		int mid = (lb+ub)/2;
		ll get = calc(vec[mid].fi, vec[mid].sc);
		if(get >= kk) lb = mid;
		else ub = mid;
	}
	
	for(int a=vec[lb].fi;a<=vec[lb].sc;a++) printf("%c",s[a]);
	puts("");
	return 0;
}