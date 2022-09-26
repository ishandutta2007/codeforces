#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
typedef long long ll;
const int N = 100010;
const int inf = 0x3f3f3f3f;
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
class lfs {
   public:
    lfs(int N) {
        memset(head, -1, sizeof head);
        ecnt = 0;
        n = N;
    }
    void adde(int from, int to, int w) {
        e[ecnt].to = to;
        e[ecnt].w = w;
        e[ecnt].next = head[from];
        head[from] = ecnt++;
    }

    void solve() {
        vector<int> bfs_order;
        memset(dis, inf, sizeof dis);
        dis[0] = 0;
        bfs_order.push_back(0); 
        int cur = 0;
        while (cur < bfs_order.size()) {
            int u = bfs_order[cur];
            for (int i = head[u]; i != -1; i = e[i].next) {
                int v = e[i].to;
                if (dis[v] == inf) {
                    dis[v] = dis[u] + 1;
                    bfs_order.push_back(v);
                }
            }
            cur++;
        }

        vector<int> end_point;
        end_point.push_back(n - 1);
        memset(vis, false, sizeof vis);
        memset(pre, 0, sizeof pre);
        vis[n - 1] = true;
        cur = 0;
        int mindis = dis[n - 1];
        while (cur < end_point.size()) {
            int u = end_point[cur];
            for (int i = head[u]; i != -1; i = e[i].next) {
                int v = e[i].to;
                if (e[i].w == 0 && !vis[v]) {
                    end_point.push_back(v);
                    pre[v] = u;
                    vis[v] = true;
                    mindis = min(mindis, dis[v]);
                }
            }
            cur++;
        }

        bool leading_zeros = true;
        for (int l = mindis; l > 0; l--) {
            int now = inf;
            vector<int> next_point;
            for (auto& u : end_point) {
                for (int i = head[u]; i != -1; i = e[i].next) {
                    int v = e[i].to;
                    if (dis[v] + 1 == l) {
                        now = min(now, e[i].w);
                    }
                }
            }
            if(now!=0) leading_zeros = false;
            if(l==1||!leading_zeros) cout << now;
            for (auto& u : end_point) {
                for (int i = head[u]; i != -1; i = e[i].next) {
                    int v = e[i].to;
                    if (dis[v] + 1 == l && e[i].w == now && !vis[v]) {
                        vis[v] = true;
                        next_point.push_back(v);
                        pre[v] = u;
                    }
                }
            }
            end_point = next_point;
        }
        if (leading_zeros) cout << 0;
        cout << endl;
        vector<int> path;
        int u = 0;
        path.push_back(u);
        while (u != n - 1) {
            u = pre[u];
            path.push_back(u);
        }
        cout<<(int)path.size()<<endl;
        for(auto x:path) {
            cout<<x << ' ';
        }
        cout<<endl;
    }
   protected:
    struct Edge {
        int to, next, w;
    }e[N<<1];
    int head[N];
    int ecnt;
    int n;
    int dis[N];
    bool vis[N];
    int pre[N];
};
int main() {
    int n = read();
    int m = read();
    auto graph = new lfs(n);
    for (int i = 1; i <= m; i++) {
        int u=read(),v=read(),w=read();
        graph->adde(u, v, w);
        graph->adde(v, u, w);
    }
    graph->solve();
    return 0;
}