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
char op[5];
int n,t[15],y[15],s[15];
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",op+1);int x=read();
		if(op[1]=='&')
		{
			for(int j=0;j<10;++j) 
				if(y[j]) t[j]=t[j]&bool(x&(1<<j));
				else if(!(x&(1<<j))) y[j]=1,t[j]=0;
		}
		else if(op[1]=='|')
		{
			for(int j=0;j<10;++j)
				if(y[j]) t[j]=t[j]|bool(x&(1<<j));
				else if(x&(1<<j)) y[j]=1,t[j]=1;	
		}
		else for(int j=0;j<10;++j) t[j]^=bool(x&(1<<j));
	}
	int x1=1023,x2=0,x3=0;
	for(int j=0;j<10;++j)
		if(!y[j]) x3|=t[j]*(1<<j);
		else if(t[j]) x2|=(1<<j);
		else x1^=(1<<j);
	puts("3");
	printf("& %d\n",x1);
	printf("| %d\n",x2);
	printf("^ %d\n",x3);
	return 0;
}