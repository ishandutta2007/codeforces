#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int>S[N];
int f[N],siz[N],fa[N],dep[N],Len,Siz,Min,rt;
int get(int x) {
	printf("d %d\n",x);fflush(stdout);
	scanf("%d",&x);
	return x;
}
int go(int x) {
	printf("s %d\n",x);fflush(stdout);
	scanf("%d",&x);
	return x;
}
void get_root(int x,int fa) {
	siz[x]=1;
	int Max=0;
	for(int y:S[x]) {
		if(f[y]||y==fa)continue;
		get_root(y,x);
		siz[x]+=siz[y];
		Max=max(Max,siz[y]);
	}
	Max=max(Max,Siz-siz[x]);
	if(Min>Max) {
		Min=Max;
		rt=x;
	}
}
void pre(int x) {
	for(int y:S[x]) {
		if(y==fa[x])continue;
		dep[y]=dep[x]+1;
		fa[y]=x;
		pre(y);
	}
}
void dfs(int x) {
	f[x]=1;
	int L=get(x),y=0;
	if(L==0) {
		printf("! %d\n",x);
		exit(0);
	}
	if(Len-L==dep[x])y=go(x);
	else y=fa[x];
	rt=-1,Min=1e9;
	Siz=siz[x]>siz[y]?siz[y]:Siz-siz[x];
	get_root(y,0);
	dfs(rt);
}
int main() {
	int n,a,b;
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		scanf("%d%d",&a,&b);
		S[a].push_back(b);
		S[b].push_back(a);
	}
	pre(1);
	Len=get(1);
	rt=-1,Min=1e9;
	Siz=n;
	get_root(1,0);
	dfs(rt);
	return 0;
}