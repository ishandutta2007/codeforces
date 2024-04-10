#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 100005
struct Scc{
    int n, nScc, vst[MXN], bln[MXN];
    vector<int> E[MXN], rE[MXN], vec;
    void init(int _n){
        n = _n;
        for (int i=0; i<MXN; i++){
            E[i].clear();
            rE[i].clear();
        }
    }
    void add_edge(int u, int v){
        E[u].pb(v);
        rE[v].pb(u);
    }
    void DFS(int u){
        vst[u]=1;
        for (auto v : E[u])
        if (!vst[v]) DFS(v);
        vec.pb(u);
    }
    void rDFS(int u){
        vst[u] = 1;
        bln[u] = nScc;
        for (auto v : rE[u])
        if (!vst[v]) rDFS(v);
    }
    void solve(){
        nScc = 0;
        vec.clear();
        MEM(vst);
        for (int i=1; i<=n; i++)
        if (!vst[i]) DFS(i);
        reverse(vec.begin(),vec.end());
        MEM(vst);
        for (auto v : vec){
            if (!vst[v]){
                rDFS(v);
                nScc++;
            }
        }
    }
}g;
int dp[100005][55];
int vst[100005][55];
vector<int> v[100005];
char open[100005][55];
int ok[100005];
int t=0;
int DP(int x,int y,int d){
	if(dp[x][y]!=-1)return dp[x][y];
	++t;
	dp[x][y]=0;
	vector<pii> q;
	q.pb(mp(x,y));
	vector<pii> temp;
	vector<pii> go;
	int tot=0;
	for(int i=0;i<q.size();i++){
		pii p=q[i];
		//printf("%d %d\n",p.x,p.y);
		if(open[p.x][p.y]=='1'&&ok[p.x]!=t)
		tot++,ok[p.x]=t;
		temp.pb(p);
		for(auto it:v[p.x]){
			if(g.bln[it]!=g.bln[x]){
				//printf("!%d %d\n",p.x,it);
				go.pb(mp(it,(p.y+1)%d));
			}
			if(!vst[it][(p.y+1)%d]&&g.bln[it]==g.bln[x]){
			//	printf("?%d %d\n",p.x,it);
				vst[it][(p.y+1)%d]=1;
				q.pb(mp(it,(p.y+1)%d));
			}
		}
	//	printf("%d %d\n",i,q.size());
	}
	dp[x][y]=tot;
	for(auto it:go)
	dp[x][y]=max(dp[x][y],tot+DP(it.x,it.y,d));
	for(auto it:temp)
	dp[it.x][it.y]=dp[x][y];
	return dp[x][y];
}
int main(){
	int n,m,d;
	scanf("%d %d %d",&n,&m,&d);
	g.init(n);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].pb(y);
		g.add_edge(x,y);
	}
	g.solve();
	for(int i=1;i<=n;i++)
	scanf("%s",open[i]);
	MEMS(dp);
	printf("%d\n",DP(1,0,d));
	/*
	queue<pii> q;
	q.push(mp(1,0));
	while(!q.empty()){
		pii p=q.front();
		q.pop();
		for(auto it:v[p.x]){
			if(!vis[it][(p.y+1)%d]){
				vis[it][(p.y+1)%d]=1;
				q.push(mp(it,(p.y+1)%d));
			}
		}
	}*/
}