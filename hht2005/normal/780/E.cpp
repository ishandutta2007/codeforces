#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int>S[N];
int f[N],pos[N*2],cnt;
void dfs(int x) {
	f[x]=1;
	pos[++cnt]=x;
	for(int y:S[x]) {
		if(f[y])continue;
		dfs(y);
		pos[++cnt]=x;
	}
}
int main() {
	int n,m,k,a,b;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&a,&b);
		S[a].push_back(b);
		S[b].push_back(a);
	}
	dfs(1);
	int val=2*n/k+(2*n%k!=0),i,j=0;
	for(i=1;i+val<=cnt;i+=val) {
		j++;
		printf("%d",val);
		for(int j=0;j<val;j++)
			printf(" %d",pos[i+j]);
		puts("");
	}
	j++;
	printf("%d",cnt-i+1);
	for(int j=0;j<cnt-i+1;j++)
		printf(" %d",pos[i+j]);
	puts("");
	for(int i=j+1;i<=k;i++)
		puts("1 1");
	return 0;
}