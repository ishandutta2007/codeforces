#include<cstdio>
#include<iostream>
using namespace std;
int C(int n) { return n*n;}
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	int ans=C(a+b+c)-C(a)-C(c)-C(e);
	printf("%d\n",ans);
	return 0;
}