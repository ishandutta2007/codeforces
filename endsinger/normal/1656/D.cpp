#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long w,x=1;
		scanf("%lld",&w);
		while(w%2==0)
			w/=2,x*=2;
		if(w==1)
			puts("-1");
		else
			printf("%lld\n",min(x*2,w));
	}
	return 0;
}