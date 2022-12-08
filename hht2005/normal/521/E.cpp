#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int>S[N];
int dep[N],fa[N],a[N],b[N];
void out(int p,int ta) {
	int now=p;
	while(now!=ta) {
		printf("%d ",now);
		now=fa[now];
	}
	printf("%d\n",ta);
}
void outR(int p,int a) {
	if(p!=a)outR(p,fa[a]);
	printf("%d ",a);
}
void solve(int a,int b,int p,int ta,int tb) {
	if(dep[ta]<dep[tb]) {
		swap(ta,tb);
		swap(a,b);
	}
	printf("%d ",dep[p]-dep[ta]+1);
	out(p,ta);
	printf("%d ",dep[a]-dep[p]+2);
	outR(p,a);
	printf("%d\n",ta);
	printf("%d ",dep[b]-dep[p]+2+dep[ta]-dep[tb]);
	outR(p,b);
	outR(tb,ta);
	puts("");
}
void dfs(int x) {
	dep[x]=dep[fa[x]]+1;
	for(int y:S[x]) {
		if(y==fa[x])continue;
		if(!dep[y]) {
			fa[y]=x;
			dfs(y);
		} else if(dep[y]<dep[x]) {
			int now=x;
			while(now!=y) {
				if(a[now]) {
					puts("YES");
					solve(x,b[now],now,y,a[now]);
					exit(0);
				}
				a[now]=y,b[now]=x;
				now=fa[now];
			}
		}
	}
}
int main() {
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&a,&b);
		S[a].push_back(b);
		S[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
		if(!dep[i])dfs(i);
	puts("NO");
	return 0;
}