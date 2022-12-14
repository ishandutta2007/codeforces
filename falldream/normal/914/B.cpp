#include<iostream>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,num[MN+5];
int main()
{
	n=read();
	for(int i=1;i<=n;++i) ++num[read()];
	for(int i=MN;i;--i) if(num[i]&1) return 0*puts("Conan");
	puts("Agasa");
	return 0;
}