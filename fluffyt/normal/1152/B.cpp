#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=1000000;
int b[2000005],x,tot,a[105];
int main()
{
	for(int i=2;i<=MX*2;i++) b[i]=b[i>>1]+1;
	scanf("%d",&x);
	int n=(1<<(b[x]+1))-1;
	for(int t=1;;t++)
	{
//		if(x>n)
//		{
//			puts("fuck!");
//			return 0;
//		}
		if(x==n)
		{
			printf("%d\n",t-1);
			for(int i=1;i<=t/2;i++) printf("%d ",a[i]);
			puts("");
			return 0;
		}
		if(t&1)
		{
			for(int i=b[x];i>=0;i--)
			{
				if(!((x>>i)&1)) 
				{
					a[++tot]=i+1;
					x=(x^((1<<(i+1))-1));
					break;
				}
			}
		}
		else x++;
	}
	return 0; 
}