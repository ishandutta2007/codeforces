#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int ans=0;
		int k=min(b,c/2);
		ans+=k*3;
		b-=k;
		k=min(a,b/2);
		ans+=k*3;
		printf("%d\n",ans);	
	} 
	return 0;
}