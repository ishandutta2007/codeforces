/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
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
int n,m;
int k;
LL dis[100000+20];
priority_queue<pair<LL,int>,vector<pair<LL,int> > ,greater<pair<LL,int> > > q;
vector<mp> g[100000+20];
bool ty[100000+20];
int main(){
	fastio;
	cin>>n>>m>>k;
	int rest=0;
	rb(i,1,m){
		int u,v,x;
		cin>>u>>v>>x;
		g[u].PB(II(v,x));
		g[v].PB(II(u,x));
	}
	memset(dis,127,sizeof(dis));
	rb(i,1,k){
		int s;LL y;
		R2(s,y);
		check_min(dis[s],y);
		ty[s]=1;
	}
	dis[1]=0;
	rb(i,1,n)
	{
		if(dis[i]!=dis[n+2]){
			q.push(II(dis[i],i));
		}
	}
	while(!q.empty()){
		pair<LL,int> now=q.top();
		q.pop();
		if(dis[now.SEC]!=now.FIR) continue;
		for(auto it:g[now.SEC]){
			if(dis[it.FIR]>=dis[now.SEC]+it.SEC){
				bool ok=(dis[it.FIR]!=dis[now.SEC]+it.SEC);
				dis[it.FIR]=dis[now.SEC]+it.SEC;
				ty[it.FIR]=0;
				if(ok)
				q.push(II(dis[it.FIR],it.FIR));
			}
		}
	}
	rb(i,1,n) rest+=ty[i];
	rest=k-rest;
	cout<<rest<<endl;
	return 0;
}