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
int n,a[101],ans,k;
bool cmp(int a,int b){return a>b;}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		if(a[i]>0 && a[i]>=a[k])
			ans++;
	printf("%d\n",ans);
	return 0;
}