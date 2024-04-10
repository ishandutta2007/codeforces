#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 800005
//#define M 1000005
#define MXN 100005
#define pi 3.14159265359
#define cpdd const pdd
using namespace std;
typedef long long LL;
int N,fa[MXN],belong[MXN],dep[MXN],sz[MXN],que[MXN];
int step,line[MXN],stPt[MXN],edPt[MXN];
vector<int> E[MXN], chain[MXN];
void init(){
	for(int i=1;i<=N;i++){
		E[i].clear();
		chain[i].clear();
	}
}
void DFS(int u){
    vector<int> &c = chain[belong[u]];
    for (int i=c.size()-1; i>=0; i--){
        int v = c[i];
        stPt[v] = step;
        line[step++] = v;
    }
    for (int i=0; i<(int)c.size(); i++){
        u = c[i];
        for (auto v : E[u]){
            if (fa[u] == v || (i && v == c[i-1])) continue;
            DFS(v);
        }
        edPt[u] = step-1;
    }
}
void build_chain(int st){
    int fr,bk;
    fr=bk=0; que[bk++] = 1; fa[st]=st; dep[st]=0;
    while (fr < bk){
        int u=que[fr++];
        for (auto v : E[u]){
            if (v == fa[u]) continue;
            que[bk++] = v;
            dep[v] = dep[u]+1;
            fa[v] = u;
        }
    }
    for (int i=bk-1,u,pos; i>=0; i--){
        u = que[i]; sz[u] = 1; pos = -1;
        for (auto v : E[u]){
            if (v == fa[u]) continue;
            sz[u] += sz[v];
            if (pos==-1 || sz[v]>sz[pos]) pos=v;
        }
        if (pos == -1) belong[u] = u;
        else belong[u] = belong[pos];
        chain[belong[u]].pb(u);
    }
    step = 0;
    DFS(st);
}
int getLCA(int u, int v){
    while (belong[u] != belong[v]){
        int a = chain[belong[u]].back();
        int b = chain[belong[v]].back();
        if (dep[a] > dep[b]) u = fa[a];
        else v = fa[b];
    }
    return sz[u] >= sz[v] ? u : v;
}
vector<pii> getPathSeg(int u, int v){
    vector<pii> ret1,ret2;
    while (belong[u] != belong[v]){
        int a = chain[belong[u]].back();
        int b = chain[belong[v]].back();
        if (dep[a] > dep[b]){
            ret1.pb(mp(stPt[a],stPt[u]));
            u = fa[a];
            } else {
            ret2.pb(mp(stPt[b],stPt[v]));
            v = fa[b];
        }
    }
    if (dep[u] > dep[v]) swap(u,v);
    ret1.pb(mp(stPt[u],stPt[v]));
    reverse(ret2.begin(), ret2.end());
    ret1.insert(ret1.end(),ret2.begin(),ret2.end());
    return ret1;
}
// Usage
void build(){
    build_chain(1); //change root
}

int main()
{
	int q;
	scanf("%d %d",&N,&q);
	for(int i=2;i<=N;i++){
		int a;
		scanf("%d",&a);
		E[a].pb(i);
		E[i].pb(a);
	}
	build();
	while(q--){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		int d=getLCA(a,c);
		int e=getLCA(a,b);
		int f=getLCA(b,c);
		int dis[3];
		dis[0]=(dep[a]+dep[b]-2*dep[e]);
		dis[1]=(dep[b]+dep[c]-2*dep[f]);
		dis[2]=(dep[a]+dep[c]-2*dep[d]);
	//	printf("%d %d %d\n",d,e,f);
	//	printf("%d %d %d\n",(dep[a]+dep[b]-2*dep[e]),(dep[b]+dep[c]-2*dep[f]),(dep[a]+dep[c]-2*dep[d]));
		sort(dis,dis+3);
		printf("%d\n",(dis[2]+dis[1]-dis[0])/2+1);
	}
}
/*
3 2
1 1
1 2 3
2 3 3


4 1
1 2 3
1 2 3
*/