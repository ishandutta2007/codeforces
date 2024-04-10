#include<cstdio>

using namespace std;

int i,j,k;

void show(int x,int k)
{
	if(x==0)
		return;
	show(x/k,k);
	printf("%d",x%k);
}

int main()
{
	scanf("%d",&k);
	for(i=1;i<k;++i,printf("\n"))
		for(j=1;j<k;++j)
			show(i*j,k),printf(" ");
}