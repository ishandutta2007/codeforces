#include<bits/stdc++.h>
using namespace std;
int n,x=1;
int main()
{
	scanf("%d",&n);
	if(n==1)
	{
		printf("1\n1 1\n");
		return 0;
	}
	printf("%d\n",n-(n+1)/3);
	for(int i=1;i<=(n+1)/3;i++)
		printf("%d %d\n",i,i*2-1);
	for(int i=1;i<(n+1)/3;i++)
		printf("%d %d\n",i+(n+1)/3,i*2);
	for(int i=n;i>=(n+1)/3*3;i--)
		printf("%d %d\n",i,i);
	return 0;
}