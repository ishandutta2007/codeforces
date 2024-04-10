#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==1)
			puts(y==1?"YES":"NO");
		else if(x==2||x==3)
			puts(y<=3?"YES":"NO");
		else
			puts("YES");
	}
	return 0;
}