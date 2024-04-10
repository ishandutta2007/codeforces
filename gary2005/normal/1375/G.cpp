/*
{By GWj
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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int cnt[2];
vector<int> g[200000+1];
void dfs(int now,int pre=0,int col=0){
	cnt[col]++;
	for(auto it:g[now]){
		if(it!=pre){
			dfs(it,now,col^1);
		}
	}
}
int main(){
	int n;
	cin>>n;
	rb(i,1,n-1){
		int u,v;
		R2(u,v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1);
	cout<<min(cnt[0],cnt[1])-1<<endl;
	return 0;
}