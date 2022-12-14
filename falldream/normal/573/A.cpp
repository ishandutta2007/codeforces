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
inline int Solve(int x){while(~x&1)x>>=1;while(x%3==0)x/=3;return x;}
int main()
{
	int n=read(),res=Solve(read());
	for(int i=2;i<=n;++i) if(Solve(read())!=res) return 0*puts("No");
	puts("Yes");
	return 0;
}