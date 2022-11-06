#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,ta,tb,tc,hz,tj,hs[10101010],nn,k,j,tt;
vector<pair<ll,ll> > a;
vector<ll> c;
bool b[101010101];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		c.push_back(k+i+1);
		cin>>ta;
		a.push_back(make_pair(ta,i));
	}
	sort(a.begin(),a.end(),greater<pair<ll,ll> >());
	tt=k+1;
	for(i=0;i<n;i++)
	{
		if(a[i].second+1>tt)
		{
			b[a[i].second+1]=1;
			hs[a[i].second]=a[i].second+1;
		}
		else
		{
			hz=hz+(tt-a[i].second-1)*a[i].first;
			hs[a[i].second]=tt;
			for(j=tt+1;j<=n+k;j++)
			{
				if(b[j]==0)
				{
					tt=j;
					break;
				}
			}	
		}
	//	cout<<a[i].second<<"\n";
		/*tj=lower_bound(c.begin(),c.end(),max(a[i].second+1,k+1))-c.begin();
	//	cout<<tj<<"\n";
	//	for(j=0;j<c.size();j++)
	//		cout<<c[j]<<" ";
	//	cout<<"\n";
		hz=hz+(c[tj]-a[i].second-1)*a[i].first;
		hs[a[i].second]=c[tj];
		c.erase(c.begin()+tj);*/
		/*for(j=max(a[i].second+1,k+1);j<=k+n;j++)
		{
			if(b[j]==0)
			{
				b[j]=1;
				hs[a[i].second]=j;
				hz=hz+(j-a[i].second-1)*a[i].first;
				break;
			}
		}*/
	}
	cout<<hz<<"\n";
	for(i=0;i<n-1;i++)
		cout<<hs[i]<<" ";
	cout<<hs[n-1]<<"\n";
}