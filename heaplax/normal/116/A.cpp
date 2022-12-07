#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
int n,a[1001],b[1001],maxn=-(1<<30),now;
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;i++)
		now=now-a[i]+b[i],maxn=max(maxn,now);
	printf("%d\n",maxn);
	return 0;
}