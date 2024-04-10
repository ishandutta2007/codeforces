#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int q,l,r,d;
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&l,&r,&d);
		if (l<=d)
		{
			printf("%d\n",(r+d)/d*d);
		} 
		else
		{
			printf("%d\n",d);
		}
	}
	return Accepted;
}