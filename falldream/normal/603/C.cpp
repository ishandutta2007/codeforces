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
int n,K,sg;
int Calc(int x)
{
	if(x==1||x==3) return 1;
	else if(x&1) return 0;
	else 
	{
		int X=Calc(x-1),Y=Calc(x>>1);
		if(X>Y) swap(X,Y);
		if(X==0&&Y==1) return 2;
		else if(X==0) return 1;
		else return 0;
	}
}
int main()
{
	n=read();K=read();
	for(int i=1;i<=n;++i)
	{
		int x=read();
		if(K&1) sg^=Calc(x);
		else 
		{
			if(x==1) sg^=1;
			else if(x==2) sg^=2;
			else sg^=1-(x&1);
		}
	}
	puts(sg?"Kevin":"Nicky");
	return 0;
}