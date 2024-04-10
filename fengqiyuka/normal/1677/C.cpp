#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+100;
int Sum2=0;bool bk[N];int a[N],b[N];
vector<int> B[N];

void dfs(int x){
	Sum2++;bk[x]=false;
	for(auto y:B[x])
		if(bk[y]) dfs(y);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		for(int i=1;i<=n;i++) B[a[i]].push_back(b[i]);
		for(int i=1;i<=n;i++) bk[i]=true;
		int Sum=0;
		for(int i=1;i<=n;i++)
			if(bk[i]){
				Sum2=0;dfs(i);
				if(Sum2%2==1) Sum++;
			}
		int t=(n-Sum)/2;ll Ans=0;
		for(int i=1;i<=t;i++) Ans=Ans-2*i;
		for(int i=n;i>=n-t+1;i--) Ans=Ans+2*i;
		for(int i=1;i<=n;i++) B[i].clear();
		printf("%lld\n",Ans);
	}
	
	return 0;
}