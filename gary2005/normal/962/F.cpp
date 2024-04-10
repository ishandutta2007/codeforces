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
const int MAXN=1e5+20;
int n,m,belong[MAXN],bccCnt,depth[MAXN],low[MAXN];
int bccHave[MAXN];
int ok[MAXN];
bool vis[MAXN];
int firstEdge[MAXN],nex[MAXN*2],edgeCnt,to[MAXN*2];
void addEdge(int u,int v){
	edgeCnt++;
	nex[edgeCnt]=firstEdge[u];
	firstEdge[u]=edgeCnt;
	to[edgeCnt]=v;
}
vector<int> g[MAXN];
stack<int> s;
void dfs(int now,int pre,int deep){
	s.push(now);
	depth[now]=deep;
	low[now]=deep;
	vis[now]=1;
	for(int Is=firstEdge[now];Is;Is=nex[Is]){
		int it=to[Is];
		if(it!=pre){
			if(!vis[it]) dfs(it,now,deep+1),low[now]=min(low[now],low[it]);
			else low[now]=min(low[now],depth[it]);
		}
	}
	if(low[now]==deep){
		bccCnt++;
		while(!s.empty()){
			int index=s.top();
			s.pop();
			belong[index]=bccCnt;
			bccHave[bccCnt]=index;
			if(index==now) break;
		}
	}	
}
int heavy[MAXN],top[MAXN],cnt,dfn[MAXN],siz[MAXN],fa[MAXN][18],cover[MAXN];
int preFix[MAXN];
void dfs1(int now,int pre,int deep){
//	cout<<now<<"-"<<pre<<endl;
	depth[now]=deep;
	fa[now][0]=pre;
	rb(i,1,17){
		fa[now][i]=fa[fa[now][i-1]][i-1];
	}
	siz[now]=1;
	vis[now]=1;
	for(int Is=firstEdge[now];Is;Is=nex[Is]){
		int it=to[Is];
		if(belong[it]==belong[now])
		if(it!=pre&&!vis[it]){
			dfs1(it,now,deep+1);
			siz[now]+=siz[it];
		}
	}
	for(int Is=firstEdge[now];Is;Is=nex[Is]){
		int it=to[Is];
		if(belong[it]==belong[now])
		if(it!=pre&&depth[it]-1==depth[now]){
			if(siz[it]*2>=siz[now]){
//				cout<<now<<" "<<it<<" "<<depth[it]<<" "<<depth[now]<<endl;
				heavy[now]=it;
			}
		}
	}
}
void dfs2(int now,int pre){
	vis[now]=1;
	dfn[now]=++cnt;
	if(heavy[now]){
		top[heavy[now]]=top[now];
		dfs2(heavy[now],now);
	}
	for(int Is=firstEdge[now];Is;Is=nex[Is]){
		int it=to[Is];
		if(belong[it]==belong[now])
		if(it!=pre&&!vis[it]&&it!=heavy[now]){
			top[it]=it;
			dfs2(it,now);
		}
	}
}
int jump(int u,int deep){
	int now=u;
	rl(i,17,0){
		if(fa[now][i]&&depth[fa[now][i]]>=deep){
			now=fa[now][i];
		}
	}
	return now;
}
void dfs3(int now,int pre){
	vis[now]=1;
	for(int Is=firstEdge[now];Is;Is=nex[Is]){
		int it=to[Is];
		if(belong[it]==belong[now])
		if(it!=pre){
			if(!vis[it]){
				dfs3(it,now);
			}
			else{
				if(depth[now]<depth[it]) continue;
				int stand=now,closeAncient;
				closeAncient=jump(stand,depth[it]+1);
				while(stand&&depth[stand]>depth[it]){
					if(depth[top[stand]]>depth[it]){
						preFix[dfn[top[stand]]]++;
						preFix[dfn[stand]+1]--;		
					}
					else{
						preFix[dfn[closeAncient]]++;
						preFix[dfn[stand]+1]--;
					}
					stand=fa[top[stand]][0];
				}
			}
		}
	}
}
void dfs4(int now,int pre){
	vis[now]=1;
	for(int Is=firstEdge[now];Is;Is=nex[Is]){
		int it=to[Is];
		if(belong[it]==belong[now])
		if(it!=pre){
			if(!vis[it]){
				dfs4(it,now);
			}
			else{
				if(depth[now]<depth[it]) continue;
				int stand=now,closeAncient;
				closeAncient=jump(stand,depth[it]+1);
				bool flag=0;
				while(stand&&depth[stand]>depth[it]){
					int l,r;
					if(depth[top[stand]]>depth[it]){
						l=dfn[top[stand]];
						r=dfn[stand];
					}
					else{
						l=dfn[closeAncient];
						r=dfn[stand];
					}
					if(preFix[r]-preFix[l-1]){
						flag=1;
						break;
					}
					stand=fa[top[stand]][0];
				}
				if(flag){
				stand=now;
				while(stand&&depth[stand]>depth[it]){
					int l,r;
					if(depth[top[stand]]>depth[it]){
						l=dfn[top[stand]];
						r=dfn[stand];
					}
					else{
						l=dfn[closeAncient];
						r=dfn[stand];
					}
					ok[l]++;
					ok[r+1]--;
					stand=fa[top[stand]][0];
					}
				}
			}
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
		edges.PB(II(u,v));
		addEdge(u,v);
		addEdge(v,u);
	}
	rb(i,1,n)
	if(!vis[i])
	dfs(i,0,1);
	memset(vis,0,sizeof(vis));
	rb(i,1,bccCnt){
		dfs1(bccHave[i],0,1);
	}
	memset(vis,0,sizeof(vis));
	cnt=0;
	rb(i,1,bccCnt){
		top[bccHave[i]]=bccHave[i];
		dfs2(bccHave[i],0);
	}
	memset(vis,0,sizeof(vis));
	rb(i,1,bccCnt){
		dfs3(bccHave[i],0);
	}
	rb(i,1,n)
		preFix[i]+=preFix[i-1];
	rb(i,1,n)
		if(preFix[i]) preFix[i]--; 
	rb(i,1,n)
		preFix[i]+=preFix[i-1];
	memset(vis,0,sizeof(vis));
	rb(i,1,bccCnt){
		dfs4(bccHave[i],0);
	}
	rb(i,1,n)
	{
		ok[i]+=ok[i-1];
	}
	rb(i,1,n)
		if(ok[i]) ok[i]=1;
	rb(i,1,n) ok[i]=1 xor ok[i];
	vector<int> res;
	rep(i,m){
		int u,v;
		u=edges[i].FIR;
		v=edges[i].SEC;
		if(belong[u]==belong[v]){
			if(depth[u]<depth[v]) swap(u,v);
			if(ok[dfn[u]]){
				res.PB(i+1);
			}
		}
	}
	cout<<res.size()<<endl;
	for(auto it:res) cout<<it<<" ";
	return 0;
}