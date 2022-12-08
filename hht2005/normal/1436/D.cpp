#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
vector<int>s[maxn];
long long Max[maxn],sum[maxn];
int siz[maxn],a[maxn];
void dfs(int x) {
	if(!s[x].size())siz[x]++;
	sum[x]=a[x];
	for(int y:s[x]) {
		dfs(y);//sadefrdgt
		siz[x]+=siz[y];
		sum[x]+=sum[y];
		Max[x]=max(Max[x],Max[y]);
	}
	if(siz[x]*Max[x]<sum[x])Max[x]=sum[x]/siz[x]+(sum[x]%siz[x]!=0);
}
int main() {
	int n,p;
	scanf("%d",&n);
	for(int i=2;i<=n;i++) {
		scanf("%d",&p);
		s[p].push_back(i);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	dfs(1);
	printf("%lld\n",Max[1]);
	return 0;
}