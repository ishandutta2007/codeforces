#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define LL long long

using namespace std;

LL read()
{
	LL ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

int n,a,b;

inline int get(int x,int y);

int main()
{
	n=read();
	while(n--)
	{
		a=read();b=read();
		printf("%d\n",get(a,b));
	}
	return 0;
}

inline int get(int x,int y)
{
	if(!y)
		return 0;
	return get(y,x%y)+x/y;
}