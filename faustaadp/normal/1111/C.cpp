#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,A,B,a[101010],i;
ll banyak(ll aa,ll bb)
{
	ll L=1,R=k,C,awal=k+1;
	while(L<=R)
	{
		C=(L+R)/2;
		if(a[C]>=aa)
		{
			awal=C;
			R=C-1;
		}
		else 
			L=C+1;
	}
	ll akhir=0;
	L=1;R=k;
	while(L<=R)
	{
		C=(L+R)/2;
		if(a[C]<=bb)
		{
			akhir=C;
			L=C+1;
		}
		else 
			R=C-1;
	}
	//cout<<aa<<" "<<bb<<" "<<akhir-awal+1<<" A\n";
	return (akhir-awal+1);
}
ll hai(ll aa,ll bb)
{
//	cout<<aa<<" "<<bb<<"\n";
	if(banyak(aa,bb)==0)return A;
	if(aa==bb)
		return B*banyak(aa,bb);
	else
	{
		ll ce=(aa+bb)/2;
		ll hz=banyak(aa,bb)*B*(bb-aa+1);
		ll X=min(hz,(hai(aa,ce)+hai(ce+1,bb)));
		//cout<<aa<<" "<<bb<<" "<<X<<"\n";
		return X;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k>>A>>B;
	for(i=1;i<=k;i++)cin>>a[i];
	sort(a+1,a+1+k);
	cout<<hai(1,(1<<n))<<"\n";
}