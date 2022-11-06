#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll m,D,n,d[2020][2020][2][2],mo=1000000007;
string s[2];
ll cek(string aa)
{
	ll ii,H=0;
	for(ii=0;ii<n;ii++)
	{
		ll now=aa[ii]-'0';
		if(ii%2==0)
		{
			if(now==D)return 0;
		}
		else
		{
			if(now!=D)return 0;
		}
		H=(H*10+now)%m;
	}
	//cout<<H<<"\n";
	return (H==0);
}
ll depe(ll aa,ll bb,ll cc,ll dd)
{
	if(aa==n&&bb==0)return 1;
	if(aa==n)return 0;
	if(d[aa][bb][cc][dd]==-1)
	{
		ll ii,tem=0;
		if(dd==0)
		{
			if(aa%2==0)
			{
				ll st=0;
				for(ii=st;ii<=9;ii++)
				{
					if(ii==D)continue;
					tem=(tem+depe(aa+1,(bb*10+ii)%m,cc,0))%mo;
				}
			}
			else
			{
				for(ii=D;ii<=D;ii++)
				{
					tem=(tem+depe(aa+1,(bb*10+ii)%m,cc,0))%mo;
				}
			}
		}
		else
		{
			if(aa%2==0)
			{
				ll st=0;
				if(aa==0&&n>1)st=1;
				for(ii=st;ii<=(s[cc][aa]-'0');ii++)
				{
					if(ii==D)continue;
					if(ii<(s[cc][aa]-'0'))
						tem=(tem+depe(aa+1,(bb*10+ii)%m,cc,0))%mo;
					else
						tem=(tem+depe(aa+1,(bb*10+ii)%m,cc,1))%mo;
				}
			}
			else
			{
				for(ii=D;ii<=min(D,(ll)(s[cc][aa]-'0'));ii++)
				{
					if(ii<(s[cc][aa]-'0'))
						tem=(tem+depe(aa+1,(bb*10+ii)%m,cc,0))%mo;
					else
						tem=(tem+depe(aa+1,(bb*10+ii)%m,cc,1))%mo;
				}
			}
		}
		d[aa][bb][cc][dd]=tem;
	}
	return d[aa][bb][cc][dd];
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>m>>D;
	cin>>s[0]>>s[1];
	n=s[0].size();
	memset(d,-1,sizeof(d));
	//cout<<depe(0,0,1,1)<<" "<<depe(0,0,0,1)<<"\n";
	cout<<(depe(0,0,1,1)-depe(0,0,0,1)+cek(s[0])+mo)%mo<<"\n";
}