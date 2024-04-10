#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,ta,d[202020],has,BIT[202020];
void upd(ll aa)
{
	ll ii;
	for(ii=aa;ii<=n;ii+=(ii&(-ii)))
		BIT[ii]++;
}
ll que(ll aa)
{
	ll ii,H=0;
	for(ii=aa;ii>=1;ii-=(ii&(-ii)))
		H+=BIT[ii];
	return H;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>ta;
		d[i]+=ta-que(ta+1);
		//cout<<i<<" "<<(ta-que(ta+1))<<"\n";
		upd(ta+1);
	}
	memset(BIT,0,sizeof(BIT));
	for(i=0;i<n;i++)
	{
		cin>>ta;
		d[i]+=ta-que(ta+1);
		//cout<<i<<" "<<(ta-que(ta+1))<<"\n";
		upd(ta+1);
	}
	for(i=n-1;i>=0;i--)
	{
		ll x=n-i;
	//	cout<<i<<" "<<x<<"\n";
		if(d[i]>=x)
		{
			if(i>0)
				d[i-1]+=d[i]/x;
			d[i]%=x;
		}
	}
	memset(BIT,0,sizeof(BIT));
	//for(i=0;i<n;i++)cout<<i<<" "<<d[i]<<"_\n";
	for(i=0;i<n;i++)
	{
		ll L=0,R=n-1,C,H;
		// for(ll j=0;j<n;j++)
		// 	cout<<j-que(j+1)<<" ";
		// cout<<"\n";
		while(L<=R)
		{
			C=(L+R)/2;
			if((C-que(C+1))<=d[i])
			{
				H=C;
				L=C+1;
			}
			else
				R=C-1;
		}
	//	cout<<H<<" "<<d[i]<<"\n";
		if((i+1)<n)cout<<H<<" ";
		else cout<<H<<"\n";
		upd(H+2);
	}
}