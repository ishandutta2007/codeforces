#include<iostream>
#include<cstdio>
using namespace std;
int T;
int A,B,C,D;
void solve()
{
	scanf("%d%d%d%d",&A,&B,&C,&D);
	int num0=A+B,num1=C+D;
	bool a=false,b=false,c=false,d=false;
	if((A+B)&1)
	{
		if(A>0||D>0) a=true;
		if(B>0||C>0) b=true;
	}
	else
	{
		if(B>0||C>0) c=true;
		if(A>0||D>0) d=true;
	}
	if(a) printf("Ya ");
	else printf("Tidak ");
	if(b) printf("Ya ");
	else printf("Tidak ");
	if(c) printf("Ya ");
	else printf("Tidak ");
	if(d) printf("Ya ");
	else printf("Tidak ");
	printf("\n");
	return;
}
int main()
{
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}