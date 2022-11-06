#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,L,R,C,has;
ll cek(ll aa)
{
	ll h1=0,h2=0,N=n;
	while(1)
	{
		if(N==0)
			break;
		ll tem=min(N,aa);
		N-=tem;
		h1+=tem;
		tem=N/10;
		N-=tem;
		h2+=tem;
	}
	return(h1>=h2);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	L=1;
	R=1000000000000000000;
	while(L<=R)
	{
		C=(L+R)/2;
		if(cek(C))
		{
			has=C;
			R=C-1;
		}
		else
			L=C+1;
	}
	cout<<has<<"\n";
}