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

const int N=2e5+5;
LL n,ans,sum,now;

map<LL,LL> mp;

int main()
{
	n=read();
	mp[0]=1;
	for(int i=1;i<=n;++i)
	{
		sum+=read();
		now=max(now,mp[sum]);
		ans+=i-now;
		mp[sum]=i+1;
	}
	printf("%lld",ans);
	return 0;
}