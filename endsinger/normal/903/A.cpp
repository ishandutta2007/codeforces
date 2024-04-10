#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		if(m==1||m==2||m==4||m==5||m==8||m==11) 
			puts("NO");
		else 
			puts("YES");
	}
	return 0;
}