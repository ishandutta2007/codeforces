#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,x,y;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>x>>y;ll ans=0;int pos=0;for(int i=1;i<=y&&i-1<=x/(i+1);i++)ans+=i-1,pos=i;
		for(int l=pos+2,r;l<=min(x,y+1);l=r+1)r=min(y+1,x/(x/l)),ans+=1ll*(r-l+1)*(x/l);cout<<ans<<endl;
	}
	return 0;
}