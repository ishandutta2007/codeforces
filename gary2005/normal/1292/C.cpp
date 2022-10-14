/*
AuThOr GaRyMr
*/
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int kids[3003][3003];bool v[3003][3003];LL dp[3003][3003];
short n;
mp las[3003][3003];
vector<mp> store[3003];
vector<int> each[3003];
int calc(int i,int j){
	if(v[i][j]) return kids[i][j];
	kids[i][j]=1;
	for(auto it:each[i]){
		if(it!=j)
			kids[i][j]+=calc(it,i);
	}
	return kids[i][j];
}
void dfs(int a,int b,int c,int d,int len){
	if(v[a][b]) return;
	v[a][b]++; 
	las[a][b]=II(c,d);//inn
	store[len].PB(II(a,b));
	for(auto it:each[a])
		if(it!=c)
			dfs(it,b,a,d,len+1);
	for(auto it:each[b])
		if(it!=d)
			dfs(a,it,c,b,len+1);
}
int main(){
	fastio;
	cin>>n;
	rb(i,1,n-1){
		int u,v;
		cin>>u>>v;
		each[u].PB(v);
		each[v].PB(u);
	}
	rb(i,1,n)
		for(auto it:each[i])
			calc(i,it);
	memset(v,0,sizeof(v));
	rb(i,1,n)
		for(auto it:each[i])
			dfs(i,it,it,i,1);
	LL res=0;
	for(auto it:store[1]){
		dp[it.FIR][it.SEC]=kids[it.FIR][it.SEC]*kids[it.SEC][it.FIR];
		res=max(res,dp[it.FIR][it.SEC]);
//		cout<<it.FIR<<" "<<it.SEC<<" "<<res<<endl;
	}
	rb(i,2,n)
		if(store[i].empty()) break;
		else
		for(auto it:store[i]){
			int u=it.FIR,v=it.SEC,c,d;
			c=las[u][v].FIR;
			d=las[u][v].SEC;
			dp[u][v]=max(dp[c][v],dp[u][d]);
			dp[u][v]+=kids[u][c]*kids[v][d];
			res=max(res,dp[u][v]);
		}
	cout<<res<<endl;	
	return 0;
}