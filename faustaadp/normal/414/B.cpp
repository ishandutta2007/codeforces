#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,l,i,hs,d[2020][2020];
ll rmt(ll ir,ll rl)
{
	if(rl==1)
		return 1;
	else
	{
		ll ii,hz=0;
		if(d[ir][rl]==0)
		{
			for(ii=ir;ii<=n;ii=ii+ir)
			{
				hz=hz+rmt(ii,rl-1);
			}
			if(hz>=1000000007)
				hz=hz%1000000007;
			d[ir][rl]=hz;
		}
		return d[ir][rl];
	}
}
int main()
{
	cin>>n>>l;
//	const clock_t begin_time = clock();
	for(i=1;i<=n;i++)
	{
		hs=hs+rmt(i,l);
		hs=hs%1000000007;
	}
	cout<<hs<<endl;
//	std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
}