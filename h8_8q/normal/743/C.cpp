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

int n,x,y,z; 

int main()
{
	n=read();
	if(n<=1)
	{
		printf("-1");
		return 0;
	}
	x=n,y=n+1,z=x*y;
	printf("%d %d %d",x,y,z);
	return 0;
}