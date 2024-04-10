#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define N 100010
const int mod=1e9+7;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
struct Basis{
	int d[5];
	Basis(){memset(d,0,sizeof(d));}
	bool Insert(int x){
		for(int i=4;i>=0;--i){
			if((x>>i)&1){
				if(!d[i]){
					d[i]=x;
					return true;
				}
				else{
					x^=d[i];
				}
			}
		}
		return false;
	}
	void Normal(){
		for(int i=4;i>=0;--i){
			if(!d[i])continue;
			for(int j=i+1;j<=4;++j){
				if((d[j]>>i)&1)d[j]^=d[i];
			}
		}
	} 
	void assign(int x){
		d[0]=x&1;
		d[1]=(x>>1)&3;
		d[2]=(x>>3)&7;
		d[3]=(x>>6)&15;
		d[4]=(x>>10)&31;
	}
	int H(){
		return d[0]|d[1]<<1|d[2]<<3|d[3]<<6|d[4]<<10;
	} 
}g[N]; 
int n,m,t[N],vis[133333],tot,st[1111],cnt,b[N],root[N],dfn[N],num,ans;
int to[380][380];
int dp[N][380];
int cirw[N];
bool ok[N],cir[N];
vector<pair<int,int> > G[N];
void init(Basis u){
	u.Normal();
	if(!vis[u.H()]){
		vis[u.H()]=++tot;
		st[tot]=u.H();	
	}
	else{
		return;
	}
	for(int i=1;i<(1<<5);++i){
		Basis tmp=u;
		if(tmp.Insert(i)){
			init(tmp);
		}
	}
}
void init_trans(){
	for(int i=1;i<=tot;++i){
		Basis myh;
		myh.assign(st[i]);
		for(int j=1;j<=tot;++j){
			Basis wzp;
			wzp.assign(st[j]);
			bool ok=true;
			for(int k=0;k<=4;++k){
				if(myh.d[k]){
					if(!wzp.Insert(myh.d[k]))ok=false;
				}
			}
			wzp.Normal();
			if(ok)to[i][j]=vis[wzp.H()];
		}
	}
}
void dfs(int u,int fa,int id){
	b[u]=id;
	dfn[u]=++num;
	for(auto qwq:G[u]){
		int v=qwq.first,w=qwq.second;
		if(v==fa)continue;
		if(!dfn[v]){
			t[v]=t[u]^w;
			dfs(v,u,id);
		}
		else if(v^1&&dfn[v]<dfn[u]){
			if(!g[id].Insert(t[u]^t[v]^w)){
				ok[id]=false;
			}
		}
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
	}
	init(Basis());
	init_trans();
	dfn[1]=++num;
	for(auto qwq:G[1]){
		int v=qwq.first,w=qwq.second;
		if(!b[v]){
			++cnt;
			ok[cnt]=true,cir[cnt]=false;
			root[cnt]=v;
			t[v]=cirw[cnt]=w;
			dfs(v,1,cnt);
		}
		else{
			for(auto s:G[v]){
				if(s.first==root[b[v]]){
					cirw[b[v]]^=s.second^w;
					cir[b[v]]=true;
				}
			}
		}
	}
	dp[0][1]=1;
	for(int i=1;i<=cnt;++i){
		memcpy(dp[i],dp[i-1],sizeof(dp[i]));
		if(!ok[i])continue;
		g[i].Normal();
		int u=vis[g[i].H()];
		if(!cir[i]){
			for(int j=1;j<=tot;++j){
				if(to[u][j]){
					dp[i][to[u][j]]=(dp[i][to[u][j]]+dp[i-1][j])%mod;
				}
			}
		}
		else{
			Basis cqz=g[i];
			int v=0;
			if(cqz.Insert(cirw[i])){
				cqz.Normal();
				v=vis[cqz.H()];
			}
			for(int j=1;j<=tot;++j){
				if(to[u][j]){
					dp[i][to[u][j]]=(dp[i][to[u][j]]+2*dp[i-1][j]%mod)%mod;
				}
				if(to[v][j]){
					dp[i][to[v][j]]=(dp[i][to[v][j]]+dp[i-1][j])%mod;
				}
			}
		}
	}
	for(int i=1;i<=tot;++i){
		ans=(ans+dp[cnt][i])%mod;
	}
	cout<<ans<<endl;
	return 0;
}