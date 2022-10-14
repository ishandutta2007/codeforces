/*
{

AuThOr Gwj
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
const int MAXN=100000+20;
vector<int> g[MAXN];
int siz[MAXN];
vector<LL> calc;
void dfs(int now,int pre=0){
	siz[now]=1;
	for(auto it:g[now]){
		if(it==pre ) continue;
		dfs(it,now);
		siz[now]+=siz[it];
	}
	for(auto it:g[now]){
		if(it==pre) continue;
		calc.PB((LL)(n-siz[it])*siz[it]);
	} 
}
void solve(){
	calc.clear();
	R(n);
	rb(i,1,n)
		siz[i]=0,g[i].clear();
	rb(i,1,n-1){
		int u,v;
		R2(u,v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1,0);
	sort(ALL(calc));
	rep(i,n-1)
		calc[i]%=(int)(1e9+7);
	vector<LL> pr;
	int m;
	R(m);
	rb(i,1,m)
	{
		int pp;
		R(pp);
		pr.PB(pp);
	}
	rb(i,1,n-1-m){
		pr.PB(1);
	}
	sort(ALL(pr));
	rb(i,1,m-(n-1)){
		LL b1,b2;
		b1=pr.back();
		pr.POB();
		b2=pr.back();
		pr.POB();
		pr.PB(b1*b2%(int)(1e9+7));
	}
//	for(auto it:calc){
//		cout<<it<<",";
//	}
//	cout<<endl;
	LL rest=0;
	rep(i,n-1){
		rest+=calc[i]*pr[i]%(int)(1e9+7);
		rest%=(int)1e9+7;
	}
	cout<<rest<<endl;
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}