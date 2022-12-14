#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char op[105][5],ss[5];
int n,m=1,num1=0,num2=0;
int main()
{
	++num1;op[1][1]='+';scanf("%s",ss+1);
	for(;;)
	{
		++m;scanf("%s",op[m]+1);
		if(op[m][1]=='+') ++num1;
		else if(op[m][1]=='-') ++num2;
		else {--m;n=read();break;}	
		scanf("%s",ss+1);
	}
	if(num1*n-num2<n||num1-n*num2>n) return 0*puts("Impossible"); else puts("Possible");
	for(int i=1,z=n;i<=m;++i)
	{
		int j,t;
		if(op[i][1]=='+') t=1,--num1; else t=-1,--num2;
		for(j=1;j<=n;++j)
		{
			if(num1*n-num2<z-t*j||num1-num2*n>z-t*j) continue;
			break;
		}	
		printf("%d ",j);
		printf("%c ",op[i+1][1]);
		z-=t*j;
	}
	printf("%d",n);
	return 0;
}