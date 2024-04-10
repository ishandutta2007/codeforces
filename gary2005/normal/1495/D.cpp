/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=404;
int n,m;
int dis[MAXN][MAXN];
vector<int> g[MAXN];
int d[MAXN];
int ty[MAXN];
void run(int now,int t){
	d[now]=0;
	if(t==now) return;
	for(auto it:g[now]){
		if(dis[it][t]==dis[now][t]-1){
			run(it,t);
			return;
		}
	}
}
int solve(int s,int t){
	memset(d,63,sizeof(d));
	run(s,t);
	queue<int> q;
	rb(i,1,n) if(!d[i]) q.push(i);
	rb(i,1,n){
		if(dis[s][i]+dis[s][t]==dis[t][i]) ty[i]=1;
		else if(dis[t][i]+dis[s][t]==dis[s][i]) ty[i]=2;
		else ty[i]=3;
	}
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(auto it:g[now]){
			if(d[it]==INF){
				d[it]=d[now]+1;
				q.push(it);
			}
		}
	}
	int rest=1;
	rb(i,1,n) if(ty[i]==3){
		if(d[i]*2+dis[s][t]!=dis[s][i]+dis[t][i]) return 0;
	}
	rb(i,1,n){
		int cnt=0;
		if(i==s||i==t) continue;
		if(ty[i]==1){
			for(auto it:g[i]) if(dis[it][s]==dis[i][s]-1) cnt++;
		}
		if(ty[i]==2){
			for(auto it:g[i]) if(dis[it][t]==dis[i][t]-1) cnt++;	
		}
		if(ty[i]==3){
			if(d[i]){
				for(auto it:g[i]) if(d[it]==d[i]-1) cnt++;}	
			else
				cnt=1;
//			cout<<i<<"__"<<cnt<<" "<<d[i]<<endl;
		}
		rest=1ll*rest*cnt%998244353; 
	}
	return rest;
}
int main(){
	scanf("%d%d",&n,&m);
	memset(dis,63,sizeof(dis));
	rb(i,1,n) dis[i][i]=0; 
	rb(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
		dis[u][v]=dis[v][u]=1;
	}
	rb(k,1,n) rb(i,1,n) rb(j,1,n) check_min(dis[i][j],dis[i][k]+dis[k][j]);
//	cout<<solve(5,6)<<endl;
//	return 0;
	rb(i,1,n){
		rb(j,1,n){
			printf("%d ",solve(i,j));
		}
		printf("\n");
	}
	return 0;
}