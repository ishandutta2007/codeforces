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
int n,m,a,b,v[200000+1];
vector<int> each[200000+1];
void dfs(int now,int color,int aim){
	if(v[now]==color||v[now]==3) return ;
	if(v[now]&&v[now]!=color) v[now]=3;
	else v[now]=color;
	if(aim==now) return ;
	for(auto it:each[now]){
		dfs(it,color,aim);
	}
}
void mian(){
	cin>>n>>m>>a>>b;
	rb(i,1,n)each[i].clear(),v[i]=0;
	rb(i,1,m){
		int u,v;
		cin>>u>>v;
		each[u].PB(v);
		each[v].PB(u);
	}
	dfs(a,1,b);
	dfs(b,2,a);
	int A,B;
	A=B=0;
	rb(i,1,n){
		if(v[i]==1){
			A++;
		}
		if(v[i]==2){
			B++;
		}
	}
	cout<<(LL)A*B<<endl;
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		mian();
	}
	return 0;
}