#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2e5+100;

int fa[N],L[N],R[N],Ans;bool bk[N];
vector<int> B[N];ll si[N];

void dfs(int x){
	bk[x]=false;si[x]=0;
	for(auto y:B[x])
		if(bk[y]){
			dfs(y);
			si[x]+=si[y];
		}
	if(si[x]<L[x]) Ans++,si[x]=R[x];
	if(si[x]>R[x]) si[x]=R[x];
}

int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=2;i<=n;i++) scanf("%d",&fa[i]);
		for(int i=1;i<=n;i++) scanf("%d%d",&L[i],&R[i]);
		for(int i=2;i<=n;i++) B[fa[i]].push_back(i);
		
		for(int i=1;i<=n;i++) bk[i]=true;
		Ans=0;dfs(1);
		
		printf("%d\n",Ans);
		
		for(int i=1;i<=n;i++) B[i].clear();
	}
	
	return 0;
}