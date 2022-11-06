#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
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

const int N=1e5+5;
LL t,n,all,now1,now2,mmax;

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		all=0,now1=0,now2=0;
		mmax=-0x7fffffff;
		for(int i=1;i<=n;++i)
		{
			LL x=read();
			all+=x;
			if(i!=n)
				now1=max(0ll,now1+x);
			if(i!=1)
				now2=max(0ll,now2+x);
			mmax=max(mmax,x);
			mmax=max(mmax,max(now1,now2));
		}
		if(all>mmax)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}