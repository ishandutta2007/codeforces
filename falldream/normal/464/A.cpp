#include<iostream>
#include<cstdio>
#define MN 1000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[MN+5];
int n,p;

void Build(int x)
{
	for(int i=x;i<=n;++i)
		for(int j=0;j<p;++j)
			if((i<=1||j!=st[i-1]-'a')&&(i<=2||j!=st[i-2]-'a')) {st[i]=j+'a';break;}
	printf("%s",st+1);
}

int main()
{
	n=read();p=read();scanf("%s",st+1);
	for(int i=n;i;--i)
		for(int j=st[i]-'a'+1;j<p;++j)
			if((i<=1||j!=st[i-1]-'a')&&(i<=2||j!=st[i-2]-'a')) {st[i]=j+'a';Build(i+1);return 0;}
	puts("NO");
	return 0;
}