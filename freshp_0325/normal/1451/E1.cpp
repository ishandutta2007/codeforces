#include<bits/stdc++.h>
using namespace std;
int n,ans[(1<<16)+5];
int main(){
	//a=1^2 b=1&2 c=1^3 d=1&3 e=2^3 f=2&3
	scanf("%d",&n);
	puts("XOR 1 2");
	fflush(stdout);
	int a;
	scanf("%d",&a);
	puts("XOR 1 3");
	fflush(stdout);
	int b;
	scanf("%d",&b);
	int c=a^b;
	puts("AND 1 2");
	fflush(stdout);
	int e;
	scanf("%d",&e);
	puts("AND 1 3");
	fflush(stdout);
	int f;
	scanf("%d",&f);
	puts("AND 2 3");
	fflush(stdout);
	int g;
	scanf("%d",&g);
	int x=a+2*e,y=b+2*f,z=c+2*g;
	int fuck=(x+y+z)/2;
	ans[1]=fuck-z,ans[2]=fuck-y,ans[3]=fuck-x;
	for(int i=4;i<=n;++i)
	{
		printf("XOR 1 %d\n",i);
		fflush(stdout);
		int p;
		scanf("%d",&p);
		ans[i]=ans[1]^p;
	}
	putchar('!');
	for(int i=1;i<=n;++i)	printf(" %d",ans[i]);
	puts("");
	fflush(stdout);
	return 0;
}