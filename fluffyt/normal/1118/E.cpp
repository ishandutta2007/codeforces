#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(n>1ll*k*(k-1)) 
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	int d=1,c=-1,x=1,y=2;
	while(n--)
	{
		printf("%d %d\n",x,y);
		if(c==-1) x++,y++;
		else x--,y--;
		if(x>k||y>k||x<=0||y<=0)
		{
			if(c==-1)
			{
				c=1;
				x=k,y=k-d;
			}
			else
			{
				c=-1;
				d++;
				x=1,y=d+1;
			}
		}
	}
	return 0;
}