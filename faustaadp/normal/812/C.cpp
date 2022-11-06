#include<bits/stdc++.h>
using namespace std;
long long n,s,i,a[1010101],ci[1010101],l,r,c,hs,hst,k;
bool rmt(long long ra)
{
//	cout<<ra<<endl;
	long long ii;
	for(ii=0;ii<n;ii++)
	{
		ci[ii]=(ii+1)*ra+a[ii];
	}
	sort(ci,ci+n);
	hst=0;
	for(ii=0;ii<ra;ii++)
	{
		hst=hst+ci[ii];
	}
//	cout<<hst<<endl;
	if(hst<=s)
		return 1;
	else
		return 0;
}
int main()
{
	cin>>n>>s;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	l=0;
	r=n;
	while(l<=r)
	{
		c=(l+r)/2;
		if(rmt(c))
		{
			l=c+1;
			k=c;
			hs=hst;
		}
		else
			r=c-1;
	}
	cout<<k<<" "<<hs<<endl;
}