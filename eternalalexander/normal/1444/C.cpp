#include <bits/stdc++.h>
#define maxn 500005
#define mp std::make_pair
#define pii std::pair<int,int>
#define ll long long

struct state {
	int x,y,ry;
};inline state newstate(int x,int y,int ry){state s;s.x=x;s.y=y;s.ry=ry;return s;}

namespace dsu {
	int fa[maxn]={0},rev[maxn]={0},dis[maxn]={0},rank[maxn]={0};
	std::stack<state>stk;
	int getf(int x){
		if (!fa[x]){dis[x]=0;return x;}
		int f=getf(fa[x]);
		dis[x]=dis[fa[x]]^rev[x];
		return f;
	} int merge(int x,int y){
		int f1=getf(x),f2=getf(y);
		if (f1!=f2){
			if (rank[f1]<rank[f2]){std::swap(f1,f2);std::swap(x,y);}
			stk.push(newstate(f2,f1,rank[f1]));
			fa[f2]=f1;rev[f2]=dis[x]^dis[y]^1;
			if (rank[f1]==rank[f2])rank[f1]++;
			return 2;
		}else {
			if (dis[x]==dis[y])return 0;
			return 1;
		}
	}inline void cancel(){
		state s=stk.top();stk.pop();
		fa[s.x]=0;rev[s.x]=0;dis[s.x]=0;rank[s.y]=s.ry;
	}
}

int n,m,k,c[maxn],u,v,bad[maxn],sz,tl;
ll ans;
std::vector<pii>vec[maxn];
std::map<pii,int>id;

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1; i <= n; ++ i) scanf("%d",&c[i]);
	for (int i = 1; i <= m; ++ i) {
		scanf("%d%d",&u,&v);
		if (c[u] == c[v]) {
			int res = dsu::merge(u,v);
			if (res == 0) bad[c[u]] = 1;
		} else {
			if (c[u] > c[v]) std::swap(u,v);
			if (!id[mp(c[u],c[v])]) id[mp(c[u],c[v])] = ++sz;
			vec[id[mp(c[u],c[v])]].push_back(mp(u,v));
		}
	}
	for (int i = 1; i <= k; ++ i) {
		if (bad[i]) continue;
		++tl;
	} ans = (ll) tl * (tl-1) / 2;
	for (auto P1:id) {
		auto p = P1.first;
		int x = p.first, y = p.second;
		if (bad[x] || bad[y]) continue;
		int ok = 1, cnt = 0;
		for (auto P2:vec[P1.second]) { 
			int res = dsu::merge(P2.first,P2.second);
			if (res == 0) { ok = 0; break; }
			if (res == 2) cnt ++;
		} for(int i=1;i<=cnt;++i)dsu::cancel();
		if (!ok) ans --;
	} printf("%lld",ans);
	return 0;
}