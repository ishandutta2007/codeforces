#include<bits/stdc++.h>
using namespace std;
const int maxn=200010,maxm=3.2e6;
int tr[maxm][2],f[maxm][3],a[maxn],siz[maxm],tot=1;
void dfs(int x) {
	if(tr[x][0])dfs(tr[x][0]),siz[x]+=siz[tr[x][0]];
	if(tr[x][1])dfs(tr[x][1]),siz[x]+=siz[tr[x][1]];
	if(siz[x]==2)f[x][1]=0,f[x][0]=1,f[x][2]=1e9;
	else if(siz[x]==1)f[x][1]=f[x][2]=1e9,f[x][0]=0;
	else {
		int ls=tr[x][0],rs=tr[x][1];
		if(!rs)memcpy(f[x],f[ls],sizeof(f[x]));
		else if(!ls)memcpy(f[x],f[rs],sizeof(f[x]));
		else if(ls&&rs) {
			f[x][0]=f[ls][0]+f[rs][0]+1;
			f[x][1]=min(min(f[ls][0],f[ls][2])+min(f[rs][0],f[rs][2]),min(f[ls][1]+min(f[rs][0],f[rs][2]),f[rs][1]+min(f[ls][0],f[ls][2])));
			f[x][2]=min(f[ls][2]+min(f[rs][0],f[rs][2])+1,f[rs][2]+min(f[ls][0],f[ls][2])+1);
		}
	}
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		int p=1;
		for(int j=30;j>=0;j--) {
			int x=a[i]>>j&1;
			if(!tr[p][x])tr[p][x]=++tot;
			p=tr[p][x];
		}
		siz[p]=1;
	}
	dfs(1);
	printf("%d\n",min(min(f[1][0],f[1][1]),f[1][2]));
	return 0;
}