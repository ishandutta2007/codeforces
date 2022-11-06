#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,F[303030],has,mo=998244353,ta,tb,d1[303030],d2[303030];
pair<ll,ll> A[303030];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	F[0]=1;
	for(i=1;i<=n;i++)
		F[i]=(F[i-1]*i)%mo;
	ll k1=1;
	ll k2=1;
	ll k3=1;
	for(i=1;i<=n;i++)
	{
		cin>>ta>>tb;
		A[i]=mp(ta,tb);
		d1[ta]++;
		d2[tb]++;
	}
	sort(A+1,A+1+n);
	for(i=1;i<=n;i++)
	{
		k1=(k1*F[d1[i]])%mo;
		k2=(k2*F[d2[i]])%mo;
	}
	for(i=1;i<n;i++)
		if(A[i].se>A[i+1].se)
			k3=0;
	if(k3==1)
	{
		ll tem=0;
		for(i=1;i<=n;i++)
		{
			tem++;
			if((i==n)||(A[i]!=A[i+1]))
			{
				k3=(k3*F[tem])%mo;
				tem=0;		
			}
		}
	}
	//cout<<k1<<" "<<k2<<" "<<k3<<"\n";
	k1=(k1+k2)%mo;
	k1=(k1+mo-k3)%mo;
	has=(F[n]-k1+mo)%mo;
	cout<<has<<"\n";
}