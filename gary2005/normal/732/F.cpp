/*
AuThOr Gwj
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;	
const int MAXN=400000+20;
int n,m,belong[MAXN],cntBcc=0,depth[MAXN],siz[MAXN],low[MAXN];
bool vis[MAXN];
vector<int> g[MAXN];
map<mp,bool> dire;
stack<int> s;
void dfs(int now,int pre,int deep)
{
	vis[now]=1;
	s.push(now);
	depth[now]=low[now]=deep;
	for(auto it:g[now]){
		if(it!=pre){
			if(vis[it]){
				low[now]=min(low[now],depth[it]);
			}
			else{
				dfs(it,now,deep+1);
				low[now]=min(low[now],low[it]);
			}
		}
	}
	if(low[now]==deep){
		cntBcc++;
		while(!s.empty()){
			int index=s.top();
			s.pop();
			belong[index]=cntBcc;
			siz[cntBcc]++;
			if(index==now) break;
		}
	}
}
void dfs2(int now,int pre){
	vis[now]=1;
	for(auto it:g[now]){
		if(belong[it]==belong[now])
		if(it!=pre){
			if(!dire[II(it,now)])
			dire[II(now,it)]=1;
			if(!vis[it]){
				dfs2(it,now);
			}
		}
	}
}
void dfs3(int now,int pre,int deep=1){
	depth[now]=deep;
	for(auto it:g[now]){
		if(it!=pre){
			dfs3(it,now,deep+1);
		}
	}
}
int main(){
	fastio;
	R2(n,m);
	vector<mp> edges;
	rb(i,1,m){
		int u,v;
		R2(u,v);
		g[u].PB(v);
		g[v].PB(u);
		edges.PB(II(u,v)); 
	}
	dfs(1,0,1);
	int res=0;
//	cout<<cntBcc<<endl;
//	cout<<
	rb(i,1,cntBcc){
		res=max(res,siz[i]);
	}
	cout<<res<<endl;
	memset(vis,0,sizeof(vis));
	rb(i,1,n)
	{
		if(!vis[i]){
//			cout<<i<<""
			dfs2(i,0);
		}
	}
	n=cntBcc;
	rb(i,1,n) g[i].clear();
	rep(i,m){
		int u,v;
		u=edges[i].FIR;
		v=edges[i].SEC;
		u=belong[u];
		v=belong[v];
		if(u!=v){
			g[u].PB(v);
			g[v].PB(u);
		}
	}
	rb(i,1,n){
		if(siz[i]==res){
			dfs3(i,0,1);
			break;
		}
	}
	rep(i,m){
		int u,v;
		u=edges[i].FIR;
		v=edges[i].SEC;
		if(belong[u]!=belong[v]){
			if(depth[belong[u]]<depth[belong[v]]){
				swap(u,v);
			}
		}
		else{
			if(!dire[II(u,v)]) swap(u,v);
		}
		cout<<u<<" "<<v<<endl;
	}
	return 0;
}