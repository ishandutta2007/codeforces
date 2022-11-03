#include<iostream>
using namespace std;
long long k,p,t,pw,ans,s;
int main()
{
	cin>>k>>p;
	for (long long i=1;i<=k;i++)
	{
		pw=1;
		t=i;s=0;
		while(t)
		{
			s=s*10+(t%10);
			t/=10;
			pw*=10;
		}
		ans=(ans+i*pw+s)%p;
	}
	cout<<ans<<endl;
	return 0;
}