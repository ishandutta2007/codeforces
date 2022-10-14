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
int dis[100000+20],mini[100000+20];
vector<pair<int,bool> > g[100000+20];
mp las[100000+20];
int n,m;
map<mp,int> id;
int ok[100000+20];
pair<mp,int> edges[100000+20];
int main(){
	scanf("%d %d",&n,&m);
	int total=0;
	rb(i,1,m){
		int u,v,z;
		scanf("%d %d %d",&u,&v,&z);
		edges[i]=II(II(u,v),z);
		g[u].PB(II(v,z));
		g[v].PB(II(u,z)); 
		id[II(u,v)]=id[II(v,u)]=i; 
		total+=!z;
	}
	memset(dis,63,sizeof(dis));
	priority_queue<pair<LL,int> ,vector<pair<LL,int> > ,greater<pair<LL,int> > > q;
	q.push(II(0,1));
	dis[1]=0;
	while(!q.empty()){
		pair<LL,int> now=q.top();
		q.pop();
		if(dis[now.SEC]!=now.FIR) continue;
		for(auto it:g[now.SEC]){
			if(dis[it.FIR]>now.FIR+1){
				dis[it.FIR]=now.FIR+1;
				q.push(II(dis[it.FIR],it.FIR));
			}
		}	
	}
	memset(mini,63,sizeof(mini));
	q.push(II(0,1));
	mini[1]=0;
	while(!q.empty()){
		pair<LL,int> now=q.top();
		q.pop();
		if(mini[now.SEC]!=now.FIR) continue;
		for(auto it:g[now.SEC]){
			if(dis[it.FIR]==dis[now.SEC]+1)
				if(mini[it.FIR]>now.FIR+(!it.SEC)){
					las[it.FIR]=II(now.SEC,it.SEC);
					mini[it.FIR]=now.FIR+(!it.SEC);
					q.push(II(mini[it.FIR],it.FIR));
				}
		}	
	}
	cout<<(m-dis[n]-(total-mini[n])+mini[n])<<endl;
	int now=n;
	do{
		ok[id[II(now,las[now].FIR)]]=1;
		if(las[now].SEC==0){
			cout<<now<<" "<<las[now].FIR<<" 1\n";
		}
		now=las[now].FIR;
	}while(now!=1);
	rb(i,1,m){
		if(!ok[i]&&edges[i].SEC==1){
			cout<<edges[i].FIR.FIR<<" "<<edges[i].FIR.SEC<<" 0"<<endl;
		}
	}
	return 0;
}