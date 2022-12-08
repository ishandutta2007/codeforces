#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int>S[N];
int x[N][2],p[N],col[N],t;
int cmp(int a,int b) {
	return x[a][t]<x[b][t];
}
void dfs(int x,int c) {
	col[x]=c;
	for(int y:S[x])
		if(col[y]==-1)dfs(y,c^1);
}
void add(int a,int b) {
	// cerr<<a<<' '<<b<<endl;
	S[a].push_back(b);
	S[b].push_back(a);
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",x[i],x[i]+1);
		p[i]=i;
	}
	sort(p+1,p+n+1,cmp);
	t=0;
	for(int i=2;i<=n;i++)
		if(x[p[i]][0]==x[p[i-1]][0])
			add(p[i-1],p[i]),i++;
	t=1;
	sort(p+1,p+n+1,cmp);
	for(int i=2;i<=n;i++)
		if(x[p[i]][1]==x[p[i-1]][1])
			add(p[i-1],p[i]),i++;
	memset(col,-1,sizeof(col));
	for(int i=1;i<=n;i++)
		if(col[i]==-1)dfs(i,0);
	for(int i=1;i<=n;i++)
		putchar(col[i]?'r':'b');
	return 0;
}