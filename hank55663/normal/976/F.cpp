#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct Dinic{
    static const int MXN = 10000;
    struct Edge{ int v,f,re,num; Edge(int a,int b,int c, int num):v(a),f(b),re(c),num(num){}};
    int n,s,t,level[MXN];
    vector<Edge> E[MXN];
	int cnt[MXN];
    void init(int _n, int _s, int _t){
        n = _n; s = _s; t = _t;
		fill(cnt,cnt+MXN,0);
        for (int i=0; i<=n; i++) E[i].clear();
    }
    void add_edge(int u, int v, int f,int num){
	//	printf("%d %d %d %d\n",u,v,f,num);
        E[u].pb(Edge(v,f,E[v].size(),num));
        E[v].pb(Edge(u,0,E[u].size()-1,-num));//direct
    }
    bool BFS(){
        MEMS(level);
        queue<int> que;
        que.push(s);
        level[s] = 0;
        while (!que.empty()){
            int u = que.front(); que.pop();
            for (auto it : E[u]){
                if (it.f > 0 && level[it.v] == -1){
                    level[it.v] = level[u]+1;
                    que.push(it.v);
                }
            }
        }
        return level[t] != -1;
    }
    int DFS(int u, int nf){
        if (u == t) return nf;
        int res = 0;
        for (auto &it : E[u]){
            if (it.f > 0 && level[it.v] == level[u]+1){
                int tf = DFS(it.v, min(nf,it.f));
                res += tf; nf -= tf; it.f -= tf;
                E[it.v][it.re].f += tf;
				if(tf){
					if(it.num<0){
					//	printf("s:%d %d\n",it.num,it.f);
						assert(cnt[-it.num]);
						cnt[-it.num]=0;
					}
					else if(it.num>0){
						//printf("s:%d %d\n",it.num,it.f);
						assert(!cnt[it.num]);
						cnt[it.num]=1;
					}
				}
				if (nf == 0) return res;
            }
        }
        if (!res) level[u] = -1;
        return res;
    }
    vector<int> flow(int res=0){
        while ( BFS() )
        res += DFS(s,2147483647);
		vector<int> ans;
		for(int i = 1;i<2005;i++){
			if(cnt[i])
				ans.pb(i);
		}
		//printf("%d\n",res);
        return ans;
    }
}flow;

int main(){
	int a,b,m;
	scanf("%d %d %d",&a,&b,&m);
	int degreea[2005],degreeb[2005];
	fill(degreea,degreea+2005,0);
	fill(degreeb,degreeb+2005,0);
	flow.init(a+b+20,a+b+1,a+b+2);
	int k=1e9;
	for(int i = 1;i<=m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		degreea[x]++;
		degreeb[y]++;
		flow.add_edge(x,a+y,1,i);
	}
	for(int i=1;i<=a;i++){
		flow.add_edge(0,i,1e9,0);
		flow.add_edge(a+b+1,i,0,0);
		k=min(k,degreea[i]);
	}
	for(int i=1;i<=b;i++){
		flow.add_edge(i+a,a+b+3,1e9,0);
		flow.add_edge(i+a,a+b+2,0,0);
		k=min(k,degreeb[i]);
	}
	if(a<b)
		flow.add_edge(a+b+1,0,0,0);
	if(a>b)
		flow.add_edge(a+b+3,a+b+2,0,0);
	for(int i = 0;i<=k;i++){
		vector<int> v=flow.flow();
		printf("%d",v.size());
		for(auto it:v)
			printf(" %d",it);
		printf("\n");
		for(auto &it:flow.E[flow.s]){
			if(it.v<=a&&it.v>=1){
				it.f++;
			}
			if(it.v==0){
				it.f+=b-a;
			}
		}
		for(auto it:flow.E[flow.t]){
			if(it.v<=a+b&&it.v>a){
				flow.E[it.v][it.re].f++;
			}
			if(it.v==a+b+3){
				flow.E[it.v][it.re].f+=a-b;
			}
		}
	}
}