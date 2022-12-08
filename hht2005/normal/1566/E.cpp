#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int>S[N];
int sum,FL;
int dfs(int x,int fa) {
	int c[2]={0,0};
	for(int y:S[x]) {
		if(y==fa)continue;
		int t=dfs(y,x);
		if(t!=-1)c[t]++;
	}
	if(x!=1) {
		if(!c[0]&&!c[1])sum++;
		if(!c[0]&&c[1])sum--;//lkjhghjekrl
		if(c[0]&&c[1])FL=0;
	} else if(c[1])FL=0;
	return (!c[0]&&c[1])?-1:(!c[0]&&!c[1]);
}
int main() {
	int T,n,a,b;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n),sum=0,FL=1;
		for(int i=1;i<=n;i++)S[i].clear();
		for(int i=1;i<n;i++) {
			scanf("%d%d",&a,&b);
			S[a].push_back(b);
			S[b].push_back(a);
		}
		dfs(1,0);
		printf("%d\n",sum+FL);
	}
	return 0;
}