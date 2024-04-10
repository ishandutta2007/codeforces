#include<bits/stdc++.h>
using namespace std;
const int N=1010;
using pii=pair<int,int>;
using ll=long long;
vector<pii>S[N];
int deg[N],d[N],ls[N],rs[N],a[3*N],b[3*N],c[3*N],m;
void opt(int x,int y,int v) {
	a[++m]=x;
	b[m]=y;
	c[m]=v;
}
void dfs(int x,int fa,int rt,ll W) {
	d[x]=x;
	for(pii y:S[x])
		if(y.first!=fa) {
			dfs(y.first,x,rt,y.second);
			W-=y.second;
			d[x]=d[y.first];
			if(!ls[x])ls[x]=d[y.first];
			else rs[x]=d[y.first];
		}
	if(x==rt)return;
	if(!ls[x]) {
		opt(rt,x,-W);
		return;
	}
	opt(rt,ls[x],-W/2);
	opt(rt,rs[x],-W/2);
	opt(ls[x],rs[x],W/2);
}
int main() {
	int n,x,y,v,fl=1;
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		scanf("%d%d%d",&x,&y,&v);
		deg[x]++,deg[y]++;
		S[x].push_back(make_pair(y,v));
		S[y].push_back(make_pair(x,v));
	}
	for(int i=1;i<=n;i++)
		if(deg[i]==2)fl=0;
	if(!fl)puts("NO"),exit(0);
	puts("YES");
	for(int i=1;i<=n;i++)
		if(deg[i]==1)fl=i;
	dfs(fl,0,fl,0);
	printf("%d\n",m);
	for(int i=1;i<=m;i++)
		printf("%d %d %d\n",a[i],b[i],-c[i]);
	return 0;
}