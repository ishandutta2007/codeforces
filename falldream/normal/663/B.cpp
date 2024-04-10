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
int n;
char st[MN+5];

int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",st+1);
		int x=0,len=0;
		for(int j=5;st[j];++j) x=x*10+st[j]-'0',++len;
		int s=1990+x%10;if(s==1999) s-=10;
		for(int i=2,p=100;i<=len;++i,p*=10) do s+=p/10; while(s%p!=x%p);
		printf("%d\n",s); 
	}
	return 0;
}