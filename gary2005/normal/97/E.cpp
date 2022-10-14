/*
{

AuThOr Gwj
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
int n,low[200000+1],m,fa[200000+1][19],cnt,root[200000+1],R,depth[200000+1];
vector<int> g[200000+1],g2[200000+1];
vector<int> roots;
bool vis[200000+10],can[200000+20];
bool odd[200000+10];
int sum[200000+10];
stack<int> st;
void dfs(int now,int pre=0,int deep=1){
	low[now]=depth[now]=deep;
	vis[now]=1;
	root[now]=R;
	st.push(now); 
	for(auto it:g[now]){
		if(it==pre) continue;
		if(vis[it]){
			check_min(low[now],depth[it]);
		}
		else{
			dfs(it,now,deep+1);
			check_min(low[now],low[it]);
			if(low[it]>=depth[now]){
				int is;
				++cnt;
				do{
					is=st.top();
					st.pop();
					g2[cnt].PB(is);
					g2[is].PB(cnt);
				}while(is!=it);
				g2[now].PB(cnt);
				g2[cnt].PB(now);
			}
		}
	}
//	cout<<now<<" "<<pre<<" "<<low[now]<<endl;
}
int colo[200000+10];
bool try_paint(int now,int col=1){
	vis[now]=1;
	colo[now]=col;
	for(auto it:g[now]){
		if(!can[it]) continue;
		if(vis[it]){
			if(col==colo[it]){
				return 0;
			}
		}
		else{
			if(!try_paint(it,col^1)) return 0;
		}
	}
	return 1;
}
void dfs2(int now,int deep=1){
	vis[now]=1;
	depth[now]=deep;
	for(auto it:g[now]){
		if(!vis[it]){
			dfs2(it,deep+1);
		}
	}
} 
void dfs3(int now,int pre=0,int deep=1){
	depth[now]=deep+1;
	fa[now][0]=pre;
	rb(i,1,18)
		fa[now][i]=fa[fa[now][i-1]][i-1];
	sum[now]+=odd[now];
	for(auto it:g2[now]){
		if(it!=pre){
			sum[it]+=sum[now];
			dfs3(it,now,deep+1);
		}
	}
//	cout<<now<<"summ"<<sum[now]<<" "<<pre<<endl;
}
int lca(int u,int v){
	if(depth[u]>depth[v]) swap(u,v);
	int jump=depth[v]-depth[u];
	rep(i,19){
		if((jump>>i)&1){
			v=fa[v][i];
		}
	}
	if(u==v) return v;
//	cout<<"lca of "<<u<<"&"<<v<<"is"; 
	rl(i,18,0){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	}
//	cout<<fa[u][0]<<"\n";
	return fa[u][0];
}
mp query[200000+2];
bool rest[200000+2];
int main(){
	fastio;
	R2(n,m);
	cnt=n;
	rb(i,1,m){
		int u,v;
		R2(u,v);
		g[u].PB(v);
		g[v].PB(u);
	}
	rb(i,1,n){
		if(!vis[i]){
			R=i;
//			cout<<"R="<<i<<endl;
			roots.PB(i);
			while(!st.empty())
			st.pop();
			dfs(i);
		}
	}
//	cout<<root[2]<<"-"<<root[4]<<endl;
//	cout<<endl;
//	rb(i,1,cnt){
//		for(auto it:g2[i])
//		{
//			if(it>i){
//				cout<<i<<" "<<it<<endl; 
//			}
//		}
//	}
	memset(vis,0,sizeof(vis));
	rb(i,n+1,cnt){
		for(auto it:g2[i]){
			can[it]=1;
		}	
		odd[i]=!try_paint(g2[i][0]);
//		cout<<i<<"--"<<odd[i]<<endl;
		for(auto it:g2[i]){
			can[it]=0;
			vis[it]=0;
		}
	}
	for(auto it:roots){
		dfs2(it);
	}
	int qqq;
	R(qqq);
	rb(i,1,qqq){
		R2(query[i].FIR,query[i].SEC);
		if(root[query[i].FIR]==root[query[i].SEC])
			if((depth[query[i].FIR]+depth[query[i].SEC])&1){
				rest[i]=1;
			}
	}
	for(auto it:roots){
		dfs3(it);
	}
	rb(i,1,qqq){
		int a,b;
		a=query[i].FIR;
		b=query[i].SEC;
		if(root[a]!=root[b]) continue;
		int lcc=lca(a,b);
		lcc=fa[lcc][0];
		if(sum[a]+sum[b]-2*sum[lcc]){
			rest[i]=1;
		}
	}
	rb(i,1,qqq){
		if(query[i].FIR==query[i].SEC) rest[i]=0;
		cout<<(rest[i]? "Yes\n":"No\n");
	}
	return 0;
}
/*
20 20
15 13
8 20
1 12
1 16
18 16
12 19
16 12
11 16
9 20
8 9
3 7
12 17
8 2
18 19
5 20
3 16
17 2
9 11
3 18
20 18
5
1 1
1 2
1 3
1 4
1 5


*/