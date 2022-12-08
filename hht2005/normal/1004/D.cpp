#include<bits/stdc++.h>
using namespace std;
const int N=1000010,M=1e9;
int t[N],n;
void dfs(int x,int L,int R,int U,int D) {
	if(x>=n+1) {
		if(L!=M&&R!=M&&U!=M&&D!=M) {
			if((R+L+1)*(U+D+1)!=n)return;
			printf("%d %d\n",R+L+1,U+D+1);
			printf("%d %d\n",L+1,U+1);
			exit(0);
		}
		return;
	}
	int sum=max(min(x-1,L)-max(0,x-U)+1,0);
	sum+=max(min(x-1,U)-max(0,x-R)+1,0);
	sum+=max(min(x-1,R)-max(0,x-D)+1,0);
	sum+=max(min(x-1,D)-max(0,x-L)+1,0);
	int tmp=(L==M)+(R==M)+(U==M)+(D==M);
	if(sum<t[x])return;
	if(sum-t[x]>tmp)return;
	if(t[x]==sum)dfs(x+1,L,R,U,D);
	if(t[x]==sum-1) {
		if(L==M)dfs(x+1,x-1,R,U,D);
		if(R==M)dfs(x+1,L,x-1,U,D);
		if(U==M)dfs(x+1,L,R,x-1,D);
		if(D==M)dfs(x+1,L,R,U,x-1);
	}
	if(t[x]==sum-2) {
		if(L==M&&R==M)dfs(x+1,x-1,x-1,U,D);
		if(L==M&&U==M)dfs(x+1,x-1,R,x-1,D);
		if(L==M&&D==M)dfs(x+1,x-1,R,U,x-1);
		if(R==M&&U==M)dfs(x+1,L,x-1,x-1,D);
		if(R==M&&D==M)dfs(x+1,L,x-1,U,x-1);
		if(U==M&&D==M)dfs(x+1,L,R,x-1,x-1);
	}
	if(t[x]==sum-3) {
		if(tmp==4)dfs(x+1,x-1,x-1,x-1,D);
		if(L!=M)dfs(x+1,L,x-1,x-1,x-1);
		if(R!=M)dfs(x+1,x-1,R,x-1,x-1);
		if(U!=M)dfs(x+1,x-1,x-1,U,x-1);
		if(D!=M)dfs(x+1,x-1,x-1,x-1,D);
	}
	if(t[x]==sum-4)dfs(x+1,x-1,x-1,x-1,x-1);
}
int main() {
	int a;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a);
		t[a]++;
	}
	if(!t[0]) {
		puts("-1");
		return 0;
	}
	dfs(1,M,M,M,M);
	puts("-1");
	return 0;
}