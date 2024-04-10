#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,A,B,i,a[202020],b[202020],hv,sv,c[202020],p[202020],du,j,s1,s2,hz,has;
vector<pair<ll,ll> > v;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>A>>B;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if(a[i]>=b[i])
			v.pb(mp(a[i]-b[i],i));
		hv+=b[i];
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	sv=v.size();
	for(i=0;i<sv;i++)
	{
		c[v[i].se]=i+1;
		p[i+1]=p[i]+v[i].fi;
	}
	has=hv;
	has=max(has,hv+p[min(sv,B)]);
	if(B==0)
	{
		cout<<has<<"\n";
		return 0;
	}
	for(i=1;i<=A;i++)
	{
		du=1;
		for(j=1;j<=i;j++)
			du*=2;
		s1=i;
		s2=min(sv,B-1);
		for(j=1;j<=n;j++)
		{
			hz=hv;
			if(c[j]<=s2&&c[j]!=0)
			{
				//cout<<"A";
				hz-=v[c[j]-1].fi;
				if(s2+1<=sv)
					hz+=v[s2].fi;
			}
			hz+=p[s2];
			hz+=du*a[j];
			hz-=b[j];
			has=max(has,hz);
		}
	}
//	cout<<hv<<" "<<p[sv]<<"\n";
	cout<<has<<"\n";
}