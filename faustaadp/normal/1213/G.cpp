#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,p[202020],bes[202020],ta,tb,tc,x[202020];
pair<ll,pair<ll,ll> > A[202020];
ll car(ll aa)
{
	if(aa==p[aa])
		return aa;
	else 
		return p[aa]=car(p[aa]);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>n>>m;
	for(i=1;i<=n;i++)p[i]=i;
	for(i=1;i<=n;i++)bes[i]=1;
	for(i=1;i<n;i++)
	{
		cin>>ta>>tb>>tc;
		A[i]=mp(tc,mp(ta,tb));
	}
	sort(A+1,A+1+n);
	for(i=1;i<=n;i++)
	{
		x[i]=x[i-1]+bes[car(A[i].se.fi)]*bes[car(A[i].se.se)];
		//cout<<i<<" "<<x[i]<<"\n";
		bes[car(A[i].se.se)]+=bes[car(A[i].se.fi)];	
		p[car(A[i].se.fi)]=car(A[i].se.se);	
	}
	while(m--)
	{	
		cin>>ta;
		ll L=1,R=n,H=0,C;
		while(L<=R)
		{
			C=(L+R)/2;
			if(A[C].fi<=ta)
			{
				H=x[C];
				L=C+1;
			}
			else
				R=C-1;
		}
		cout<<H<<" ";
	}

}