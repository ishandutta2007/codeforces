#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,a[202020],nx[202020],tempe,tempe1,tempe2,has,jangan,te,j,i,ta;
ll kal(ll aa,ll bb)
{
	if(bb==0)
		return 0;
	else
	{
		ll tem=kal(aa,bb/2);
		tem+=tem;
		if(bb%2==1)
		{
			tem+=aa;
		}
		if(tem>1e18)
			jangan=1;
		return tem;
	}
}
int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i];
	tempe=n+1;
	for(i=n;i>=1;i--)
	{
		nx[i]=tempe;
		if(a[i]!=1)
			tempe=i;
	}
	for(i=1;i<=n;i++)
	{
		tempe1=a[i];
		tempe2=a[i];
		if(k==1)
			has++;
		jangan=0;
		te=0;
		j=i;
		while(1)
		{
		//	cin>>ta;
		//	cout<<tempe1<<" "<<tempe2<<"\n";
			if(jangan||te>40||j==n+1)	break;
			if(nx[j]!=j+1)
			{
				if((tempe1-tempe2*k>0)&&((tempe1-tempe2*k)%k==0))
				{
					ll hai=(tempe1-tempe2*k)/k,lee=1,ree=nx[j]-j-1;
					if(lee<=hai&&hai<=ree)
						has++;
				}
				te++;
				kal(tempe1,a[nx[j]]);
					if(jangan)	break;
				tempe1*=a[nx[j]];
				tempe2+=a[nx[j]];
				tempe2+=nx[j]-j-1;
				if(k*tempe2==tempe1)
					has++;
				j=nx[j];
			}
			else
			{
				te++;
				if(nx[j]==n+1)
					break;
				kal(tempe1,a[nx[j]]);
				if(jangan)	break;
				tempe1*=a[nx[j]];
				tempe2+=a[nx[j]];
				if(k*tempe2==tempe1)
					has++;
				j=nx[j];
			}
		}
	}
	cout<<has<<"\n";
}