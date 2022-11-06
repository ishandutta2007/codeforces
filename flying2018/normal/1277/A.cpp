#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
ll num[11]={0,1,11,111,1111,11111,111111,1111111,11111111,111111111};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a;
		scanf("%lld",&a);
		int ans=0;
		for(int i=1;i<=9;i++)
		{
			int p=1;
			while(p<10 && num[i]*p<=a) p++,ans++;
			if(p!=10) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}