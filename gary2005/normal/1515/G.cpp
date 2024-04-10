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
const int MAXN=2e5+233;
int n,m; 
vector<int> g[MAXN],rg[MAXN];
bool vis[MAXN];
int belong[MAXN];
int cnt=0;
stack<int> sta;
LL x[MAXN];
void dfs1(int now){
	vis[now]=1;
	for(auto it:g[now]){
		if(!vis[it]) dfs1(it);
	}
	sta.push(now);
}
void dfs2(int now){
	vis[now]=1;
	belong[now]=cnt;
	for(auto it:rg[now]){
		if(!vis[it]) dfs2(it);
	}
}
LL mygcd(LL x,LL y){
	if(y==0) return x;
	return mygcd(y,x%y); 
}
vector<mp> gg[MAXN];
vector<mp > E[MAXN],E2[MAXN];
vector<pair<mp,int> > Ehave[MAXN];
LL dist1[MAXN];
LL dist2[MAXN];
bool visit[MAXN][2];
void dfs1_(int now){
	visit[now][0]=1;
	for(auto it:E[now]){
		if(!visit[it.FIR][0]){
			dist1[it.FIR]=dist1[now]+it.SEC;
			dfs1_(it.FIR);
		}
		else{
			x[belong[now]]=mygcd(x[belong[now]],abs(dist1[it.FIR]-(dist1[now]+it.SEC)));
		}
	}
}
void dfs2_(int now){
	visit[now][1]=1;
	for(auto it:E2[now]){
		if(!visit[it.FIR][1]){
			dist2[it.FIR]=dist2[now]+it.SEC;
			dfs2_(it.FIR);
		}
		else{
			x[belong[now]]=mygcd(x[belong[now]],abs(dist2[it.FIR]-(dist2[now]+it.SEC)));
		}
	}
}
int main(){
	srand(time(0));
	scanf("%d%d",&n,&m);
	rb(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v);
		rg[v].PB(u);
		g[u].PB(v);
		int l;
		scanf("%d",&l);
		gg[u].PB(II(v,l));
	}
	rb(i,1,n) if(!vis[i]) dfs1(i);
	memset(vis,0,sizeof(vis));
	while(!sta.empty()){
		int now=sta.top();
		sta.pop();
		if(!vis[now]){
			++cnt;
			dfs2(now);
		}
	}
	rb(i,1,n){
		for(auto it:gg[i]){
			if(belong[it.FIR]==belong[i]){
				Ehave[belong[i]].PB(II(II(i,it.FIR),it.SEC));
				E[i].PB(it);
				E2[it.FIR].PB(II(i,it.SEC));
			}
		}
	}
	rb(i,1,n) if(!visit[i][0]){
		dfs1_(i);
		dfs2_(i);
	}
//	rb(i,1,n){
//		cout<<belong[i]<<" "<<i<<":"<<dist1[i]+dist2[i]<<endl;
//	}
	rb(i,1,n) x[belong[i]]=mygcd(x[belong[i]],dist1[i]+dist2[i]);
//	rb(i,1,n) cout<<i<<":"<<x[belong[i]]<<endl;
	int q;
	scanf("%d",&q);
	while(q--){
		int v,s,t;
		scanf("%d%d%d",&v,&s,&t);
		if(!x[belong[v]]){
			puts(s==0? "YES":"NO");
		}
		else{
			s=t-s;
			int vv=mygcd(t,x[belong[v]]);
			puts(s%vv==0? "YES":"NO");
		}
	}
	return 0;
}