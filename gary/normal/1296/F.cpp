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
int f[5005],n;
vector<mp> each[5005];
pair<int,mp> pp[5005];
void pr(int x){
	cout<<(x? x:1)<<" ";
}
bool cmp(pair<int,mp> A,pair<int,mp> B){
	return A>B;
}
int ok=0;
void dfs(int now,int aim,int  pre,int col){
	if(now==aim){
		ok=1;
	}
	else
	for(auto it:each[now]){
		if(it.FIR==pre) continue;
		dfs(it.FIR,aim,now,col);
		if(ok)
		{
			if(!f[it.SEC]){
				f[it.SEC]=col;
			}
			break;
		}
	}
}
int res=INF;
void dfs2(int now,int aim,int pre=-1){
	if(now==aim){
		ok=1;
	}
	else
	for(auto it:each[now]){
		if(it.FIR==pre) continue;
		dfs2(it.FIR,aim,now);
		if(ok){
			res=min(res,f[it.SEC]);
			break;
		}
	}
}int m;
bool check(){
	rb(i,1,m){
		ok=0;
		res=INF;dfs2(pp[i].SEC.FIR,pp[i].SEC.SEC);
		if(res==pp[i].FIR);
		else return 0;
	}
	return 1;
}
int main(){
	fastio;	
	cin>>n;
	rb(i,2,n)
	{
		int u,v;
		cin>>u>>v;
		each[u].PB(II(v,i));
		each[v].PB(II(u,i));
	}
	
	cin>>m;
	rb(i,1,m){
		int a,b,g;
		cin>>a>>b>>g;
		pp[i]=II(g,II(a,b));
	}
	sort(pp+1,pp+1+m,cmp);
	rb(i,1,m){
		ok=0;
		dfs(pp[i].SEC.FIR,pp[i].SEC.SEC,-1,pp[i].FIR);
	}
	if(!check()){
		cout<<-1;
		return 0;
	}
	rb(i,2,n)
		pr(f[i]);
	return 0;
}