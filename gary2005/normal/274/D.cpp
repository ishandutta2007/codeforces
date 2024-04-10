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
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m,v;
vector<int> res;
int vis[100000+20];
vector<int> g[300000+20];
void dfs(int now){
	vis[now]=1;
	for(auto it:g[now]){
		if(vis[it]==1) {
			cout<<-1<<endl;exit(0);
		}
		if(!vis[it])
		dfs(it);
	}
	vis[now]=2;
	if(now<m) res.PB(now);
}
int main(){
	fastio;
	cin>>n>>m;
	vector<vector<int> > a(n,vector<int>(m));
	rep(i,n)rep(j,m) cin>>a[i][j];
	v=m-1;
	rep(i,n){
		vector<mp> vec;
		rep(j,m) if(a[i][j]!=-1) vec.PB(II(a[i][j],j));
		sort(ALL(vec));
		int las=INF;
		for(auto it:vec){
			int j=it.SEC;
			if(las==it.FIR){
				
				g[v].PB(j),g[j].PB(v+1);	
			}
			else{
				v++;
				g[v].PB(j),g[j].PB(v+1);
			}
//			cout<<v<<" ->"<<j<<endl;
//			cout<<j<<"->"<<v+1<<endl;
			las=it.FIR;
		}
		v++;
	}
	rep(i,m) if(!vis[i]) dfs(i);
	reverse(ALL(res));
	for(auto it:res) cout<<it+1<<" ";cout<<endl; 
	return 0;
}