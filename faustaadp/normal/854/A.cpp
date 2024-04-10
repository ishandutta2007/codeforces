#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,ta,tb,tc,hz,tj,hs,nn;
ll fpb(ll aa,ll bb)
{
	if(bb==0)
		return aa;
	else
		return fpb(bb,aa%bb);
}
int main()
{
	cin>>n;
	nn=n/2+n%2;
	for(i=nn-1;i>=1;i--)
	{
		if(fpb(i,n-i)==1)
		{
			cout<<i<<" "<<n-i<<"\n";
			return 0;
		}
	}
}