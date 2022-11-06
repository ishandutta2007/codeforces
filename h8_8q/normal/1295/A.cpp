#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

int t,n,a,b;

int main() 
{
	t=read();
	while(t--)
	{
		n=read();
		a=n/2;
		b=n%2;
		if(b)
			printf("7");
		else
			printf("1");
		for(int i=1;i<=a-1;++i)
			printf("1");
		printf("\n");
	}
	return 0;
}