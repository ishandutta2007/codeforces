#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10,mod=1e9+7;
vector<int>S[N];
int a[N],d;
int dfs(int x,int fa,int rt) {
	int f=1;
	for(int y:S[x])
		if(y!=fa&&(a[y]<a[rt]||(a[y]==a[rt]&&y<rt))&&a[rt]-a[y]<=d)
			f=1ll*f*(dfs(y,x,rt)+1)%mod;
	return f;
}
signed main() {
	int n,x,y;
	scanf("%d%d",&d,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		S[x].push_back(y);
		S[y].push_back(x);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=(ans+dfs(i,0,i))%mod;
	printf("%d\n",ans);
	return 0;
}