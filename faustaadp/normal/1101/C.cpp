#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,ta,tb,has,t,X[202020],Y[202020],a[202020],b[202020],x[202020];
pair<pair<ll,ll>,ll> A[202020],B[202020];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			x[i]=2;
			cin>>a[i]>>b[i];
			A[i]=mp(mp(a[i],b[i]),i);
		}
		has=-1;
		ll ma=-1e18;
		sort(A+1,A+1+n);
		for(i=1;i<=n;i++)
		{
			x[A[i].se]=1;
			ma=max(ma,A[i].fi.se);
			if(i<n&&A[i+1].fi.fi>ma)
			{
				has=1;
				break;
			}
		}
		if(has==-1)cout<<-1<<"\n";
		else
		{
			for(i=1;i<=n;i++)
				if(i<n)cout<<x[i]<<" ";
				else cout<<x[i]<<"\n";
		}
	}
}