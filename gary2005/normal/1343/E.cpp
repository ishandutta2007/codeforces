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
int dis[3][200000+20];
int n,m,a,b,c;
vector<int> g[200000+2];
LL p[200000+2];
void bfs(int now,int index){
	rb(i,1,n)
		dis[index][i]=-1;
	dis[index][now]=0;
	queue<int> q;
	q.push(now);
	while(!q.empty()){
		int pro=q.front();
		q.pop();
		for(auto it:g[pro]){
			if(dis[index][it]==-1){
				dis[index][it]=1+dis[index][pro];
				q.push(it);	
			}
		}
	}
}
void solve(){
	cin>>n>>m>>a>>b>>c;
	rb(i,1,n)
	g[i].clear();	
	rb(i,1,m) cin>>p[i];sort(p+1,p+1+m);
	rb(i,1,m){
		int a_,b_;
		cin>>a_>>b_;
		g[a_].PB(b_);
		g[b_].PB(a_);
	}
	rb(i,1,m) p[i]+=p[i-1];
	//val->prefix_sum
	bfs(a,0);
	bfs(b,1);
	bfs(c,2);
//	cout<<dis[0][4]<<endl;
	LL res=20000000000000000;
	rb(i,1,n){
		//i
		if(dis[0][i]+dis[2][i]+dis[1][i]>m) continue;
		res=min(res,p[dis[1][i]]+p[dis[0][i]+dis[2][i]+dis[1][i]]);
//		cout<<dis[1][i]<<" "<<dis[0][i]<<" "<<
	}
	cout<<res<<endl;
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--)
	solve();	
	return 0;
}