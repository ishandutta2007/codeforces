#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,a,b,bo,i,A,B,hv,d[1010101];
void ges(ll aa,ll bb)
{
	//cout<<aa<<" "<<bb<<"\n";
	ll ii,te=aa-1;
	for(ii=aa+1;ii<=bb;ii++)
	{
		te++;
		d[ii]=te;
	}
	te++;
	d[aa]=te;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>a>>b;
	bo=0;
	for(i=0;i<=n;i+=a)
	{
		if((n-i)%b==0)
		{
			A=i/a;
			B=(n-i)/b;
			bo=1;
		}
	}
	if(bo==0)
	{
		cout<<-1<<"\n";
		return 0;
	}
	hv=1;
	for(i=1;i<=A;i++)
	{
		ges(hv,hv+a-1);
		hv+=a;
	}
	for(i=1;i<=B;i++)
	{
		ges(hv,hv+b-1);
		hv+=b;
	}
	for(i=1;i<n;i++)
		cout<<d[i]<<" ";
	cout<<d[n]<<"\n";
}