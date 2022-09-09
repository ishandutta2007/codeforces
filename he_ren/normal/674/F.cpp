#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
typedef unsigned int uint;
typedef pair<int,int> pii;
const int MAXP = 130 + 5;

int gcd(int a,int b){ return b? gcd(b,a%b): a;}

inline uint pw(uint a,uint b)
{
	uint res = 1;
	while(b)
	{
		if(b&1) res*=a;
		a*=a; b>>=1;
	}
	return res;
}

inline uint get_c(int n,int m)
{
	if(n < 0 || m < 0 || n < m) return 0;
	if(m == 0 || m == n) return 1;
	
	static int t[MAXP];
	for(int i=1; i<=m; ++i) t[i] = n - i + 1;
	for(int i=1; i<=m; ++i)
	{
		int rem = i;
		for(int j=1; j<=m && rem > 1; ++j) if(t[j] > 1)
		{
			int k = gcd(rem, t[j]);
			rem /= k; t[j] /= k;
		}
	}
	
	uint res = 1;
	for(int i=1; i<=m; ++i) res *= (uint)t[i];
	return res;
}

uint c[MAXP];

int main(void)
{
	int n,p,q;
	scanf("%d%d%d",&n,&p,&q);
	p = min(p, n-1);
	
	for(int i=0; i<=p; ++i)
		c[i] = get_c(n, i);
	
	uint res = 0;
	for(int k=1; k<=q; ++k)
	{
		uint tmp = 0, pwk = 1;
		for(int i=0; i<=p; ++i)
		{
			tmp += c[i] * pwk;
			pwk *= (uint)k;
		}
		res ^= tmp * (uint)k;
	}
		
	printf("%u",res);
	return 0;
}