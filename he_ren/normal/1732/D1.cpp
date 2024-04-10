#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int main(void)
{
	set<ll> bak;
	map<ll,ll> ans;
	
	bak.emplace(0);
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		static char op[10];
		ll x;
		scanf("%s%lld",op,&x);
		
		if(*op == '+')
			bak.emplace(x);
		else
		{
			ll res = ans[x];
			while(bak.count(res))
				res += x;
			ans[x] = res;
			printf("%lld\n",res);
		}
	}
	return 0;
}