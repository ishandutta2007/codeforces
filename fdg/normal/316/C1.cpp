#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <memory.h>

using namespace std;

int arr[82][82]={0};

struct MinCostFlow {
    MinCostFlow(int _n,int _s,int _t) : n(_n), s(_s), t(_t), fl(0), cost(0) {
        first.resize(n,-1);
        dist.resize(n);
        prev.resize(n);
        a.reserve(8*n);
    };
    struct Edge {
        Edge(int _to,int _cap,int _cost,int _next) : to(_to), cap(_cap), cost(_cost), next(_next) {};
        int to,next,cap,cost;
    };
    void addEdge(int u,int v,int cap,int cost) {
        a.push_back(Edge(v,cap,cost,first[u])); first[u]=a.size()-1;
        a.push_back(Edge(u,0,-cost,first[v])); first[v]=a.size()-1;
    }
    bool augment() {
        dist.assign(n,inf);
        dist[s]=0;
        priority_queue < pair <int,int> > q; q.push(make_pair(0,s));
        while(q.size()) {
            if (dist[t]!=inf) break;
            pair <int,int> top=q.top(); q.pop();
            if (dist[top.second]!=-top.first) continue;
            int u=top.second;
            for(int e=first[u];e!=-1;e=a[e].next) {
                int v=a[e].to,ndist=-top.first+a[e].cost;
                if (a[e].cap>0&&dist[v]>ndist) {
                    dist[v]=ndist;
                    q.push(make_pair(-ndist,v));
                    prev[v]=e;
                }
            }
        }
        return dist[t]!=inf;
    }
    pair <int,int> flow() {
        while(augment()) {
            int cur=t,size=inf;
            while(cur!=s) {
                int e=prev[cur];
                size=min(size,a[e].cap);
                cur=a[e^1].to;
            }
            fl+=size; cost+=(dist[t])*size;
//          if (cost>=0) break;
            cur=t;
            while(cur!=s) {
                int e=prev[cur];
                a[e].cap-=size;
                a[e^1].cap+=size;
                cur=a[e^1].to;
            }
        }
        return make_pair(fl,cost);
    }
    int n,s,t,fl,cost;
    static const int inf=1000000009;
    vector <int> first,prev,dist;
    vector <Edge> a;
};

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            scanf("%d",&arr[i][j]);
    int dx[]={-1,0,0,1},
        dy[]={0,-1,1,0};
    int s=0,t=n*m+1;
    MinCostFlow flow(n*m+2,s,t);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if ((i+j)%2==0) flow.addEdge(s,i*m+j+1,1,0);
            else flow.addEdge(i*m+j+1,t,1,0);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if ((i+j)%2==0)
            for(int t=0;t<4;++t) {
                int nx=i+dx[t],ny=j+dy[t];
                if (nx>=0&&nx<n&&ny>=0&&ny<m) {
                    flow.addEdge(i*m+j+1,nx*m+ny+1,1,(arr[i][j]!=arr[nx][ny]));
                }
            }
    pair <int,int> res=flow.flow();
    cout << res.second << endl;
    return 0;
}