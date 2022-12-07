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
int k,n,w;
long long ans;
int main()
{	
	scanf("%d%d%d",&k,&n,&w);
	for(int i=1;i<=w;i++)
		ans+=k*i;
	if(n>=ans)ans=0;
	else ans-=n;
	printf("%I64d\n",ans);
	return 0;
}