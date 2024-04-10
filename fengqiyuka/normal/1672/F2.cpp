#include<bits/stdc++.h>
using namespace std;

const int N=2e5+100;
int a[N],Cnt[N],b[N],g[N];

set<int> S[N];

int bk[N];bool pd;

void dfs(int x){
	bk[x]=1;
	for(auto y:S[x]){
		if(bk[y]==1){
			pd=false;
			return ;
		}
		if(bk[y]==0){
			dfs(y);
			if(!pd) return ;
		}
	}
	bk[x]=2;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		
		for(int i=1;i<=n;i++) Cnt[i]=0;
		for(int i=1;i<=n;i++) Cnt[a[i]]++;
		
		int Max=0,Max1;
		for(int i=1;i<=n;i++){
			if(Max<Cnt[i]) Max=Cnt[i],Max1=i;
		}
		
		for(int i=1;i<=n;i++)
			if(a[i]!=Max1&&b[i]!=Max1) S[a[i]].insert(b[i]);
		
		pd=true;
		for(int i=1;i<=n;i++) bk[i]=0;
		for(int i=1;i<=n;i++)
			if(bk[i]==0){
				dfs(i);
				if(!pd) break;
			}
		
		if(pd) printf("AC\n");
		else printf("WA\n");
		
		for(int i=1;i<=n;i++) S[i].clear();
	}
	
	return 0;
}