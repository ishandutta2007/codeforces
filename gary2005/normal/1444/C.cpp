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
const int MAXN=500000+20;
int n,m,k;
int belong[MAXN],ty[MAXN];
int col[2*MAXN],bad_group[MAXN];
vector<int> g[2*MAXN];
bool vis[2*MAXN];
int cnt=0;
int Col[2*MAXN];
void dfs(int now){
	vis[now]=1;
	Col[cnt+cnt]=col[now];
	Col[cnt+cnt-1]=col[now];
	belong[now]=cnt;
	for(auto it:g[now]){
		if(col[it]!=col[now]) continue;
		if(vis[it]){
			if(ty[it]==ty[now]){
				bad_group[col[now]]=1;
			}
		}
		else{
			ty[it]=ty[now]^1;
			dfs(it);
		}
	}
}
map<mp,vector<mp> > M;
void add_edge(int C1,int C2,int u,int v){
	if(C1>C2) swap(C1,C2);
	M[II(C1,C2)].PB(II(u,v));
}
bool dfs_check(int now,int color){
	vis[now]=true;
	Col[now]=color;
	for(auto it:g[now]){
		if(!vis[it]){
			if(!dfs_check(it,color^1)) return false;
		}
		else{
			if(Col[it]==color) return false;
		} 
	}
	if(!vis[now^1]){
		if(!dfs_check(now^1,color^1)) return false;
	}
	else{
		if(Col[now^1]==color) return false;
	}
	return true;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rb(i,1,n) scanf("%d",&col[i]);
	rb(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
	}
	rb(i,1,n){
		if(!vis[i]){
			dfs(i);
		}
	}	
	memset(vis,0,sizeof(vis));
	rb(i,1,n)
		if(!bad_group[col[i]])
			if(!vis[i]){
				ty[i]=0;
				++cnt;
				dfs(i);
			}
	rb(i,1,n)
		if(!bad_group[col[i]]){
			for(auto it:g[i]){
				if(col[it]!=col[i])
					if(!bad_group[col[it]]){
						add_edge(col[i],col[it],belong[i]*2-2+ty[i],belong[it]*2-2+ty[it]);
					}		
			}
		}
	int ZZ=k-1;
	LL rest=1ll*(k)*(k-1)/2; 
	rb(i,1,k){
		if(bad_group[i]){
			rest-=ZZ--;
		}
	}
	memset(vis,0,sizeof(vis));
	rb(i,1,n) g[i].clear();
	for(auto ite=M.begin();ite!=M.end();ite++){
				for(auto it: ite->SEC){
					int u,v;
					u=it.FIR;
					v=it.SEC;
					g[u].PB(v);
					g[v].PB(u);
				}
				bool can=1;
				for(auto it: ite->SEC){
					int u,v;
					u=it.FIR;
					v=it.SEC;
					if(!vis[u]){
						can&=dfs_check(u,0);
					}
					if(!vis[v]){
						can&=dfs_check(v,0);
					}
				}
				rest-=!can;
				for(auto it: ite->SEC){
					int u,v;
					u=it.FIR;
					v=it.SEC;
					vis[u]=vis[v]=vis[u^1]=vis[v^1]=0;
					g[u].clear();
					g[v].clear();
					g[u^1].clear();
					g[v^1].clear();
				}
	}
	cout<<rest<<endl;
	return 0;
}