#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2E5+10;
ll jc[15];
int main()
{
	jc[0]=1;
	for(int i=1;i<=14;++i)jc[i]=jc[i-1]*i;
	int n,m;
	cin>>n>>m;
	int z=max(n-13,1);
	ll ad=0,p=jc[n-z+1];
	while(m--)
	{
		int k;
		cin>>k;
		if(k==1)
		{
			int l,r;
			cin>>l>>r;
			if(r<z)cout<<(l+r)*1ll*(r-l+1)/2<<endl;
			else
			{
				ll ans=(z-1)*(r-max(l,z)+1),da=ad;
				if(l<z)ans+=(l+z-1)*1ll*(z-l)/2;
				bool b[15]={0};
				for(int i=z;i<=r;++i)
				{
					ll t=da/jc[n-i];
					int j=1;
					da-=t*jc[n-i];
					for(;t||b[j];++j)if(!b[j])--t;
					b[j]=1;
					if(i>=l)ans+=j;
				}
				cout<<ans<<endl;
			}
		}
		else 
		{
			int t;
			cin>>t;
			ad=(ad+t)%p;
		}
	}
	return 0;
}