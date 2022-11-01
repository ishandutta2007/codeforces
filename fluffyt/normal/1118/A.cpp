#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int q,c1,c2;
ll n;
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%lld%d%d",&n,&c1,&c2);
		if(c1*2<c2) printf("%lld\n",n*c1);
		else
		{
			ll ans=(n/2)*c2;
			if(n&1) ans+=c1;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
4 233
2 3 5*/