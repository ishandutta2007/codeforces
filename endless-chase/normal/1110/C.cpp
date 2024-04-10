#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int q,x,p,t;
bool f;
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&x);
		for (int i=0;i<=25;i++)
		{
			if (x&(1<<i)) p=i;
		}
		if (x!=(1<<(p+1))-1) printf("%d\n",(1<<(p+1))-1);
		else
		{
			t=sqrt(x);f=0;
			for (int i=2;i<=t;i++)
			{
				if (x%i==0)
				{
					printf("%d\n",x/i);
					f=1;
					break;
				}
			}
			if (!f) printf("1\n");
		}
	}
	return Accepted;
}