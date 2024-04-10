#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>S[N];
int f[N],a[N],sk[4*N],top;
int dfs(int x) {
	f[x]=1;
	int siz=a[x];
	for(int y:S[x])
		if(!f[y])siz+=dfs(y);
	return siz;
}
void to(int x) {
	sk[++top]=x;
	a[x]^=1;
}
void DP(int x) {
	f[x]=2;
	to(x);
	for(int y:S[x])
		if(f[y]!=2) {
			DP(y);
			to(x);
			if(a[y]) {
				to(y);
				to(x);
			}
		}
}
int main() {
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		S[x].push_back(y);
		S[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	int cnt=0,rt=0;
	for(int i=1;i<=n;i++)
		if(!f[i]&&dfs(i)) {
			cnt++;
			rt=i;
		}
	if(!rt)return puts("0"),0;
	if(cnt>1)return puts("-1"),0;
	if(S[rt].empty()) {
		printf("%d\n%d\n",1,rt);
		return 0;
	}
	DP(rt);
	if(a[rt]) {
		to(S[rt][0]);
		to(rt);
		to(S[rt][0]);
	}
	printf("%d\n",top);
	for(int i=1;i<=top;i++)
		printf("%d ",sk[i]);
	puts("");
	return 0;
}