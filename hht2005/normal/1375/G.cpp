#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int>S[N];
int W,B;
void dfs(int x,int fa,int c) {
	if(c)W++;
	else B++;
	for(int y:S[x])
		if(y!=fa)dfs(y,x,c^1); 
}
int main() {
	int n,a,b;
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		scanf("%d%d",&a,&b);
		S[a].push_back(b);
		S[b].push_back(a);
	}
	dfs(1,0,0);
	printf("%d\n",min(W,B)-1);
	return 0;
}