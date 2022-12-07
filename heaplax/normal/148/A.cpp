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
int a,b,c,d,sum,ans;
bool fit[100001];
int main()
{
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&sum);
	if(a!=0)for(int i=a;i<=sum;i+=a)fit[i]=true;
	if(b!=0)for(int i=b;i<=sum;i+=b)fit[i]=true;
	if(c!=0)for(int i=c;i<=sum;i+=c)fit[i]=true;		
	if(d!=0)for(int i=d;i<=sum;i+=d)fit[i]=true;		
	for(int i=1;i<=sum;i++)if(fit[i])ans++;
	printf("%d\n",ans);
	return 0;			
}