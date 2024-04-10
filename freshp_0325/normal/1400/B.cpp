#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL T;
	cin>>T;
	while(T-->0)
	{
		LL p,f,cs,cw,s,w,ans=0;
		cin>>p>>f>>cs>>cw>>s>>w;
		if(s>w)	s^=w^=s^=w,cs^=cw^=cs^=cw;
		for(LL i=0;i<=cs && i*s<=p;++i)
		{
			LL u=i;
			LL v=min(cw,(p-(i*s))/w);
			LL a=min(cs-i,f/s);
			LL b=min(cw-v,(f-(s*a))/w);
			ans=max(ans,u+v+a+b);
		}
		cout<<ans<<endl;
	}
	return 0;
}