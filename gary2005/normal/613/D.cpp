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
const int MAXN=1e5+233;
int cnt=0;
int dfn[MAXN];
int n;
vector<int> g[MAXN]; 
int depth[MAXN];
int in[MAXN],out[MAXN],fa[MAXN][17];
int tot=0;
void dfs(int now,int pre,int dep=0){
	dfn[now]=++cnt; 
	in[now]=++tot;
	depth[now]=dep;
	fa[now][0]=pre;
	rb(i,1,16) fa[now][i]=fa[fa[now][i-1]][i-1];
	for(auto it:g[now]) if(it!=pre) dfs(it,now,dep+1);
	out[now]=++tot;
}
int lg[1<<17];
int climb(int x,int y){
	while(y){
		x=fa[x][lg[y&(-y)]];
		y^=y&(-y);
	}
	return x;
}
int lca(int u,int v){
	if(depth[u]>depth[v]) swap(u,v);
	v=climb(v,depth[v]-depth[u]);
	if(u==v) return u;
	rl(i,16,0) if(fa[u][i]!=fa[v][i]) {u=fa[u][i],v=fa[v][i];}
	return fa[u][0];
}
bool cmp(int A,int B){
	return dfn[A]<dfn[B];
}
vector<int> vg[MAXN];
int vn;
vector<int> nodes;
int get(int now){
	for(int i=now+1;i<vn;++i){
		if(out[nodes[i]]<=out[nodes[now]]&&in[nodes[i]]>=in[nodes[now]]){
			vg[nodes[now]].PB(nodes[i]);
			i=get(i);
		}
		else{
			return i-1;
		}
	}
	return vn-1;
}
void v_tree(vector<int> v){
	sort(ALL(v),cmp);
	rep(i,v.size()) {
		if(v[i]!=1) nodes.PB(fa[v[i]][0]);	
		nodes.PB(v[i]);
	}
	rep(i,v.size()) if(i){
		nodes.PB(lca(v[i-1],v[i]));
	}
	sort(ALL(nodes));
	nodes.erase(unique(ALL(nodes)),nodes.end());
	sort(ALL(nodes),cmp);
	vn=nodes.size();
	get(0);
}
bool vis[MAXN][2];
int dp[MAXN][2];
void clear_(){
	for(auto it:nodes) vis[it][0]=vis[it][1]=0,dp[it][0]=dp[it][1]=INF;
	for(auto it:nodes) vg[it].clear();
	nodes.clear();
}
bool bad[MAXN];
int trans(int now,bool ty){
	vis[now][ty]=true;
	int& ret=dp[now][ty];
	int two[2][2];
	int pre_=0,now_=1;
	two[pre_][0]=0;
	two[pre_][1]=INF;
	for(auto it:vg[now]){
		two[now_][0]=two[now_][1]=INF;
		rep(i,2) {
			int val=(vis[it][i]? dp[it][i]:trans(it,i));
			rep(j,2){
				if(i&&j&&ty) continue; 
				check_min(two[now_][i|j],two[pre_][j]+val);
			}
		}
		swap(pre_,now_);
	}
	if(ty){
		if(bad[now]){
			check_min(ret,two[pre_][0]);
		}
		else{
			check_min(ret,two[pre_][1]);
		}
	}
	else{
		if(!bad[now]){
			check_min(ret,two[pre_][0]);
			check_min(ret,two[pre_][1]+1); 
		}
	}
	return ret;
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	memset(dp,63,sizeof(dp));
	int q;
	scanf("%d",&n);
	rb(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1,0);
	rb(i,0,16)
		lg[1<<i]=i;
	scanf("%d",&q);
	rb(T,1,q){
		int m;
		scanf("%d",&m);
		vector<int> que;
		rb(i,1,m){
			int ai;
			scanf("%d",&ai);
			que.PB(ai);
		}
		clear_();
		v_tree(que);
		int root=nodes[0];
		for(auto it:que) bad[it]=true;
		int rest = min(trans(root,0),trans(root,1));
		if(rest==INF) rest=-1;
		printf("%d\n",rest);
		for(auto it:que) bad[it]=false;
	}
	return 0;
}

/*

4 4
1 3
2 3
4 3
2 1 2
3 2 3 4
3 1 2 4
4 1 2 3 4

9 4
1 2
1 3
1 4
1 5
3 6
3 7
7 8
7 9

3 9 8 5
2 9 5
2 9 1
4 9 8 3 5
*/