#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
vector<int>S[N];
int SG[N],f[N],fa[N];
void dfs(int x) {
	for(int y:S[x]) {
		if(y==fa[x])continue;
		fa[y]=x;
		dfs(y);
		SG[x]^=SG[y]+1;
	}
}
int main() {
	int n,a,b;
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		scanf("%d%d",&a,&b);
		S[a].push_back(b);
		S[b].push_back(a);
	}
	dfs(1);
	int sg=SG[f[1]=1],cnt=0;
	printf("%d",sg?1:2);
	for(int i=2;i<=n;i++) {
		for(int j=i;!f[j];j=fa[j]) {
			f[j]=1;
			sg^=(SG[j]+1)^SG[j];
			cnt^=1;
		}
		printf("%d",(sg^cnt)?1:2);
	}
	puts("");
	return 0;
}