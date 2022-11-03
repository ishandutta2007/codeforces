#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,a,b,c,d;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if (a==c) printf("%d\n",abs(b-d));
		else if (d==b) printf("%d\n",abs(a-c));
		else printf("%d\n",abs(a-c)+abs(b-d)+2);
	}
	return Accepted;
}