#include<iostream>
using namespace std;
int main()
{
	int x;
	scanf("%d",&x);
	for(int a,b;x--;)
	{
		scanf("%d%d",&a,&b);
		if(a==b)printf("0\n");
		else 
		{
			if(a<b&&(b-a)%2||a>b&&(a-b)%2==0)printf("1\n");
			else printf("2\n");
		}
	}
	return 0;
}