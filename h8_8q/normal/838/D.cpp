#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read()
{
	int res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){res=res*10+c-'0';c=getchar();}
	return res*f;
}

const int mod=1e9+7;
int n,m,ans;

inline int q_pow(int a,int b);

signed main()
{
	n=read();m=read();
	printf("%lld\n",q_pow(2,m)*q_pow(n+1,m-1)%mod*(n-m+1)%mod);
	return 0;
}

inline int q_pow(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*c%mod;
		a=a*a%mod;b>>=1;
	}
	return c;
}