#include<bits/stdc++.h>
using namespace std;
char a[20];
void sol()
{
	scanf("%s",a);
	int m=10;
	for(int s=0;s<1024;s++)
	{
		int ok=1;
		for(int i=0;i<10;i++)
		{
			if(a[i]=='0'&&(s>>i&1))
				ok=0;
			if(a[i]=='1'&&!(s>>i&1))
				ok=0;
		}
		if(!ok)
			continue;
		int x=0,y=0,rx=5,ry=5;
		for(int i=0;i<10;i++)
		{
			if(!(i&1))
			{
				rx--;
				if(s>>i&1)
					x++;
			}
			else
			{
				ry--;
				if(s>>i&1)
					y++;
			}
			if(x+rx<y||y+ry<x)
			{
				m=min(m,i+1);
				break;
			}
		}
	}
	printf("%d\n",m);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();	
	return 0;
}