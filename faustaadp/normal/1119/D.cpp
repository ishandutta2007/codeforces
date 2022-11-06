#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,i,a[101010],awal,X,h[101010],he[101010],has,q,ta,tb;
vector<ll> z;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
		if(i==n||a[i]!=a[i+1])
			awal++;
	X=1;
	for(i=1;i<n;i++)
		if((a[i+1]-a[i])>1)
		{
			X++;
			z.pb(a[i+1]-a[i]-1);
		}
	sort(z.begin(),z.end());
	ll sz=z.size();
//	cout<<awal<<" "<<X<<"\n";
	h[0]=awal;
	for(i=0;i<sz;i++)
	{
		if(i==0||z[i]!=z[i-1])
		{
			ll sel=z[i];
			if(i>0)sel=z[i]-z[i-1];
			h[i+1]=h[i]+X*sel;
			he[i+1]=X;
		}
		else
		{
			he[i+1]=he[i];
			h[i+1]=h[i];
		}
		X--;
	}
	he[sz+1]=1;

	//for(i=0;i<=sz+1;i++)
	//	cout<<i<<" "<<h[i]<<" "<<he[i]<<"\n";
	cin>>q;
	while(q--)
	{
		cin>>ta>>tb;
		ta=tb-ta;
		ll L=0,R=sz-1,C,y=0,woi=0;
		while(L<=R)
		{
			C=(L+R)/2;
			if(z[C]<=ta)
			{
				woi=z[C];
				y=C+1;
				L=C+1;
			}
			else
				R=C-1;
		}
		//cout<<y<<" "<<h[y]<<" "<<he[y+1]<<"\n";
		has=h[y]+(ta-woi)*he[y+1];
		cout<<has;
		if(q)cout<<" ";
		else cout<<"\n";
	}
}