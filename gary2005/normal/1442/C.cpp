/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int N=18;
int n,m;
mp dist[N+2][2][200000+1];
vector<int> g[2][200000+1];
int main(){
	scanf("%d%d",&n,&m);
	priority_queue<pair<mp,pair<mp,int> > ,vector<pair<mp,pair<mp,int> > > ,greater<pair<mp,pair<mp,int> > > > q;
	rb(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v);
		g[0][u].PB(v);
		g[1][v].PB(u);
	}
	rb(i,0,N+1)
		rep(j,2)
			rb(k,1,n)
				dist[i][j][k]=II(INF,INF);
	dist[0][0][1]=II(0,0);
	q.push(II(II(0,0),II(II(0,0),1)));
	while(!q.empty()){
		mp val=q.top().FIR;
		int i,j,k;
		i=q.top().SEC.FIR.FIR;
		j=q.top().SEC.FIR.SEC;
		k=q.top().SEC.SEC;
		q.pop();
		if(dist[i][j][k]!=val) continue;
//		cout<<j<<' '<<k<<' '<<val.FIR<<' '<<val.SEC<<endl;
		for(auto it:g[j][k]){
			mp tmp=val;
			tmp.second++;
//			cout<<it<<' '<<dist[i][j][it].FIR<<endl;
			if(tmp<dist[i][j][it]){
				dist[i][j][it]=tmp;
				q.push(II(dist[i][j][it],II(II(i,j),it)));
			}
		}
		val.first++;
		j^=1;
		for(auto it:g[j][k]){
			mp tmp=val;
			tmp.second++;
			if(tmp<dist[min(N+1,val.FIR)][j][it]){
				dist[min(N+1,val.FIR)][j][it]=tmp;
				q.push(II(dist[min(N+1,val.FIR)][j][it],II(II(min(N+1,val.FIR),j),it)));
			}
		}	
	}
	int rest=INF;
	rb(i,0,N){
		rep(j,2){
			check_min(rest,dist[i][j][n].SEC+(1<<i)-1);
		}
	}
	if(rest!=INF){
		cout<<rest<<endl;
	}
	else{
		int MOD=998244353;
		check_min(dist[N+1][0][n],dist[N+1][1][n]);
		int rest=1;
		rb(i,1,dist[N+1][0][n].first)
			rest=1ll*rest*2%MOD;
		rest--;
		rest+=dist[N+1][0][n].SEC;
		rest%=MOD;
		cout<<(rest+MOD)%MOD<<endl;
	}
	return 0;
}
/** 
  *  
  *
  *
  *
  **/