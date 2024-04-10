#include<bits/stdc++.h>
using namespace std;
#define mp(x,y)(make_pair(x,y))
const int N=2e5+1;
struct List{
	int head[N],tail[N],next[N];;
	void combine(int x,int y){
		if (head[y]){
			if (!head[x])head[x]=head[y],tail[x]=tail[y];
			else{
			    next[tail[x]]=head[y];
			    tail[x]=tail[y];
			}
			head[y]=tail[y]=0;
		}
	}
	void add(int x,int y){
		if (!head[x])head[x]=tail[x]=y;
		else
		    next[tail[x]]=y,tail[x]=y; 
	}
	void clear(int x){
	    head[x]=tail[x]=0;
	}
};
struct Tarjan{
    vector<pair<int,int>>g[N];
    int n,m,tot;
    bool instack[N],didedge[N];
	List in_edge,stack;
    int dfn[N],low[N];
    vector<int>edge_on_simple_circle,d;
    void read(){
        cin>>n>>m;
        for (int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            g[x].push_back(mp(y,i));
            g[y].push_back(mp(x,i));
        }
    }
    void dfs(int x,int lastedge){
        dfn[x]=low[x]=++tot;
        instack[x]=1;
        for (auto y:g[x]){
            if (y.second==lastedge)continue;
            if (!dfn[y.first]){
                dfs(y.first,y.second);
                if (dfn[x]<low[y.first]){
                    //bridge
                    continue;
                }else{
                    in_edge.add(low[y.first],y.second);
                    didedge[y.second]=1;
                }
                if (low[y.first]==dfn[x]){
                    int calc=1;
                    int sig=dfn[x],p=stack.head[sig];
                    while (p){
                        instack[p]=0;
                        ++calc;
                        p=stack.next[p];
                    }
                    stack.clear(sig);
                    d.clear();
                    instack[x]=1;
                    int e=in_edge.head[sig];
                    while (e)d.push_back(e),e=in_edge.next[e];
                    in_edge.head[sig]=in_edge.tail[sig]=0;
                    if (d.size()==calc){
                        for (auto e:d)
                            edge_on_simple_circle.push_back(e);
                    }
                }else{
                    if (low[y.first]<low[x]){
                        in_edge.combine(low[y.first],low[x]);
                        stack.combine(low[y.first],low[x]);
                    }else
                        if (low[y.first]>low[x]){
                            in_edge.combine(low[x],low[y.first]);
                            stack.combine(low[x],low[y.first]);
                        }
                    low[x]=min(low[x],low[y.first]);
                }
            }else{
                if (instack[y.first]){
                    if (!didedge[y.second]){
                        in_edge.add(dfn[y.first],y.second);
                        didedge[y.second]=1;
                    }
                    if (low[x]>dfn[y.first]){
                        in_edge.combine(dfn[y.first],low[x]);
                        stack.combine(dfn[y.first],low[x]);
                        low[x]=dfn[y.first];
                    }else
                    if (low[x]<dfn[y.first]){
                        in_edge.combine(low[x],dfn[y.first]);
                        stack.combine(low[x],dfn[y.first]);
                    }
                }
            }
        }
        stack.clear(dfn[x]);
        in_edge.clear(dfn[x]);
        if (low[x]!=dfn[x])
            stack.add(low[x],x);
        else
            instack[x]=0;
    }
    void build(){
        for (int i=1;i<=n;i++)
            if (!dfn[i])
                tot=0,dfs(i,0);
    }
    void output(){
        sort(edge_on_simple_circle.begin(),edge_on_simple_circle.end());
        cout<<edge_on_simple_circle.size()<<endl;
        for (auto e:edge_on_simple_circle)
            cout<<e<<' ';
    }
}f;
int main(){
   // freopen("a.in","r",stdin);
    ios::sync_with_stdio(false);
    f.read();
    f.build();
    f.output();
    return 0;
}