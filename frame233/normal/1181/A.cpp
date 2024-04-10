//Author -- Frame

#include<bits/stdc++.h>


typedef long long ll;
ll a,b,c;
int main()
{
	scanf("%lld %lld %lld",&a,&b,&c);
	ll t1 =a%c,t2=b%c,ans=0;
	if(!t2) ans=0;
	else 
	{
		if(t1+t2<c) ans=0;
		else ans=std::min(c-t1,c-t2);
	}
	std::cout<<(a+b)/c<<' '<<ans<<std::endl;
	return 0;
}