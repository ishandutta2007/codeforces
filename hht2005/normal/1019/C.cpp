#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int>S[N];
int vis[N],f[N];
int main() {
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&a,&b);
		S[a].push_back(b);
	}
	for(int i=1;i<=n;i++) {
		if(vis[i])continue;
		vis[i]=f[i]=1;
		for(int j:S[i])
			vis[j]=1;
	}
	for(int i=n;i>=1;i--) {
		if(!f[i])continue;
		for(int j:S[i])
			f[j]=0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(f[i])cnt++;
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)
		if(f[i])printf("%d ",i);
	puts("");
	return 0;
}