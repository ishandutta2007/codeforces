#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXD = 60 + 5;
const int mod = 1e9 + 7;

inline ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

int f[MAXD];

int main(void)
{
	int d;
	scanf("%d",&d);
	
	f[1] = 1;
	for(int i=2; i<=d; ++i)
		f[i] = 4ll * f[i-1] * f[i-1] %mod;
	
	int ans = f[d] * pw(2, (1ll<<d) - 1) %mod * 3 %mod;
	printf("%d",ans);
	return 0;
}