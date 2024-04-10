#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int>S[N];
int col[N],t[N];
void dfs(int x,int c) {
	col[x]=c;
	for(int y:S[x])
		if(col[y]==-1)
			dfs(y,c^1);
}
int main() {
	int n,x;
	scanf("%d",&n);
	if(n&1) {
		puts("Second");
		fflush(stdout);
		for(int i=1;i<=n;i++) {
			S[i].push_back(i+n);
			S[i+n].push_back(i);
		}
		for(int i=1;i<=2*n;i++) {
			scanf("%d",&x);
			if(t[x]) {
				S[i].push_back(t[x]);
				S[t[x]].push_back(i);
			}
			t[x]=i;
		}
		memset(col,-1,sizeof(col));
		for(int i=1;i<=2*n;i++)
			if(col[i]==-1)dfs(i,0);
		long long sum=0;
		for(int i=1;i<=2*n;i++)
			if(col[i])sum+=i;
		for(int i=1;i<=2*n;i++)
			if(col[i]==(sum%(2*n)==0))
				printf("%d ",i);
		cout<<endl;
	} else {
		puts("First");
		fflush(stdout);
		for(int i=1;i<=2;i++)
			for(int j=1;j<=n;j++)
				printf("%d ",j);
		cout<<endl;
	}
	return 0;
}