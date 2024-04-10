#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
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

int a,b,c,d,e,f,ans;

int main()
{
	a=read();b=read();c=read();d=read();e=read();f=read();
	if(e>=f)
	{
		int k=min(a,d);
		ans+=k*e;
		a-=k,d-=k;
		if(d)
		{
			int g=min(d,min(b,c));
			ans+=g*f;
		}
	}
	else
	{
		int k=min(d,min(b,c));
		ans+=k*f;
		d-=k,b-=k,c-=k;
		if(d)
		{
			int g=min(d,a);
			ans+=g*e;
		}
	}
	printf("%d",ans);
	return 0;
}