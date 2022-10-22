#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL Solve(LL n,LL x)
{
	n=min(n,x);
	LL ans=0;
	for(LL l=1,r;l<=n;l=r+1)
	{
		r=min(x/(x/l),n);
		ans+=(r-l+1)*(x/l);
	}
	ans-=x;
	return ans;
}
int main(){
	LL T;
	cin>>T;
	while(T-->0)
	{
		LL x,y;
		cin>>x>>y;
		LL ans=0,i=1;
		for(;i<=y;++i)
		{
			if(i*i+i-1>x)	break;
			ans+=(i*i+i-1)/(i+1);
		}
		ans+=Solve(min(x,y+1),x)
		-Solve(i,x);
		cout<<ans<<endl;
//		cerr<<Solve(min(x,y+1),x)<<' '<<Solve(i,x)<<endl;
	}
	return 0;
}