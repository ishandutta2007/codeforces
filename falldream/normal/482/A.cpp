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

int main()
{
	int n=read(),K=read(),a=1,b=n;
	for(int i=1;i<=K;++i) printf("%d ",(i&1)?(a++):(b--));
	if(K&1) for(;a<=b;++a) printf("%d ",a);
	else for(;b>=a;--b) printf("%d ",b);
	return 0;
}