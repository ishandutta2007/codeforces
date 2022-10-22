#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[100005],b[100005],c[100005];
int main(){
	LL T;
	cin>>T;
	while(T-->0)
	{
		cin>>n;
		for(LL i=1;i<=n;++i)	cin>>c[i];
		for(LL i=1;i<=n;++i)	cin>>a[i];
		for(LL i=1;i<=n;++i)	cin>>b[i];
		for(LL i=1;i<=n;++i)	if(a[i]>b[i])	a[i]^=b[i]^=a[i]^=b[i];
		LL ans=0,las=0;
		for(LL i=2;i<=n;++i)
		{
			if(a[i]==b[i])	las=2;
			else
			{
				if(i!=2 && las-1+c[i-1]>(b[i]-a[i])*2)	las+=a[i]-1+c[i-1]-b[i]+2;
				else	las=b[i]-a[i]+2;
			}
			ans=max(ans,c[i]-1+las);
		}
		cout<<ans<<endl;
	}
	return 0;
}