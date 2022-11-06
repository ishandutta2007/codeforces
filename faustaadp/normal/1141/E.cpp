#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
ll H,n,a[202020],p[202020],jum,ma,i;
ll coba(ll aa)
{
	if(aa>=H/jum+1)return 1;
	ll tem=aa*jum;
	if(tem>=H)return 1;
	tem+=ma;
	if(tem>=H)return 1;
	else return 0;
}
void cek(ll aa)
{
	ll tem=n*aa,z=jum*aa,ii;
	if(z>=H)
	{
		cout<<tem<<"\n";
		exit(0);
	}
	for(ii=1;ii<=n;ii++)
	{
		z+=a[ii];
		tem++;
		if(z>=H)
		{
			cout<<tem<<"\n";
			exit(0);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>H>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)a[i]*=-1;
	for(i=1;i<=n;i++)p[i]=p[i-1]+a[i];
	for(i=1;i<=n;i++)ma=max(ma,p[i]);
	jum=p[n];
	if(ma>=H)
		cek(0);
	else
	if(jum<=0)
		cout<<-1<<"\n";
	else
	{
		ll L=0,R=1e18,C,X=-1;
		while(L<=R)
		{
			C=(L+R)/2;
			if(coba(C))
			{
				X=C;
				R=C-1;
			}
			else
				L=C+1;
		}
		//cout<<X<<"\n";
		if(X==-1)
		{
			cout<<-1<<"\n";
			return 0;
		}
		else
			cek(X);
	}
}