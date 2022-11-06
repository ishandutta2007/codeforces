#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll a[99],x[99],has,y[99];
ll cek(ll aa)
{
	ll ii,jj;
	for(ii=0;ii<7;ii++)
	{
		ll K=aa/7,siza=aa%7;
		y[1]=K*3;
		y[2]=K*2;
		y[3]=K*2;
		for(jj=ii;jj<(ii+siza);jj++)
			y[x[jj%7]]++;
		if(y[1]<=a[1]&&y[2]<=a[2]&&y[3]<=a[3])return 1;
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	cin>>a[1]>>a[2]>>a[3];
	x[0]=1;
	x[1]=1;
	x[2]=2;
	x[3]=3;
	x[4]=1;
	x[5]=3;
	x[6]=2;
	ll L=0,R=1e18,C;
	while(L<=R)
	{
		C=(L+R)/2;
		if(cek(C))
		{
			has=C;
			L=C+1;
		}
		else
			R=C-1;
	}
	cout<<has<<"\n";
}