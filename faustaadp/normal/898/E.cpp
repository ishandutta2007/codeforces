#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,m,k,i,ta,hz,hs;
vector<ll> v1,v2;
bool rmt(ll aa)
{
	ll he=sqrt(aa);
	he=he*he;
	if(aa==he)
		return 1;
	else
		return 0;
}
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		if(ta==0)
			v1.pb(2);
		else
		if(rmt(ta))
			v1.pb(1);
		else
		{
			hz=sqrt(ta);
			hz++;
			//v2.pb(hz-ta);
			v2.pb(min(ta-((hz-1)*(hz-1)),(hz*hz)-ta));
			//hz=hz*hz;
		}
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	if(v1.size()>n/2)
	{
		for(i=0;i<v1.size()-n/2;i++)
			hs+=v1[i];
	}
	else
	{
		for(i=0;i<v2.size()-n/2;i++)
			hs+=v2[i];
	}
	cout<<hs<<"\n";
}