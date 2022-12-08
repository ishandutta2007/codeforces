#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define fi first
#define se second
typedef pair<int,int> pii;
vector<pii>S[N];
int s,t,Max,n;
void pre(int x,int fa,int dep) {
	if(Max<=dep) {
		s=x;
		Max=dep;
	}
	for(pii y:S[x]) {
		if(y.fi==fa)continue;
		pre(y.fi,x,dep+y.se);
	}
}
struct Tree {
	int jp[N][20],D[N],dep[N],son[N],top[N],tim[N],sum[N],rt,m;
	pii p[N];
	void dfs1(int x,int fa) {
		jp[x][0]=fa;
		for(int i=1;i<20;i++)
			jp[x][i]=jp[jp[x][i-1]][i-1];
		for(pii y:S[x]) {
			if(y.fi==fa)continue;
			D[y.fi]=D[x]+y.se;
			dfs1(y.fi,x);
			if(dep[y.fi]+y.se>dep[x])
				dep[x]=dep[son[x]=y.fi]+y.se;
		}
	}
	void dfs2(int x,int fa) {
		for(pii y:S[x]) {
			if(y.fi==fa)continue;
			top[y.fi]=y.se;
			if(son[x]==y.fi)
				top[y.fi]+=top[x];
			dfs2(y.fi,x);
		}
	}
	void pre(int s) {
		rt=s;
		dfs1(s,0);
		dfs2(s,0);
		for(int i=1;i<=n;i++)
			if(i!=s&&S[i].size()==1u)
				p[++m]=make_pair(top[i],i);
		sort(p+1,p+m+1,greater<pii>());
		for(int i=1;i<=m;i++) {
			sum[i]=sum[i-1]+p[i].fi;
			int now=p[i].se;
			while(now&&!tim[now])
				tim[now]=i,now=jp[now][0];
		}
	}
	int qry(int x,int y) {
		if(2*y-1>m)return sum[m];
		if(tim[x]<=2*y-1)return sum[2*y-1];
		int ans1=sum[2*y-2]+dep[x],p=x;
		for(int i=19;i>=0;i--)
			if(tim[jp[p][i]]>2*y-2)
				p=jp[p][i];
		ans1+=D[x]-D[jp[p][0]];
		int ans2=sum[2*y-1]+dep[x];
		p=x;
		for(int i=19;i>=0;i--)
			if(tim[jp[p][i]]>2*y-1)
				p=jp[p][i];
		ans2+=D[x]-D[jp[p][0]]-dep[jp[p][0]];
		return max(ans1,ans2);
	}
}A,B;
int main() {
	int q,a,b,c;
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++) {
		scanf("%d%d%d",&a,&b,&c);
		S[a].push_back(make_pair(b,c));
		S[b].push_back(make_pair(a,c));
	}
	pre(1,0,0);
	Max=0,t=s;
	pre(s,0,0);
	A.pre(s);
	B.pre(t);
	int lastans=0;
	while(q--) {
		scanf("%d%d",&a,&b);
		a=(a+lastans-1)%n+1;
		b=(b+lastans-1)%n+1;
		printf("%d\n",lastans=max(A.qry(a,b),B.qry(a,b)));
	}
	return 0;
}