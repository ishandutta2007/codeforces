#include<cstdio>
using namespace std;
int n;
bool a[15];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char temp;
		scanf(" %c",&temp);
		if(temp>='0' && temp<='9')
		{
			a[temp-'0']=false;
		}
		if(temp=='L')
		{
			for(int i=0;i<=9;i++)
			{
				if(a[i]==false)
				{
					a[i]=true;
					break;
				}
			}
		}
		if(temp=='R')
		{
			for(int i=9;i>=0;i--)
			{
				if(a[i]==false)
				{
					a[i]=true;
					break;
				}
			}
		}
	}
	for(int i=0;i<=9;i++)
	{
		if(a[i]==true) printf("1");
		else printf("0");
	}
}