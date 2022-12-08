#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>S[N];
int f[N],n,m,k,fa[N],dep[N],sum[N];
void dfs(int x) {
	f[x]=1;
	for(int y:S[x]) {
		if(y==fa[x])continue;
		if(!f[y]) {
			fa[y]=x;
			dep[y]=dep[x]+1;
			dfs(y);
		} else if(dep[y]<dep[x]) {
			if(dep[x]-dep[y]+1>=k) {
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
	scanf("%d%d",&n,&m);
	int a,b;
	k=ceil(sqrt(n));
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&a,&b);
		S[a].push_back(b);
		S[b].push_back(a);
	}
	dfs(1);
	k--;
	for(int i=1;i<=n;i++)
		sum[dep[i]%k]++;
	int Max=0,x=0;
	for(int i=0;i<k;i++) {
		if(Max<sum[i])
			Max=sum[x=i];
	}
	int cnt=0;
	puts("1");
	for(int i=1;i<=n;i++)
		if(dep[i]%k==x&&cnt<=k)
			cnt++,printf("%d ",i);
	return 0;
}