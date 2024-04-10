#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define INF 2147483647
#define N 200050
#define paul 1050

using namespace std;

struct Node{ int u,cap,rec; };
vector<Node> e[paul*10];
string s;

int p[paul],S,T,cnt,f[N],g[N],n,kk[N],mk[N];
 
void add_Node(int a,int b,int v) {
    Node tmp;
    tmp.u = b;
    tmp.cap = v;
    tmp.rec = e[b].size();
    e[a].push_back(tmp);
     
    tmp.u = a;
    tmp.cap = 0;
    tmp.rec = e[a].size() - 1;
    e[b].push_back(tmp);
}
 
bool BFS()
{
    bool flag = false;
    memset(p,0,sizeof(p));
    queue<int> q;
    q.push(S);
    p[S] = 1;
     
    while (!q.empty())
    {
        int now = q.front(); q.pop();
        if (now == T) flag = true;
        for (int i=0;i<e[now].size();i++)
        {
            int nxt = e[now][i].u;
            int cp = e[now][i].cap;
            if (cp > 0 && p[nxt] == 0)
            {
                q.push(nxt);
                p[nxt] = p[now] + 1;
            }
        }
    }
    return flag;
}
 
int DFS(int u,int flow)
{
    if (u == T) return flow;
    int g = 0 , f = flow;
    for (int i=0;i<e[u].size();i++)
    {
        int v = e[u][i].u;
        int cp = e[u][i].cap;
        int tmp = 0;
        if (cp > 0 && p[v] == p[u] + 1 && (tmp = DFS(v,min(f,cp))) > 0)
        {
            g += tmp;
            f -= tmp;
            e[u][i].cap -= tmp;
            int rc = e[u][i].rec;
            e[v][rc].cap += tmp;
        }
    }
    return g;
}

int main()
{
	S = ++cnt; T = ++cnt;
	for (int i=1;i<=6;i++) {
		int x = 0; scanf("%d",&x);
		add_Node(g[i] = ++cnt,T,x);
	}
	
	scanf("%d",&n);
	
	for (int i=1;i<=n;i++) {
		cin >> s;
		if (s == "S") kk[ mk[i] = 1 ]++;
		if (s == "M") kk[ mk[i] = 2 ]++;
		if (s == "L") kk[ mk[i] = 3 ]++;
		if (s == "XL") kk[ mk[i] = 4 ]++;
		if (s == "XXL") kk[ mk[i] = 5 ]++;
		if (s == "XXXL") kk[ mk[i] = 6 ]++;
		if (s == "S,M") kk[ mk[i] = 7 ]++;
		if (s == "M,L") kk[ mk[i] = 8 ]++;
		if (s == "L,XL") kk[ mk[i] = 9 ]++;
		if (s == "XL,XXL") kk[ mk[i] = 10 ]++;
		if (s == "XXL,XXXL") kk[ mk[i] = 11 ]++;
	}
	
	for (int i=1;i<=11;i++) add_Node(S,f[i] = ++cnt,kk[i]);
	
	for (int i=1;i<=6;i++)
		add_Node(f[i],g[i],kk[i]);
	for (int i=7;i<=11;i++) {
		add_Node(f[i],g[i-6],kk[i]);
		add_Node(f[i],g[i-5],kk[i]);
	}
	
	int ans = 0;
	while (BFS()) ans += DFS(S,INF);
	
	if (ans < n) {
		puts("NO");
	} else {
		printf("YES\n");
		for (int i=1;i<=n;i++) {
			int tmp = 0;
			if (mk[i] <= 6) tmp = mk[i]; else {
				int a = mk[i] - 6;
				int b = a + 1;
				int rc = e[ f[mk[i]] ][1].rec;
				if (e[ g[a] ][ rc ].cap > 0) {
					tmp = a;
					e[ g[a] ][ rc ].cap--;
				} else {
					tmp = b;
				}
			}
			if (tmp == 1) printf("S\n");
			if (tmp == 2) printf("M\n");
			if (tmp == 3) printf("L\n");
			if (tmp == 4) printf("XL\n");
			if (tmp == 5) printf("XXL\n");
			if (tmp == 6)printf("XXXL\n");
		}
	}
	
	return 0;
}