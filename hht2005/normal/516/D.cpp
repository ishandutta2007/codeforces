#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N=3e5+10;
typedef pair<int,int> pii;
vector<pii>S[N];
int d[N],jp[N][20];
long long f[N],g[N];
void dfs(int x,int fa) {
	for(pii y:S[x]) {
		if(y.fi==fa)continue;
		dfs(y.fi,x);
		long long t=f[y.fi]+y.se;
		if(t>f[x])swap(f[x],t);
		if(t>g[x])swap(g[x],t);
	}
}
void redfs(int x,int fa,int w) {
	if(fa) {
		long long t=f[x]+w==f[fa]?g[fa]+w:f[fa]+w;
		if(t>f[x])swap(f[x],t);
		if(t>g[x])swap(g[x],t);
	}
	for(pii y:S[x]) {
		if(y.fi==fa)continue;
		redfs(y.fi,x,y.se);
	}
}
void pre(int x,int fa) {
	jp[x][0]=fa;
	for(int i=1;i<20;i++)
		jp[x][i]=jp[jp[x][i-1]][i-1];
	for(pii y:S[x]) {
		if(y.fi==fa)continue;
		pre(y.fi,x);
	}
}
void sum(int x,int fa) {
	for(pii y:S[x]) {
		if(y.fi==fa)continue;
		sum(y.fi,x);
		d[x]+=d[y.fi];
	}
}
int main() {
	int n,q,a,b,c,rt=0;
	long long l;
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		scanf("%d%d%d",&a,&b,&c);
		S[a].push_back(make_pair(b,c));
		S[b].push_back(make_pair(a,c));
	}
	dfs(1,0);
	redfs(1,0,0);
	for(int i=1;i<=n;i++)
		if(!rt||f[rt]>f[i])
			rt=i;
	pre(rt,0);
	f[0]=-1e18;
	scanf("%d",&q);
	while(q--) {
		memset(d,0,sizeof(d));
		scanf("%lld",&l);
		for(int i=1;i<=n;i++) {
			d[i]++;
			int p=i;
			for(int j=19;j>=0;j--)
				if(f[jp[p][j]]>=f[i]-l)
					p=jp[p][j];
			d[jp[p][0]]--;
		}
		sum(rt,0);
		int ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,d[i]);
		printf("%d\n",ans);
	}
	return 0;
}