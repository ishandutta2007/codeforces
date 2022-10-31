#include<cstdio>
#include<iostream>
using namespace std;

int c,v,vt,a,l;
int main()
{
	scanf("%d%d%d%d%d",&c,&v,&vt,&a,&l);
	int day=0;
	while (c>0)
	{
		if (day) c+=l;
		c-=v;day++;
		v=min(v+a,vt);
	}
	printf("%d\n",day);
	return 0;
}