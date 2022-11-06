#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,i,p[1010101],ta,taa,tbb,d[1010101],hs;
vector<ll> h;
ll fin(ll aa)
{
	if(p[aa]==aa)
		return aa;
	else
		return fin(p[aa]);
}
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		p[i]=i;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		taa=fin(ta);
		tbb=fin(i);
		p[ta]=taa;
		p[i]=tbb;
		if(taa!=tbb)
			p[taa]=tbb;
	}
	for(i=1;i<=n;i++)
	{
		taa=fin(i);
		p[i]=taa;
		d[taa]++;
	}
	for(i=1;i<=n;i++)
		if(d[i]>0)
			h.pb(d[i]);
	if(h.size()==1)
		hs=n*n;
	else
	{
		//cout<<h.size()<<"\n";
		sort(h.begin(),h.end());
		for(i=0;i<h.size()-2;i++)
		{
			hs+=h[i]*h[i];
		}
		//cout<<h[0]<<" "<<h[1]<<"\n";
		hs+=(h[h.size()-1]+h[h.size()-2])*(h[h.size()-1]+h[h.size()-2]);
	}
	cout<<hs<<"\n";
}