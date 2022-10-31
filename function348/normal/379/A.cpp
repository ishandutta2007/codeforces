#include<cstdio>
#include<iostream>
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int ans=0,c=0;
	while (a)
	{
		ans+=a;
		c+=a;
		a=c/b;c%=b;
	}
	std::cout<<ans;
	return 0;
}