#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll l,r,x,y,i,X,Y,has,K;
ll fpb(ll aa,ll bb)
{
	if(bb==0)
		return aa;
	else
		return fpb(bb,aa%bb); 
}
ll kpk(ll aa,ll bb)
{
	return aa/fpb(aa,bb)*bb;
}
ll hah()
{
	ll ii,jj,H=0;
	for(ii=l;ii<=r;ii++)
		for(jj=l;jj<=r;jj++)
			if(fpb(ii,jj)==x&&kpk(ii,jj)==y)
				H++;
	return H;
}
int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	while(1)
	{
		has=0;
		cin>>l>>r>>x>>y;
//		cout<<hah()<<"\n";
		if(y%x!=0)
		{
			cout<<0<<"\n";
			return 0;
		}
		K=x;
		y=y/x;
		x=1;
		for(i=1;i<=sqrt(y);i++)
		{
			if(y%i==0)
			{
				X=y/i;
				Y=i;
				if(fpb(X,Y)==x&&(l<=(min(X,Y)*K))&&((max(X,Y)*K)<=r))
				{
					has+=2;
					if(X==Y)
						has--;
				}
			}
		}
		cout<<has<<"\n";
	}
}