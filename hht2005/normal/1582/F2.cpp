#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=1<<13;
int ans[M],r[M],a[N];
vector<int>g[M];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<M;i++) {
		g[i].push_back(0);
		r[i]=M-1;
	}
	ans[0]=1;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++) {
		for(int j:g[a[i]]) {
			int to=j^a[i];
			ans[to]=1;
			while(r[to]>a[i])
				g[r[to]--].push_back(to);
		}
		g[a[i]].clear();
	}
	int k=0;
	for(int i=0;i<M;i++)
		k+=ans[i];
	printf("%d\n",k);
	for(int i=0;i<M;i++)
		if(ans[i])printf("%d ",i);
	puts("");
	return 0;
}