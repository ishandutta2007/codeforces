#include<iostream>
#include<cstdio>
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,a[MN+5],b[MN+5],pos1,pos2;
inline void Move(int*s,int&x){for(x=x%n+1;!s[x];x=x%n+1);}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) if((a[i]=read())==1) pos1=i;
	for(int i=1;i<=n;++i) if((b[i]=read())==1) pos2=i;
	for(int i=1;i<n;++i) 
	{
		Move(a,pos1),Move(b,pos2);
		if(a[pos1]!=b[pos2]) return 0*puts("NO");
	}
	puts("YES");
	return 0;
}