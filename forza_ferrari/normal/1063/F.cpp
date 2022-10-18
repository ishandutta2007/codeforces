#include<iostream>
#include<cstdio>
#include<bitset>
#include<string>
#include<cmath>
using namespace std;
const int mod=7000007,base=37;
string s;
int n,maxn,res,h[500001];
bitset<mod+1> qwq;
bitset<500001> f[1001];
int main()
{
	cin>>n>>s;
	s=" "+s;
	for(register int i=1;i<=n;++i)
		h[i]=s[i]-='a'-1;
	maxn=sqrt(n<<1)+1;
	res=1;
	f[1].set();
	for(register int i=2;i<=maxn;++i)
	{
		res+=i;
		for(register int j=n-res+1;j>=1;--j)
		{
			if(f[i-1][j+i])
				qwq[h[j+i]]=1;
			if(qwq[h[j]]||qwq[h[j+1]])
				f[i][j]=1;
		}
		if(f[i].none())
		{
			printf("%d\n",i-1);
			return 0;
		}
		qwq.reset();
		for(register int j=1;j<=n-res+1;++j)
			h[j]=(h[j]*base%mod+s[j+i-1])%mod;
	}
	printf("%d\n",maxn);
	return 0;
}