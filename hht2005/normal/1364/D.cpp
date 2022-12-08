#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>S[N];
int f[N],n,m,k,fa[N],dep[N],Max,A;
void dfs(int x) {
	f[x]=1;
	if(Max<dep[x])Max=dep[A=x];
	for(int y:S[x]) {
		if(y==fa[x])continue;
		if(!f[y]) {
			fa[y]=x;
			dep[y]=dep[x]+1;
			dfs(y);
		} else if(dep[y]<dep[x]) {
			if(dep[x]-dep[y]+1<=k) {
				puts("2");
				printf("%d\n",dep[x]-dep[y]+1);
				while(x!=y)printf("%d ",x),x=fa[x];
				printf("%d\n",x);
				exit(0);
			}
		}
	}
}
int main() {
	scanf("%d%d%d",&n,&m,&k);
	int a,b;
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&a,&b);
		S[a].push_back(b);
		S[b].push_back(a);
	}
	dfs(1);
	if(m==n-1) {
		puts("1");
		int O=0,E=0;
		for(int i=1;i<=n;i++)
			if(dep[i]&1)O++;
			else E++;
		if(O>E) {
			int cnt=0;
			for(int i=1;i<=n&&cnt<k/2+k%2;i++)
				if(dep[i]&1)cnt++,printf("%d ",i);
			puts("");
		} else {
			int cnt=0;
			for(int i=1;i<=n&&cnt<k/2+k%2;i++)
				if(!(dep[i]&1))cnt++,printf("%d ",i);
			puts("");
		}
		return 0;
	}
	int cnt=0;
	puts("1");
	int x=A,c1=0;
	while(x) {
		if((cnt++)%2==0&&++c1<=k/2+k%2)printf("%d ",x);
		x=fa[x];
	}
	return 0;
}