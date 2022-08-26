#include<bits/stdc++.h>
#define N 2000005
using namespace std;
int i,j,k,l,s[N],n,m,fa[N],si[N],G[N],tot;
map<int,int>ma;
int ans,x,y;
#define pb push_back
vector<int>B[N];
int A[N];
inline int get(int x) {
	if (fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
int main() {
	scanf("%d",&n);
	for (i=1;i<=2*n;i++) fa[i]=i;
	for (i=1;i<=n;i++) {
		scanf("%d%d",&x,&y);
		if (!ma[x]) ma[x]=++tot,G[tot]=x;
		if (!ma[y]) ma[y]=++tot,G[tot]=y;
		x=ma[x],y=ma[y];
		fa[get(x)]=get(y);
		s[x]++;
	}
	for (i=1;i<=tot;i++) {
		si[get(i)]++;
		A[get(i)]+=s[i];
		B[get(i)].pb(G[i]);
	}
	for (i=1;i<=tot;i++) {
		if (get(i)!=i) continue;
		if (A[i]>si[i]) return puts("-1"),0;
		if (A[i]==si[i]) {
			for (j=0;j<B[i].size();j++) ans=max(ans,B[i][j]);
		}
		else {
			int ma=0;
			for (j=0;j<B[i].size();j++) ma=max(ma,B[i][j]);
			for (j=0;j<B[i].size();j++) if (B[i][j]!=ma) ans=max(ans,B[i][j]);
		}
	}
	printf("%d\n",ans);
}