#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll n,l,r,c,hs;
bool rmt(ll aa)
{
	ll ii,jj,de;
	for(ii='a';ii<='z';ii++)
	{
		bool boo=1;
		de=0;
		for(jj=0;jj<aa;jj++)
			if(s[jj]==char(ii))
				de++;
		if(de==0)
			boo=0;
		for(jj=aa;jj<n;jj++)
		{
			if(s[jj]==char(ii))
				de++;
			if(s[jj-aa]==char(ii))
				de--;
			if(de==0)
				boo=0;
		}
		if(boo)
			return 1;
	}
	return 0;
}
int main()
{
	cin>>s;
	n=s.length();
	l=1;
	r=n;
	while(l<=r)
	{
		c=(l+r)/2;
		if(rmt(c))
		{
			hs=c;
			r=c-1;
		}
		else
			l=c+1;
	}
	cout<<hs<<"\n";
}