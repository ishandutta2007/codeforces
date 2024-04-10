#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
using namespace std;
ll n,x,i,ta,tb,a[101010],hs,c[101010],n1,n2,d[101010],hz,hn,hzz;
vector<ll> v;
vector<ll> k[10];
bool b[101010];
int main()
{
//	cout<<(2^3^4^8^13)<<"\n";
	cin>>n>>x;
	if(n==2&&x==0)
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	if(n==1)
	{
		cout<<x<<"\n";
		return 0;
	}
//	if(n%4!=1)
	{
		for(i=1;i<n-1;i++)
		{
		//	cout<<i<<" ";
			v.push_back(i);
			hz=hz^i;
		}
		hz=(x^hz);
		if(hz==0)
		{
			hz=hz^1^(n-1);
			v.push_back(n-1);
			v.erase(v.begin());
		}
		hzz=hz;
		for(i=0;i<=100;i++)
		{
			if(pow(2,i)>n-1&&(pow(2,i)>hz))
			{
				hn=pow(2,i);
				break;
			}
		}
		//cout<<hz<<" "<<hn<<"\n";
		while(1)
		{
			hz=hz+hn;
			if(hz>n-1)
			{
				for(i=0;i<v.size();i++)
				{
					cout<<v[i]<<" ";
					n1=n1^v[i];
				}
				cout<<hz<<" "<<(hn)<<"\n";
		//		cout<<(n1^hz^hn)<<"\n";
				return 0;
			}
			hn=hn+hn*2;
		}
	}
	
}