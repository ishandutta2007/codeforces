#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
ll n,i,a[202020],hz,te,x[202020],has;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			hz++;
		else
		{
			if(hz>0)
			{
				te++;
				x[te]=hz;
			}
			hz=0;
		}
	}
	if(hz>0)
	{
		te++;
		x[te]=hz;
	}
	for(i=1;i<=te;i++)
		has=max(has,x[i]);
	if(a[1]==1&&a[n]==1)has=max(has,x[1]+x[te]);
	cout<<has<<"\n";
}