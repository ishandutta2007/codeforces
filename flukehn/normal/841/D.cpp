#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=3e5+11;
#define fi first
#define se second
#define epb emplace_back
int n, m, d[N];
vector<pii> g[N];
vector<int> ans;
bool v[300010];
int deg[300010];
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
bool dfs(int p, int fid) {
	v[p]=1;
	for(auto t: g[p]) {
		if(v[t.fi]) continue;
		deg[p]^=dfs(t.fi, t.se);
	}
	if(deg[p]^d[p]) {
		ans.push_back(fid);
		return true;
	}
	return false;
}
int main() {
	n=rd(), m=rd();
	int wild=-1, tot=0;
	for(int i=1; i<=n; i++) {
		d[i]=rd();
		if(d[i]==-1)
			if(~wild) d[i]=0;
			else wild=i;
		else
			tot^=d[i];
	}
	if(wild==-1&&tot) {
		puts("-1");
		return 0;
	}
	int u, v;
	for(int i=1; i<=m; i++) {
		u=rd(), v=rd();
		g[u].epb(v, i);
		g[v].epb(u, i);
	}
	if(wild!=-1) d[wild]=tot;
	dfs(1, 0);
	printf("%lu\n", ans.size());
	sort(ans.begin(), ans.end());
	for(auto t: ans)
		printf("%d\n", t);
	return 0;
}