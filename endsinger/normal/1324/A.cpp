#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,fl=1,x,y;
		scanf("%d%d",&n,&x);
		for(int i=2;i<=n;i++)
		{
			scanf("%d",&y);
			if(x%2!=y%2)
				fl=0;
		}
		puts(fl?"YES":"NO");
	}
	return 0;
}