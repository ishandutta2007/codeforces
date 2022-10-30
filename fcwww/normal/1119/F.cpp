#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define fov(i,x) for(i=0;i<(int)x.size();i++)
#define N 250050
#define vi vector<int>
typedef long long ll;
int n,nxt[N],D,d[N],vis[N],st[N];
struct A {int to,v;bool operator < (const A &u) const {return d[to]<d[u.to];}};
vector<A> G[N];
vi dd[N];
multiset<ll,greater<ll> > s[N];
ll sum[N],ans,f[N][2];
inline void add(int u,int v,int w) {G[u].push_back((A){v,w});}
void del(int x) {
	vis[x]=1;
	int i;
	fov(i,G[x]) {
		int to=G[x][i].to,v=G[x][i].v;
		if(vis[to]) continue;
		s[to].insert(v), sum[to]+=v;
	}
}
void resize(int x,int n) {
	while((int)s[x].size()>n) sum[x]-=*s[x].begin(),s[x].erase(s[x].begin());
}
void resize(int x,int n,vector<ll> &u) {
	while((int)s[x].size()>n) sum[x]-=*s[x].begin(),u.push_back(*s[x].begin()),s[x].erase(s[x].begin());
}
void dfs(int x,int y) {
	int i,ned=d[x]-D;
	ll tot=0;
	vis[x]=1;
	vector<ll>v1,v2;
	resize(x,max(0,ned));
	while(st[x]<(int)G[x].size()&&d[ G[x][st[x]].to ]<=D) st[x]++;
	for(i=st[x];i<(int)G[x].size();i++) {
		int to=G[x][i].to,v=G[x][i].v;
		if(vis[to]||to==y) continue;
		dfs(to,x);
		if(f[to][1]+v<=f[to][0]) ned--,tot+=f[to][1]+v;
		else {
			tot+=f[to][0];
			ll tmp=f[to][1]+v-f[to][0];
			s[x].insert(tmp); sum[x]+=tmp;
			v2.push_back(tmp);
		}
	}
	resize(x,max(0,ned),v1);
	f[x][0]=tot+sum[x];
	ned--; 
	resize(x,max(0,ned),v1);
	f[x][1]=tot+sum[x];
	fov(i,v1) s[x].insert(v1[i]),sum[x]+=v1[i];
	fov(i,v2) s[x].erase(s[x].find(v2[i])),sum[x]-=v2[i];
}
int main() {
	scanf("%d",&n);
	int i,x,y,z,j,k;
	for(i=1;i<n;i++) scanf("%d%d%d",&x,&y,&z),add(x,y,z),add(y,x,z),ans+=z,d[x]++,d[y]++;
	for(i=1;i<=n;i++) {
		sort(G[i].begin(),G[i].end());
		dd[d[i]].push_back(i);
	}
	nxt[n]=n+1;
	for(i=n-1;i;i--) {
		if(dd[i+1].size()) nxt[i]=i+1;
		else nxt[i]=nxt[i+1];
	}
	printf("%lld ",ans);
	for(i=1;i<n;i++) {
		fov(j,dd[i])del(dd[i][j]);
		ans=0; D=i;
		for(j=i+1;j<=n;j=nxt[j]) {
			fov(k,dd[j]) {
				if(vis[dd[j][k]]) continue;
				dfs(dd[j][k],0); ans+=f[dd[j][k]][0];
			}
		}
		printf("%lld ",ans);
		for(j=i+1;j<=n;j=nxt[j])
			fov(k,dd[j])
				vis[dd[j][k]]=0;
	}
	puts("");
	return 0;
}