#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL Calc(LL x,LL y)
{
	LL p=1,ans=0;
	while(y)	y/=x,++ans;
	return ans;
}
int main(){
	LL T;
	cin>>T;
	while(T-->0)
	{
		LL a,b;
		cin>>a>>b;
		if(a<b)
		{
			cout<<1<<endl;
			continue;
		}
		LL ans=2147483647;
		for(LL i=max(b,2ll);i<=min(b+500000,a+1);++i)
		{
			ans=min(ans,i-b+Calc(i,a));
		}
//		if(b==1)	++ans;
		cout<<ans<<endl;
	}
	return 0;
}