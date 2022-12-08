#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int SG[N],t[N];
long long h[N],val[N];
vector<int>S[N];
void dfs(int x) {
	for(int y:S[x])
		if(SG[y]==-1)dfs(y);
	for(int y:S[x])
		t[SG[y]]=1;
	SG[x]=0;
	while(t[SG[x]])
		SG[x]++;
	for(int y:S[x])
		t[SG[y]]=0;
}
int main() {
	memset(SG,-1,sizeof(SG));
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",h+i);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&a,&b);
		S[a].push_back(b);
	}
	for(int i=1;i<=n;i++)
		if(SG[i]==-1)dfs(i);
	for(int i=1;i<=n;i++)
		val[SG[i]]^=h[i];
	int T=-1;
	for(int i=0;i<=m;i++)
		if(val[i])T=i;
	if(T==-1)puts("LOSE");
	else {
		puts("WIN");
		int M=0;
		for(int i=1;i<=n;i++)
			if(SG[i]==T)
				if((val[T]^h[i])<h[i])
					M=i;
		h[M]=val[T]^h[M];
		for(int i:S[M]) {
			h[i]=val[SG[i]]^h[i];
			val[SG[i]]=0;
		}
		for(int i=1;i<=n;i++)
			printf("%lld ",h[i]);
		puts("");
	}
	return 0;
}